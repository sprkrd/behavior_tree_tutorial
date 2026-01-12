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

### 2.6. Synchronous vs asynchronous actions

|              | Can be halted | Tree responsiveness | Returns                   |
| ------------ | ------------- | ------------------- | ------------------------- |
| Synchronous  | ❌            | ❌                  | Success, Failure          |
| Asynchronous | ✅            | ✅                  | Success, Failure, Running |

**Async nodes are preferred!** <!-- .element: class="fragment" -->

vvv

<!-- .slide: class="gridNx2" -->
### 2.7. Reactive version of control nodes <!-- .element: class="header" -->

![Reactive sequence](img/reactive_sequence.png) <!-- .element: class="fragment" -->

![Reactive fallback](img/reactive_fallback.png) <!-- .element: class="fragment" -->

vvv

<!-- .slide: class="gridNx2" -->
### 2.8. Blackboard and ports <!-- .element: class="header" -->

* Blackboard = memory <!-- .element: class="fragment" -->
    * Use scarcely! <!-- .element: class="fragment" -->
* Ports = node parameters <!-- .element: class="fragment" -->
    * Can be in/out <!-- .element: class="fragment" -->
    * Can be constant... <!-- .element: class="fragment" -->
    * ... or store/load into/from the blackboard <!-- .element: class="fragment" -->

![In/out ports interacting with blackboard](img/blackboard.png) <!-- .element: class="fragment" -->

vvv

### 2.9. A complete example

>>>

## 🌳 3. The BT.cpp library 🌳

(available at https://www.behaviortree.dev/) 

vvv

## 3.1. Overview

vvv

## 3.2. The XML schema

vvv

## 3.3. Loggers and observers

vvv

## 3.4. Preconditions

vvv

## 3.5. Groot2

vvv

## 3.6. Other features

>>>

## 🤖 4. ROS 2 integration 🤖

>>>

## 🎓 5. Research opportunities 🎓

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
