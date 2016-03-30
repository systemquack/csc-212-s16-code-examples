# Heap it up!

## Lab #9

In this lab you will be implementing a Heap class. There is starter code in the repository, make a new project with these files. The Heap is implemented as an array.

### In the repository:

`main.cpp` - this file contains the main function and a helper function called `fillVector()`. The main function right now loads the Heap class vector with some random values and displays them.

`heap.h` - this is the header file for the `Heap` class, it should not need to be changed to complete this Lab. Feel free to add comments to help you understand the class.

`heap.cpp` - this file implements the `Heap` class. You will not need to touch the `printAsVector()` nor the `printAsTree()` functions, they are simplistic but written for you to visualize your data as you work with the class. The `swap()` function is there to help you. Also, the `isMaxHeap()` function is there to validate that you have indeed created a max heap. You will need to implement the remaining functions: `downHeap()`, `upHeap()`, `insert()`, `removeMax()` and `buildHeap()`. Refer to the [slides] (http://homepage.cs.uri.edu/~malvarez/teaching/2016s/csc212/files/L14-pq-heaps-9x.pdf) from the lecture for descriptions of what these functions should do. Start with `downHeap()` and `upHeap()`. The comments outline what the function should do, but it is important to think of it as only dealing with the element stored at one index. It just follows one ‘node’ up or down the heap. `upHeap()` should be fairly straightforward, but `downHeap()` has a couple caveats. Be sure that the node has two children before you try to test for them, or swap them!  Once these are done, `insert()` should not be very long. There is more to the remaining two, but they should be straightforward.

Work in pairs because there is a lot to digest. Once you have it working, the TA will check it and your code and award your group credit.

### Minimum Expectation for credit

You must complete the `Heap` class and display a heap with at least 100 elements.
