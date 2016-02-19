# Lab 5

## Linked Lists and Debugging

### Goal:
  To practice using the debugger with linked lists

## What is a linked list?

We have seen that arrays are nice to work with because we can access any element in 
constant time. One disadvantage has been that we must know the size of the array we will
need before we can start working with it. If we don't know, then we must guess, and then
if more memory is needed, we must process this in a special way - see the dynamic arrays.

A different data structure called a linked list solves the size problem. In fact, as soon
as we need another memory cell, we allocate it and add it to the list. We never need to
guess at the final size, or recopy anything. We simply use a pointer to show where to get
the next piece of data. What is the disadvantage of this approach? We lose the ability to
access any element in constant time. We must now move through the list from the beginning
each time.

Let's look at a simple example of a linked list a little closer.
In the SLinkedList.h file, we can see two classes. One is called Node, and the other is
List. Node holds only the data (which could be anything, but for us it is a simple char)
and a pointer to another Node. The functions allow getting and setting these fields. The
List class holds a pointer to the first Node and then some functions to operate on the 
List. SLinkedList.cpp has the implementations of the Append, Print, and Remove functions.
Main.cpp simply appends some data, and then removes it all, printing after each operation.


## Using the debugger

our code compiles just fine.  looking at it, it seems ok.  when we run the program,
however, there is a problem!

We will use the debugger to find the problem.

1.segmentation fault _when we delete a node, we get an error_
2.correctness error _when we delete a node, we do not delete the correct one.._
3._another error, maybe for the students to find on their own  last node not well deleted_

we can trace the normal execution of the code to watch it add to the end, as well.

Let's add to this code.

It should be no problem to make some improvements to this code:
1. and a function called 'insert' that puts data into the list in order
2. once we know the list is in order, we can update delete, and make it more efficient
3. Lastly, and most important, add a pointer to the end (Tail) and add reverse pointers

This last one is a doubly linked list.

We get practice with pointers
We get practice with the debugger, and a chance to manipulate simple code..