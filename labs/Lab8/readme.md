# STL and Templates: how does BSTree and std::Map compare ?

## Lab 8

For the last two weeks, we have been working with texts. This time we will be focussed on the performance of some of the data structures we have been working with in this class. By now we are convinced of the benefits of Binary Search Trees over a simple Linked List. Let us compare our implementation to the professional ones.

### Overview

Professional programmers often make use of the data structures in this course, but are not often writing them by hand. They do it by making use of the Standard Template Library. They can also write common algorithms in a generic way, so that code can be more readily reused. C++ has a Template feature that faciliates these ideas.

### What to do in the lab

We will have a short introduction to the Standard Template Library (STL) and templates. You may want to review the slides below, as well. Once you are ready, you will be repeating the lab from last week, only this time using the `std::map` instead of your binary tree. Specifically, read in one of the texts, and then print out the first 20 words. You can use your project from last week if you like, I’ve simply repeated the code from last week here.

To make things slightly more interesting, I’ve added a very long novel called `Clarissa.txt` which has about 600,000 words in it.


### Minimum Expectation for credit

In order to receive credit for the lab (attendance) you must at least:

1. Enter the code to declare and use a `std::map`
2. Read in the entire text of the file of your choice from the repository
3. Display the first 20 words and their frequencies alphabetically on the screen

### Once this is done

1. Add timing code to measure the amount of time it takes to read in the file
2. Go back to your BSTree from last week and measure the time for the same text (add timing code if needed)
3. Measure on a few texts and create a table of their values, is there a difference in the times?

### References

Some high-level, useful slides (http://www.slideshare.net/SreejithSree1/stl-25264696).

More in-depth slides (http://ee.usc.edu/~redekopp/cs104/slides/L09_STL.pdf).

The Template tutorial (http://www.cplusplus.com/doc/oldtutorial/templates/).

The `std::map` details can be found here (http://www.cplusplus.com/reference/map/map/). Pay special attention to the `insert` and `find` functions.

