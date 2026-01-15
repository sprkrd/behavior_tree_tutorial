#include <behaviortree_cpp/bt_factory.h>
#include "behaviortree_cpp/loggers/groot2_publisher.h"
#include "behaviortree_cpp/loggers/bt_file_logger_v2.h"

#include <iostream>
#include <string>
#include <thread>

std::string input;

class AskUserName : public BT::StatefulActionNode
{
    public:
        static BT::PortsList providedPorts()
        {
            return { BT::OutputPort<std::string>("userName") };
        }
        
        AskUserName(const std::string& nodeName, const BT::NodeConfig& config)
            : BT::StatefulActionNode(nodeName, config)
        {
        }

        BT::NodeStatus onStart() override
        {
            input.clear();
            std::cout << "What's your name? " << std::endl;
            return BT::NodeStatus::RUNNING;
        }

        BT::NodeStatus onRunning() override
        {
            if (!input.empty())
            {
                setOutput("userName", input);
                input.clear();
                return BT::NodeStatus::SUCCESS;
            }
            return BT::NodeStatus::RUNNING;
        }

        void onHalted() override
        {
        }
};

class GreetUser : public BT::SyncActionNode
{
    public:
        static BT::PortsList providedPorts()
        {
            return { BT::InputPort<std::string>("userName") };
        }

        GreetUser(const std::string& nodeName, const BT::NodeConfig& config)
            : BT::SyncActionNode(nodeName, config)
        {
        }

        BT::NodeStatus tick() override
        {
            std::cout << "Hello " << getInput<std::string>("userName").value()
                      << "!" << std::endl;
            return BT::NodeStatus::SUCCESS;
        }
};

const char* xmlTree = R"(
<root BTCPP_format="4">
    <BehaviorTree ID="Main">
        <Sequence name="root_sequence">
            <AskUserName    userName="{userName}"/>
            <GreetUser  userName="{userName}"/>
        </Sequence>
    </BehaviorTree>
</root>
)";

int main()
{
    BT::BehaviorTreeFactory factory;

    factory.registerNodeType<AskUserName>("AskUserName");
    factory.registerNodeType<GreetUser>("GreetUser");

    auto tree = factory.createTreeFromText(xmlTree);
    BT::Groot2Publisher groot2Publisher(tree, 1667);
    BT::FileLogger2 logger2(tree, "instantiate_simple_tree.btlog");

    std::thread treeRunner([&]
    {
        tree.tickWhileRunning(std::chrono::milliseconds(100));
    });

    std::cin >> input;
    treeRunner.join();
    std::cout << "Tree finished execution" << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

