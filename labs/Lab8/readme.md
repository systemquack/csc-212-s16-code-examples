# Comparing Performance: Your tree vs. AVL vs. std::Map

## Lab 8

For the last two weeks, we have been working with texts. This time we will be focussed on the performance of some of the data structures we have been working with in this class. By now we are convinced of the benefits of Binary Search Trees over a simple Linked List. Let us compare our implementation to some professional ones.

### Overview

We now have your BSTree, but we will add in the repository an AVL tree implemented as a template and also count the Map container from the STL. The goal is to compare these three data structures on a performance test. The benchmark is this: To read in our `dictionary.txt` file into the data structure, then search it for every word in the `Clarissa.txt` file in the repository.

### What to do in the lab

Download the `dictionary.txt` file and `Clarissa.txt` file, the `avl_tree.h` header file, and starter `main.cpp` file, and start a new project. Your task is to write the `main.cpp` file to time each of the three data structures on the benchmark and write out the results (preferably) to a file. The `main.cpp` file should do something like:


1. Declare an `std::map`
2. Set a NotFound word count to zero
3. Mark the time as starting time
4. Read in `dictionary.txt` to that map
5. Mark the time as insert time
6. Read the `Clarissa.txt` file, searching the map for each word
7. If the word is NOT found, incrementing the count
8. Mark the time as finishing time
9. Report on the length of the intervals from start to insert to finish
10. Repeat this for the other two data structures (your BSTree and avl_tree)


### Minimum Expectation for credit

In order to receive credit for the lab (attendance) you must at least:

1. Show the three running times from the benchmark
2. Show the number of words not found in the dictionary
3. Answer which data structure performed the fastest at each stage

### Once this is done

1. Use the texts from earlier labs to make a table
2. What is the underlying structure for the `std::map` ?


## How to use the `Avl.h` and `std::map`

To use `Avl.h` include also `Comparable.h` and `Avl.cc` in your project. To use them, declare a tree and comparable like this:

```
AvlTree<std::string> myTreeName;
Comparable<std::string> * found = NULL;  // this is a pointer
. . .

  found = myTreeName.Insert(&WordToInsert);
  if(found) {
    std::cout << WordToInsert << “ was already in the tree.”;
. . .

  found = myTreeName.Search(WordToFind);
  if(!found) {
    std::cout << WordToFind << “ is not in the tree.”;
. . .
```

The `std::map` details can be found here (http://www.cplusplus.com/reference/map/map/). Pay special attention to the `insert` and `find` functions.

