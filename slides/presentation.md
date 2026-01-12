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
* Started by Michele Coledanchise circa 2015
* ... maintained by Davide Faconti 
* C++ 17 <!-- .element: class="fragment" -->
* Very few dependencies
* BTs as XML files
* Async actions as first class citizens
* Easy interaction with ROS 2

vvv

## 3.1. Architecture

vvv

## 3.2. Registering nodes

vvv

## 3.3. Synchronous vs asynchronous actions

|              | Can be halted | Tree responsiveness | Returns                   |
| ------------ | ------------- | ------------------- | ------------------------- |
| Synchronous  | ❌            | ❌                  | Success, Failure          |
| Asynchronous | ✅            | ✅                  | Success, Failure, Running |

**Async nodes are generally preferred!** <!-- .element: class="fragment" -->

vvv

## 3.3. Registering, instantiate and run trees

vvv

## 3.4. Preconditions & postconditions

vvv

## 3.5. Loggers and observers

vvv

## 3.6. Groot2

vvv

## 3.7. Execution example

vvv

## 3.8. Other features

* Scripting language
* Support for parallel control nodes
* Node replacements (mocks)
* Allows dynamic plugins

>>>

## 🤖 4. ROS 2 integration 🤖

vvv

### 4.1. Overview

vvv

### 4.2. ROS 2 actions as BT.cpp async actions

vvv

### 4.3. Tree execution server

vvv

### 4.4. Execution example

>>>

## 🎓 5. Research opportunities 🎓

vvv

### 5.1. Genetic algorithms

vvv

### 5.2. Coledanchise

vvv

### 5.3. Madrid

>>>

## 🏁 6. Conclusions 🏁

* Great reusability
    * Maintain repository of nodes and subtrees
* Drag & drop demos
* Good visual feedback
* Lots of resources and support
* Research opportunities if you work in planning

>>>

## 🔗 7. Resources 🔗 
