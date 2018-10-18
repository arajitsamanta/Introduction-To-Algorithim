
# Introduction To Algorithim

Study notes and code written for each chapter while reading the book **Introduction To Algorithim - 3rd Edition**

# Table of contents

1. [Foundatios](#foundations)
    1. [Role of Algorithims in Computing](#role-algo)
    2. [Getting Started](#getting-started)
    3. [Growth of Functions](#function-growth)
    4. [Divide-And-Conquer](#divide-conquer)
    5. [Probabilistic Analysis and Randomized Algorithms](#prob-rand-algo)
2. [Sorting and Order Statistics](#sorting)
    1. [Heapsort](#heapsort)
    2. [Quicksort](#quicksort)
    3. [Sorting in Linear Time](#linear-time-sort)
    4. [Medians and Order Statistics](#median-order-stat)
3. [Data Structures](#data-structures)
    1. [Elementary Data Structures](#elementary-data-structures)
    2. [Hash Tables](#hashtable)
    3. [Binary Search Trees](#bst)
    4. [Augmenting Data Structures](#augment-data-structure)
4. [Advanced Design and Analysis Techniques](#adv-analysis-design)
    1. [Dynamic Programming](#dynamic-prog)
    2. [Greedy Algorithim](#greedy-algo)
    3. [Amortized Analysis](#amort-analysis)
5. [Advanced Data Structures](#adv-data-structure)
    1. [B-Trees](#b-tress)
    2. [Fibonacci Heaps](#fibonacci-heaps)
    3. [Van Ende Boas Trees](#v-e-b-trees)
    4. [Data Structures for Disjoint sets](#disjoint-sets)
6. [Graph Algorithims](#graphs)
    1. [Elemantary Graph Algorithim](#elem-graph-algo)
    2. [Minimum Spanning Trees](#min-spanning-trees)
    3. [Single-Source Shortest Paths](#single-source-shortest-path)
    4. [All-Pairs Shortest Paths](#all-pairs-shortest-path)
    5. [Maximum FLow](#max-flow)
7. [Selected Topics](#selected-topics)
    1. [Mutithreaded Algorithim](#muti-thread-algo)
    2. [Matrix Operations](#matrix-operations)
    3. [Linear Programming](#linear-programming)
    4. [Polynomials and the FFT](#polynomials-fft)
    5. [Number-Theoretic Algorithims](#number-theory)
    6. [String Matching](#string-matching)
    7. [Computational Geometry](#compute-geometry)
    8. [NP-Completeness](#np-complete)
    9. [Approximation Algorithims](#approx-algo)
8. [Mathematical Background](#math-background)
    1. [Summations](#summations)
    2. [Sets](#sets)
    3. [Counting and Probability](#counting-probability)
    4. [Matrices](#matrices)


# Foundation <a name="foundations"></a>

## Role of Algorithims in Computing <a name="role-algo"></a>

Algorithms, an algorithm is any well-defined computational procedure that takes some value, or set of values, as input and produces some value, or set of values, as output. An algorithm is thus a sequence of computational steps that transform the input into the output.

## Getting Started <a name="getting-started"></a>
TODO##

## Growth of Functions <a name="function-growth"></a>
TODO##

## Divide-And-Conquer <a name="divide-conquer"></a>
TODO##

## Probabilistic Analysis and Randomized Algorithms <a name="prob-rand-algo"></a>
TODO##

# Sorting and Order Statistics <a name="sorting"></a>

## Heapsort <a name="heapsort"></a>
TODO##

## Quicksort <a name="quicksort"></a>
TODO##

## Sorting in Linear Time <a name="linear-time-sort"></a>
TODO##

## Medians and Order Statistics <a name="median-order-stat"></a>
TODO##

# Data Structures <a name="data-structures"></a>

## Elementary Data Structures <a name="elementary-data-structures"></a>

### Stack

### Queue

### Linked List

### Binary Tree

In computer science, a binary tree is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child.

#### Types of binary trees

- A **rooted** binary tree has a root node and every node has at most two children.
- A **full** binary tree (sometimes referred to as a **proper** or **plane** binary tree)is a tree in which every node has either 0 or 2 children. Another way of defining a full binary tree is a recursive definition.

    ![Full Binary Tree](./asset/trees/full_binary_tree.png)

- In a **complete** binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes at the last level h. An alternative definition is a perfect tree whose rightmost leaves (perhaps all) have been removed.

    ![Complete Binary Tree](./asset/trees/full_binary_tree.png)

- A **perfect** binary tree is a binary tree in which all interior nodes have two children and all leaves have the same depth or same level.
- A **balanced** binary tree is a binary tree structure in which the left and right subtrees of every node differ in height by no more than 1.One may also consider binary trees where no leaf is much farther away from the root than any other leaf.

#### Tree Operations/Properties

##### Height and Depth

1. The **depth** of a node is the number of edges from the node to the tree's root node. A root node will have a depth of 0.
2. The **height** of a node is the number of edges on the longest path from the node to a leaf.A leaf node will have a height of 0.
3. The **diameter (or width)** of a tree is the number of nodes on the longest path between any two leaf nodes. The tree below has a diameter of 6 nodes.

    ![Height Depth and Diameter](./asset/trees/height_depth.png)

    __Algorithim__

    ```NA
    height()
    1. If tree is empty then return 0
    2. Else
        (a) Get the max depth of left subtree recursively  i.e., call height( tree->left-subtree)
        (a) Get the max depth of right subtree recursively  i.e., call height( tree->right-subtree)
        (c) Get the max of max depths of left and right subtrees and add 1 to it for the current node.
            max_depth = max(max dept of left subtree, max depth of right subtree) + 1
        (d) Return max_depth
    ```

    __Example Tree__

    >
                1
            2       3
        4       5
    >
    See the below diagram for more clarity about execution of the recursive function height() for above example tree.
    ```NA
    height('1') = max(height('2'), height('3')) + 1  = 2 + 1
                                    /    \
                                  /         \
                                /             \
                              /                 \
                            /                     \
                height('2')                 height('3') = 1
    = max(height('4'), height('5')) + 1
    = 1 + 1   = 2
                    /    \
                  /        \
                /            \
              /                \
            /                    \
    height('4') = 1     height('5') = 1
    ```
    __Implementation__ 
    Code to calculate height of binary tree can be found [here](./ch03/trees.c)

#### Complexity Analysis Cheatsheet

Operation      | Best case       | Worst Case     | Average case   | Space
:------------: | :-------------: | :------------: | :------------: | :------:
height()       | O(n)            | O(n)           | O(n)           | O(n)



## Hash Tables <a name="hashtable"></a>
TODO##

## Binary Search Trees <a name="bst"></a>
TODO##

## Augmenting Data Structures <a name="augment-data-structure"></a>
TODO##

# Advanced Design and Analysis Techniques <a name="adv-analysis-design"></a>

## [Dynamic Programming <a name="dynamic-prog"></a>
TODO##

## Greedy Algorithim <a name="greedy-algo"></a>
TODO##

## Amortized Analysis <a name="amort-analysis"></a>
TODO##

# Advanced Data Structures <a name="adv-data-structures"></a>

## B-Trees <a name="b-trees"></a>
TODO##

## Fibonacci Heaps <a name="fibonacci-heaps"></a>
TODO##

## Van Ende Boas Trees <a name="v-e-b-trees"></a>
TODO##

## Data Structures for Disjoint sets <a name="disjoint-sets"></a>
TODO##

# Graph Algorithims <a name="graphs"></a>

## Elemantary Graph Algorithim <a name="elem-graph-algo"></a>
TODO##

## Minimum Spanning Trees <a name="min-spanning-trees"></a>
TODO##

## Single-Source Shortest Paths <a name="single-source-shortest-path"></a>
TODO##

## All-Pairs Shortest Paths <a name="all-pairs-shortest-path"></a>
TODO##

## Maximum FLow <a name="max-flow"></a>
TODO##

#Selected Topics <a name="selected-topics"></a>

## Mutithreaded Algorithim <a name="muti-thread-algo"></a>
TODO##

## Matrix Operations <a name="matrix-operations"></a>
TODO##

## Linear Programming <a name="linear-programming"></a>
TODO##

## Polynomials and the FFT <a name="polynomials-fft"></a>
TODO##

## Number-Theoretic Algorithims <a name="number-theory"></a>
TODO##

## String Matching <a name="string-matching"></a>
TODO##

## Computational Geometry <a name="compute-geometry"></a>
TODO##

## NP-Completeness <a name="np-complete"></a>
TODO##

## Approximation Algorithims <a name="approx-algo"></a>
TODO##

# Mathematical Background <a name="math-background"></a>

## Summations <a name="math-background"></a>
TODO##

## Sets <a name="sets"></a>
TODO##

## Counting and Probability <a name="counting-probability"></a>
TODO##

## Matrices <a name="matrices"></a>
TODO##