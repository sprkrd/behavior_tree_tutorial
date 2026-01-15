#include <behaviortree_cpp/bt_factory.h>
#include "behaviortree_cpp/loggers/groot2_publisher.h"
#include "behaviortree_cpp/loggers/bt_file_logger_v2.h"

#include <crow.h>

#include <iostream>
#include <string>
#include <thread>
#include <functional>

//std::string input;

class Wait : public BT::StatefulActionNode
{
    public: 
        Wait(const std::string& nodeName, const BT::NodeConfig& config, int msec)
            : BT::StatefulActionNode(nodeName, config)
            , _msec(msec)
        {
        }

        BT::NodeStatus onStart() override
        {
            _deadline = std::chrono::steady_clock::now() + _msec;
            return BT::NodeStatus::RUNNING;
        }

        BT::NodeStatus onRunning() override
        {
            if (std::chrono::steady_clock::now() < _deadline)
            {
                return BT::NodeStatus::RUNNING;
            }
            return BT::NodeStatus::SUCCESS;
        }

        void onHalted() override
        {
        }

    private:

        std::chrono::milliseconds _msec;
        std::chrono::steady_clock::time_point _deadline;
};

class Scoop : public Wait
{
    public:
        static BT::PortsList providedPorts()
        {
            return { BT::InputPort<int>("plate") };
        }

        Scoop(const std::string& nodeName, const BT::NodeConfig& config, int msec)
            : Wait(nodeName, config, msec)
        {
        }
};

class Server
{
    public:

        explicit Server(const std::string& executable)
        {
            Init(executable);
        }

        void Run()
        {
            _app.port(8081).run();
        }

        bool Get(const std::string& condition) const
        {
            std::lock_guard lock(_mtx);
            auto it = _conditions.find(condition);
            if (it == _conditions.end()) return false;
            return it->second;
        }

        void SendMessage(const std::string& message)
        {
            std::lock_guard lock(_wsMtx);
            for (auto* user : _users)
            {
                user->send_text(message);
            }
        }

    private:

        void Init(const std::string& executable)
        {
            using namespace std::placeholders;
            auto binPath = std::filesystem::absolute(executable).parent_path();
            auto indexHtmlPath = std::filesystem::canonical(
                    binPath / ".." / "nyam_full_example" / "index.html");
            _indexHtmlPath = indexHtmlPath.string();

            CROW_ROUTE(_app, "/")(std::bind(&Server::OnLoad, this, _1));

            CROW_ROUTE(_app, "/set")
                .methods("POST"_method)(std::bind(&Server::OnSet, this, _1));

            CROW_ROUTE(_app, "/get")(std::bind(&Server::OnGet, this, _1));

            CROW_WEBSOCKET_ROUTE(_app, "/status")
                .onopen(std::bind(&Server::WsOnConnect, this, _1))
                .onclose(std::bind(&Server::WsOnClose, this, _1, _2, _3));

            _conditions["DoesUserLookAtRobot"] = false;
            _conditions["IsMouthOpen"] = false;
            _conditions["UserHasMovedForwardAndBack"] = false;
        }

        void WsOnConnect(crow::websocket::connection& conn)
        {
            std::lock_guard lock(_wsMtx);
            CROW_LOG_INFO << "New websocket connection from " << conn.get_remote_ip();
            _users.push_back(&conn);
        }

        void WsOnClose(crow::websocket::connection& conn, const std::string&, uint16_t)
        {
            std::lock_guard lock(_wsMtx);
            CROW_LOG_INFO << "Bye " << conn.get_remote_ip();
            auto it = std::find(_users.begin(), _users.end(), &conn);
            if (it != _users.end())
            {
                _users.erase(it);
            }
        }

        crow::response OnLoad(const crow::request& req)
        {
            std::ostringstream oss;
            std::ifstream in(_indexHtmlPath);
            oss << in.rdbuf();
            return oss.str();
        }

