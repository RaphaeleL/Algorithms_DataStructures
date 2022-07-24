# Data Structures and Algorithms 

Overview of some Basic Data Structures and Algorithms

> [Overview of some Data Structures](https://www.geeksforgeeks.org/data-structures/?ref=lbp)

## Linked List

A linked list is a linear data structure (like arrays) where each element is a separate object. A linked list is made up of two items that are data and a reference to the next node. A reference to the next node is given with the help of pointers and data is the value of a node. Each node contains data and links to the other nodes. It is an ordered collection of data elements called a node and the linear order is maintained by pointers. It has an upper hand over the array as the number of nodes i.e. the size of the linked list is not fixed and can grow and shrink as and when required, unlike arrays.

### Single

In this type of linked list, every node stores address or reference of the next node in the list and the last node has the next address or reference as NULL. For example 1->2->3->4->NULL

### Double

In this type of Linked list, there are two references associated with each node, One of the reference points to the next node and one to the previous node. The advantage of this data structure is that we can traverse in both directions and for deletion, we don’t need to have explicit access to the previous node. Eg. NULL<-1<->2<->3->NULL

### Circular

Circular linked list is a linked list where all nodes are connected to form a circle. There is no NULL at the end. A circular linked list can be a singly circular linked list or a doubly circular linked list. The advantage of this data structure is that any node can be made as starting node. This is useful in the implementation of the circular queues in the linked list. Eg. 1->2->3->1 [The next pointer of the last node is pointing to the first]

### Circular Double

The circular doubly linked list is a combination of the doubly linked list and the circular linked list. It means that this linked list is bidirectional and contains two pointers and the last pointer points to the first pointer.

## Stack

A stack or LIFO (last in, first out) is an abstract data type that serves as a collection of elements, with two principal operations: push, which adds an element to the collection, and pop, which removes the last element that was added. In stack both the operations of push and pop take place at the same end that is top of the stack. It can be implemented by using both array and linked list.

## Queue

### Simple

Simple queue also known as a linear queue is the most basic version of a queue. Here, insertion of an element i.e. the Enqueue operation takes place at the rear end and removal of an element i.e. the Dequeue operation takes place at the front end.

### Circular

In a circular queue, the element of the queue act as a circular ring. The working of a circular queue is similar to the linear queue except for the fact that the last element is connected to the first element. Its advantage is that the memory is utilized in a better way. This is because if there is an empty space i.e. if no element is present at a certain position in the queue, then an element can be easily added at that position.

### Priority

This queue is a special type of queue. Its specialty is that it arranges the elements in a queue based on some priority. The priority can be something where the element with the highest value has the priority so it creates a queue with decreasing order of values. The priority can also be such that the element with the lowest value gets the highest priority so in turn it creates a queue with increasing order of values.

## Binary Tree

Unlike Arrays, Linked Lists, Stack, and queues, which are linear data structures, trees are hierarchical data structures. 
A binary tree is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child. It is implemented mainly using Links. 

## Binary Search Tree 

Binary Search Tree (BST) is a tree whose main function is to search a specific element.
Binary Search Tree is a Binary Tree with the following additional properties: 
1. The left subtree of a node contains only nodes with keys less than the node’s key. 
2. The right subtree of a node contains only nodes with keys greater than the node’s key. 
3. The left and right subtree each must also be a binary search tree. 

## Hash

Hashing is a popular technique for storing and retrieving data as fast as possible. The main reason behind using hashing is that it gives optimal results as it performs optimal searches.
