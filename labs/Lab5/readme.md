# Lab 5

## Exploring Linked Lists through the Debugger

### Goal:
  To practice using the debugger to examine linked lists

## What is a linked list?

We have seen that arrays are nice to work with because we can access any element in constant time. One disadvantage has been that we must know the size of the array we will need before we can start working with it. If we don't know, then we must guess, and then if more memory is needed, we must process this in a special way - see the dynamic arrays.

A different data structure called a linked list solves the size problem. In fact, as soon as we need another memory cell, we allocate it and add it to the list. We never need to guess at the final size, or recopy anything. We simply use a pointer to show where to get the next piece of data. What is the disadvantage of this approach? We lose the ability to access any element in constant time. We must now move through the list from the beginning each time.

Let's look at a simple example of a linked list a little closer.
In the `list.h` file, we can see two classes. One is called Node, and the other is List. Node holds only the data (which could be anything, but for us it is a simple int) and a pointer to another Node.  The List class holds a pointer to the first Node and a pointer to the last Node and then some functions to operate on the List. `list.cc` has the implementations of the `insert_end`, `print`, and `remove` functions.`Main.cc` simply appends some data, and then removes it, printing after some operations.


## Using the debugger

The first task we have is to step through the code as it adds to the list.

We want to fill in this chart with the memory locations of the first 5 nodes.  Where should we set the breakpoint for this?

Memory Address | Name | Value
-------------- | ---- | -----


--------------------


--------------------


--------------------


--------------------


--------------------


--------------------


--------------------


--------------------


--------------------



Our code compiles just fine.  After looking through it, it seems ok.  But when we run the program, to test it, there is a problem!

We will use the debugger to find the problem.

What appears to be the problem from the test?

Where should we start looking in the code, that is, where to break:




Once the problems are solved, let's add to this code.

1. Add reverse pointers to make a doubly linked list
2. Add a function called 'insert' that puts data into the list in order
3. Once we know the list is in order, we can update delete, and make it more efficient