        crow::response OnSet(const crow::request& req)
        {
            std::lock_guard lock(_mtx);
            auto data = crow::json::load(req.body);
            if (!data)
            {
                return crow::response(400);
            }
            for (const auto& kv : data)
            {
                const auto& key = kv.key();
                auto it = _conditions.find(key);
                if (it==_conditions.end())
                {
                    return crow::response(400, "Error key/value");
                }
                bool value = kv.b();
                it->second = value;
            }
            crow::response res(201);
            res.set_header("Content-Type", "application/json");
            res.write("{\"status\": \"ok\"}");
            return res;
        }

        crow::response OnGet(const crow::request& req)
        {
            std::lock_guard lock(_mtx);
            crow::json::wvalue body;
            for (const auto&[condition,value] : _conditions)
            {
                body[condition] = value;
            }
            crow::response res(201);
            res.set_header("Content-Type", "application/json");
            res.write(body.dump());
            return res;
        }

        crow::SimpleApp _app;
        std::string _indexHtmlPath;
        std::unordered_map<std::string,bool> _conditions;
        std::vector<crow::websocket::connection*> _users;
        mutable std::mutex _mtx;
        mutable std::mutex _wsMtx;
};

BT::NodeStatus BoolToStatus(bool b)
{
    return b? BT::NodeStatus::SUCCESS : BT::NodeStatus::FAILURE;
}

class TreeRunner
{
    public:

        TreeRunner(const std::string& executable, Server& server)
            : _server(server)
        {
            Init(executable);
            _worker = std::thread(&TreeRunner::Run, this);
        }

        void Run()
        {
            BT::Groot2Publisher groot2(_tree, 1667);
            StatusLogger statusLogger(_server, _tree);
            auto _status = _tree.tickExactlyOnce();
            while (_status == BT::NodeStatus::RUNNING)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                _status = _tree.tickExactlyOnce();
            }
        }

    private:

        class StatusLogger : public BT::StatusChangeLogger
        {
            public:
                StatusLogger(Server& server, const BT::Tree& tree)
                    : BT::StatusChangeLogger(tree.rootNode())
                    , _server(server) {}

            private:

                void callback(BT::Duration timestamp, const BT::TreeNode& node,
                        BT::NodeStatus prevStatus, BT::NodeStatus status) override
                {
                    std::ostringstream oss;
                    oss << node.name() << " " << prevStatus << "->" << status << '\n';
                    _server.SendMessage(oss.str());
                }

                void flush() override {}

                Server& _server;
        };

        void Init(const std::string& executable)
        {
            auto binPath = std::filesystem::absolute(executable).parent_path();
            auto xmlPath = std::filesystem::canonical(
                    binPath / ".." / "nyam_project.xml");

            // register actions
            _factory.registerNodeType<Wait>("ApproachMouth", {}, 2000);
            _factory.registerNodeType<Wait>("CatchAttention", {}, 1000);
            _factory.registerNodeType<Wait>("Retreat", {}, 2000);
            _factory.registerNodeType<Scoop>("Scoop", 2000);

            // register conditions
            _factory.registerSimpleCondition("DoesUserLookAtRobot",
                    [&](BT::TreeNode&) { return BoolToStatus(_server.Get("DoesUserLookAtRobot")); });
            _factory.registerSimpleCondition("IsMouthOpen",
                    [&](BT::TreeNode&) { return BoolToStatus(_server.Get("IsMouthOpen")); });
            _factory.registerSimpleCondition("UserHasMovedForwardAndBack",
                    [&](BT::TreeNode&) { return BoolToStatus(_server.Get("UserHasMovedForwardAndBack")); });
            _tree = _factory.createTreeFromFile(xmlPath);
        }

        BT::BehaviorTreeFactory _factory;
        Server& _server;
        BT::Tree _tree;
        std::thread _worker;
};

int main(int argc, char* argv[])
{
    Server server(argv[0]);
    TreeRunner treeRunner(argv[0], server);
    server.Run();
}

