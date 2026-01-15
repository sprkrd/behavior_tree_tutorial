# Behavior Trees for Robotics 

🦆 *Alejandro Suárez Hernández* 🦆 

(available at https://sprkrd.github.io/behavior_tree_tutorial/slides)

>>>

## ✨ 1. Introduction to BTs ✨ 

vvv

### 1.1. Motivation

Wouldn't you like...

* ... a researcher-friendly programming framework? <!-- .element: class="fragment" -->
* ... fast preparation of demos?                   <!-- .element: class="fragment" -->
* ... easy behavior composition?                   <!-- .element: class="fragment" -->
* ... robust and responsive execution?             <!-- .element: class="fragment" -->

vvv

<!-- .slide: class="gridNx2" -->
### 1.2. What are our options? <!-- .element: class="header" -->


![Code](img/options_frame1.png) <!-- .element: class="fragment" height="400" -->

![Flowchart](img/options_frame2.png) <!-- .element: class="fragment" height="400" -->

![Finite state machine](img/options_frame3.png) <!-- .element: class="fragment" height="300" -->

![✨ Behavior tree ✨](img/options_frame4.png) <!-- .element: class="fragment" height="300" -->

vvv

### 1.3. NYAM as a running example

![NYAM in "Comando Actualidad", April 2024](img/NYAM_comando_actualidad.png) <!-- .element: height="500" -->

vvv

<iframe width="590" height="1048" src="https://www.youtube.com/embed/l9opW5vjPng?autoplay=1&mute=1" title="LabORA - &#39;NYAM&#39; Experiments - Part 1" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

vvv

<!-- .slide: class="gridNx2" -->
### 1.4. What are Behavior Trees? <!-- .element: class="header" -->

![Simple behavior tree](img/basic_behavior_tree.png)

* Graphical programming <!-- .element: class="fragment" -->
* Execution model       <!-- .element: class="fragment" -->
* Action-driven         <!-- .element: class="fragment" -->
* High level            <!-- .element: class="fragment" -->
* Hierarchical          <!-- .element: class="fragment" -->
* Modular               <!-- .element: class="fragment" -->
* Reactive              <!-- .element: class="fragment" -->

>>>

## 📖 2. Theory 📖

vvv

### 2.1. How do we read them?

<div class="r-stack">
<img src="img/basic_behavior_tree.png" class="fragment fade-out" data-fragment-index="0">
<img src="img/how_to_read_bts_frame1.png" class="fragment fade-in-then-out" data-fragment-index="0">
<img src="img/how_to_read_bts_frame2.png" class="fragment fade-in-then-out">
<img src="img/how_to_read_bts_frame3.png" class="fragment fade-in-then-out">
<img src="img/how_to_read_bts_frame4.png" class="fragment fade-in-then-out">
<img src="img/how_to_read_bts_frame5.png" class="fragment">
</div>

vvv

### 2.2. Execution model

<div class="r-stack">
<img src="img/basic_behavior_tree.png" class="fragment fade-out" data-fragment-index="0">
<img src="img/execution_model_frame1.png" class="fragment fade-in-then-out" data-fragment-index="0">
<img src="img/execution_model_frame2.png" class="fragment fade-in-then-out">
<img src="img/execution_model_frame3.png" class="fragment fade-in-then-out">
<img src="img/execution_model_frame4.png" class="fragment fade-in-then-out">
<img src="img/execution_model_frame5.png" class="fragment fade-in-then-out">
<img src="img/execution_model_frame6.png" class="fragment fade-in-then-out">
<img src="img/execution_model_frame7.png" class="fragment fade-in-then-out">
<img src="img/execution_model_frame8.png" class="fragment fade-in-then-out">
<img src="img/execution_model_frame9.png" class="fragment fade-in-then-out">
<img src="img/execution_model_frame10.png" class="fragment fade-in-then-out">
<img src="img/execution_model_frame11.png" class="fragment fade-in-then-out">
<img src="img/execution_model_frame12.png" class="fragment">
</div>

vvv

<!-- .slide: class="gridNx2" -->
### 2.3. Types of node <!-- .element: class="header" -->

![Action nodes](img/action_nodes.png)       <!-- .element: class="fragment" height="300" -->

![Condition nodes](img/condition_nodes.png) <!-- .element: class="fragment" height="300" -->

![Control nodes](img/control_nodes.png)     <!-- .element: class="fragment" height="300" -->

![Decorator nodes](img/decorator_nodes.png) <!-- .element: class="fragment" height="300" -->

vvv

<!-- .slide: class="gridNx3" -->
### 2.4. More on control nodes <!-- .element: class="header" -->

![Simple sequence to feed patient](img/Sequence.png)                          <!-- .element: class="fragment" -->

![Fallback to scoop from non-empty bowl](img/Fallback.png)                  <!-- .element: class="fragment" -->

![Composition of control nodes](img/combination_of_fallback_and_sequence.png) <!-- .element: class="fragment" -->

vvv

### 2.5. Subtrees

<div class="r-stack">
<img src="img/subtree_example_frame1.png" class="fragment fade-out" data-fragment-index="0">
<img src="img/subtree_example_frame2.png" class="fragment fade-in-then-out" data-fragment-index="0">
<img src="img/subtree_example_frame3.png" class="fragment">
</div>

vvv

<!-- .slide: class="gridNx2" -->
### 2.6. Reactive version of control nodes <!-- .element: class="header" -->

![Reactive sequence](img/reactive_sequence.png) <!-- .element: class="fragment" -->

![Reactive fallback](img/reactive_fallback.png) <!-- .element: class="fragment" -->

vvv

<!-- .slide: class="gridNx2" -->
### 2.7. Blackboard and ports <!-- .element: class="header" -->

* Blackboard = memory <!-- .element: class="fragment" -->
    * Use scarcely! <!-- .element: class="fragment" -->
* Ports = node parameters <!-- .element: class="fragment" -->
    * Can be in/out <!-- .element: class="fragment" -->
    * Can be constant... <!-- .element: class="fragment" -->
    * ... or store/load into/from the blackboard <!-- .element: class="fragment" -->

![In/out ports interacting with blackboard](img/blackboard.png) <!-- .element: class="fragment" -->

vvv

### 2.8. A complete example

<div class="r-stack">
<img src="img/full_example_frame1.png" class="fragment fade-out" data-fragment-index="0">
<img src="img/full_example_frame2.png" class="fragment fade-in-then-out" data-fragment-index="0">
<img src="img/full_example_frame3.png" class="fragment fade-in-then-out">
<img src="img/full_example_frame4.png" class="fragment fade-in-then-out">
<img src="img/full_example_frame5.png" class="fragment fade-in-then-out">
<img src="img/full_example_frame6.png" class="fragment fade-in-then-out">
<img src="img/full_example_frame7.png" class="fragment fade-in-then-out">
<img src="img/full_example_frame8.png" class="fragment fade-in-then-out">
<img src="img/full_example_frame9.png" class="fragment fade-in-then-out">
<img src="img/full_example_frame10.png" class="fragment fade-in-then-out">
<img src="img/full_example_frame11.png" class="fragment fade-in-then-out">
<img src="img/full_example_frame12.png" class="fragment fade-in-then-out">
<img src="img/full_example_frame13.png" class="fragment fade-in-then-out">
<img src="img/full_example_frame14.png" class="fragment fade-in-then-out">
<img src="img/full_example_frame15.png" class="fragment">
</div>

>>>

## 🌳 3. The BT.cpp library 🌳

(available at https://www.behaviortree.dev/) 

vvv

## 3.1. Overview

* Open source <!-- .element: class="fragment" -->
* Started by Michele Coledanchise circa 2015 <!-- .element: class="fragment" -->
* ... maintained by Davide Faconti <!-- .element: class="fragment" -->
* C++ 17 <!-- .element: class="fragment" -->
* Very few dependencies <!-- .element: class="fragment" -->
* BTs as XML files <!-- .element: class="fragment" -->
* Async actions as first class citizens <!-- .element: class="fragment" -->
* Easy interaction with ROS 2 <!-- .element: class="fragment" -->

vvv

## 3.1. Architecture

<div class="r-stack">
<img src="img/architecture_frame1.png" class="fragment fade-out" data-fragment-index="0">
<img src="img/architecture_frame2.png" class="fragment fade-in-then-out" data-fragment-index="0">
<img src="img/architecture_frame3.png" class="fragment fade-in-then-out">
<img src="img/architecture_frame4.png" class="fragment fade-in-then-out">
<img src="img/architecture_frame5.png" class="fragment fade-in-then-out">
<img src="img/architecture_frame6.png" class="fragment fade-in-then-out">
<img src="img/architecture_frame7.png" class="fragment fade-in-then-out">
<img src="img/architecture_frame8.png" class="fragment fade-in-then-out">
<img src="img/architecture_frame9.png" class="fragment fade-in-then-out">
<img src="img/architecture_frame10.png" class="fragment fade-in-then-out">
<img src="img/architecture_frame11.png" class="fragment fade-in-then-out">
<img src="img/architecture_frame12.png" class="fragment">
</div>

vvv

## 3.3. Synchronous vs asynchronous actions

|              | Can be halted | Tree responsiveness | Returns                   |
| ------------ | ------------- | ------------------- | ------------------------- |
| Synchronous  | ❌            | ❌                  | Success, Failure          |
| Asynchronous | ✅            | ✅                  | Success, Failure, Running |

**Async nodes are generally preferred!** <!-- .element: class="fragment" -->

vvv

<!-- .slide: class="gridNx2" -->

## 3.3. Creating an asynchronous action <!-- .element: class="header" -->

<img src="img/AskUserName.png">

<pre style="height:750px;" class="language-cpp"><code data-trim data-line-numbers="|1|3-5|11-15|17-23|26|32|33"><script type="text/template">
class AskUserName : public BT::StatefulActionNode {
    public:
        static BT::PortsList providedPorts() {
            return { BT::OutputPort<std::string>("userName") };
        }
        
        AskUserName(const std::string& nodeName,
                    const BT::NodeConfig& config)
            : BT::StatefulActionNode(nodeName, config) {}

        BT::NodeStatus onStart() override {
            input.clear();
            std::cout << "What's your name? " << std::endl;
            return BT::NodeStatus::RUNNING;
        }

        BT::NodeStatus onRunning() override {
            if (!input.empty()) {
                setOutput("userName", input);
                input.clear();
                return BT::NodeStatus::SUCCESS;
            }
            return BT::NodeStatus::RUNNING;
        }

        void onHalted() override {}
};

// ...

int main() {
    BT::BehaviorTreeFactory factory;
    factory.registerNodeType<AskUserName>("AskUserName");
    // ...
}
</script></code></pre>

vvv

<!-- .slide: class="gridNx2" -->

## 3.3. Creating a synchronous action <!-- .element: class="header" -->

<img src="img/GreetUser.png">

<pre style="height:750px;" class="language-cpp"><code data-trim data-line-numbers="|11-15"><script type="text/template">
class GreetUser : public BT::SyncActionNode
{
    public:
        static BT::PortsList providedPorts() {
            return { BT::InputPort<std::string>("userName") };
        }

        GreetUser(const std::string& nodeName, const BT::NodeConfig& config)
            : BT::SyncActionNode(nodeName, config) {}

        BT::NodeStatus tick() override {
            std::cout << "Hello " << getInput<std::string>("userName").value()
                      << "!" << std::endl;
            return BT::NodeStatus::SUCCESS;
        }
};

// ...

int main() {
    // ...
    factory.registerNodeType<GreetUser>("GreetUser");
}

</script></code></pre>

vvv

<!-- .slide: class="gridNx2" -->

## 3.3. Creating and running a tree <!-- .element: class="header" -->

<img src="img/ask_name_tree.gif">

<pre style="height:750px;" class="fragment language-cpp"><code data-trim data-line-numbers="|1-10|14|15"><script type="text/template">
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

int main() {
    // ...
    auto tree = factory.createTreeFromText(xmlTree);
    tree.tickWhileRunning(std::chrono::milliseconds(100));
    // ...
}
</script></code></pre>

vvv
<!-- .slide: class="gridNx2" -->
## 3.4. Preconditions & postconditions <!-- .element: class="header" -->

![Preconditions can simplify trees](img/precondition-example.png) <!-- .element: height="400" class="fragment" -->

![Using postconditions to know which node in a sequence failed](img/postcondition-example.png) <!-- .element: height="400" class="fragment" -->

vvv

## 3.7. Execution example

vvv

<!-- .slide: data-background-video="videos/full_example_nyam.mp4" data-background-video-loop data-background-video-muted -->


vvv

## 3.8. Other nice features

* Scripting language <!-- .element: class="fragment" -->
* Support for parallel control nodes <!-- .element: class="fragment" -->
* Tools for debug and diagnostics <!-- .element: class="fragment" -->
* Allows dynamic plugins <!-- .element: class="fragment" -->

>>>

## 🤖 4. ROS 2 integration 🤖

vvv

### 4.1. Overview

* Async actions → rclcpp\_action (or even rclcpp::Client)
    * The server side of the action can be in any ROS 2-supported language

vvv

### 4.2. ROS 2 actions as BT.cpp async actions

<pre style="height:750px;" class="language-cpp"><code data-trim data-line-numbers="|12-16|18-20|22-27|29-32|35-51|66-69|72-77"><script type="text/template">

class SleepAction : public RosActionNode<btcpp_ros2_interfaces::action::Sleep> {
public:
  SleepAction(const std::string& name, const NodeConfig& conf,
              const RosNodeParams& params)
    : RosActionNode<btcpp_ros2_interfaces::action::Sleep>(name, conf, params)
  {}

  static BT::PortsList providedPorts(){
    return providedBasicPorts({ InputPort<unsigned>("msec") });
  }

  bool setGoal(Goal& goal) override {
    auto timeout = getInput<unsigned>("msec");
    goal.msec_timeout = timeout.value();
    return true;
  }

  void onHalt() override {
    RCLCPP_INFO(logger(), "%s: onHalt", name().c_str()); 
  }

  BT::NodeStatus onResultReceived(const WrappedResult& wr) override {
    RCLCPP_INFO(logger(), "%s: onResultReceived. Done = %s", name().c_str(),
        wr.result->done ? "true" : "false");

    return wr.result->done ? NodeStatus::SUCCESS : NodeStatus::FAILURE; 
  }

  virtual BT::NodeStatus onFailure(ActionNodeErrorCode error) override {
    RCLCPP_ERROR(logger(), "%s: onFailure with error: %s", name().c_str(), toStr(error));
    return NodeStatus::FAILURE; 
  }
};

static const char* xml_text = R"(
 <root BTCPP_format="4">
     <BehaviorTree>
        <Sequence>
            <PrintValue message="start"/>
            <SleepAction name="sleepA" msec="2000"/>
            <PrintValue message="sleep completed"/>
            <Fallback>
                <Timeout msec="1500">
                   <SleepAction name="sleepB" action_name="sleep_service" msec="2000"/>
                </Timeout>
                <PrintValue message="sleep aborted"/>
            </Fallback>
        </Sequence>
     </BehaviorTree>
 </root>
 )";

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  auto nh = std::make_shared<rclcpp::Node>("sleep_client");

  BehaviorTreeFactory factory;

  factory.registerNodeType<PrintValue>("PrintValue");

  RosNodeParams params;
  params.nh = nh;
  params.default_port_value = "sleep_service";

#ifdef USE_SLEEP_PLUGIN
  RegisterRosNode(factory, "../lib/libsleep_action_plugin.so", params);
#else
  factory.registerNodeType<SleepAction>("SleepAction", params);
#endif

  auto tree = factory.createTreeFromText(xml_text);

  for(int i = 0; i < 5; i++)
  {
    tree.tickWhileRunning();
  }

  return 0;
}

</script></code></pre>

vvv

## 🎓 5. Research opportunities 🎓

vvv

### 5.1. Genetic algorithms

![Learn topology of BTs](img/genetic_algorithms.png)

vvv

### 5.2. Behavior tree + task planning

![Expand condition nodes using task planning (backward chaining)](img/behavior_trees_task_planning.png)

vvv

<!-- .slide: class="gridNx2" -->

### 5.3. BTs and RL <!-- .element: class="header" -->

<ul>
    <li>RL:
        <ul>
            <li class="fragment">Near-optimal behavior</li>
            <li class="fragment">"Hands-off"</li>
        </ul>
    </li>
    <li>BTs:
        <ul>
            <li class="fragment">Explainable</li>
            <li class="fragment">Modular</li>
            <li class="fragment">Guaranteed convergence</li>
        </ul>
    </li>
</ul>


<div class="fragment">
<b>Can we get the best of both worlds?</b>
<ul>
    <li class="fragment">Replace nodes or subtrees by RL</li>
    <li class="fragment">Learn priorities of fallback nodes</li>
    <li class="fragment">Improve backward chaining with RL</li>
    <li class="fragment">Many more possibilities...</li>
</ul>
</div>

>>>

## 🏁 6. Conclusions 🏁

* Great reusability <!-- .element: class="fragment" -->
    * Maintain repository of nodes and subtrees <!-- .element: class="fragment" -->
* Drag & drop demos <!-- .element: class="fragment" -->
* Good visual feedback <!-- .element: class="fragment" -->
* Lots of resources and support <!-- .element: class="fragment" -->
* Research opportunities if you work in planning <!-- .element: class="fragment" -->

>>>

## 🔗 7. Resources 🔗

* [Code used for this presentation](https://github.com/sprkrd/behavior_tree_tutorial)
* [Youtube series on BTs by P. Ögren](https://www.youtube.com/watch?v=KeShMInMjro&list=PLFQdM4LOGDr_vYJuo8YTRcmv3FrwczdK)
* [Behavior Trees in Robotics and AI free book](https://arxiv.org/abs/1709.00084)
* [M. Coledanchise PhD thesis](https://kth.diva-portal.org/smash/get/diva2:1078940/FULLTEXT01.pdf)

>>>

# Questions?
