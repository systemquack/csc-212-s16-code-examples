# Applying Trees for Fast Look-ups

## Lab 7

Let’s implement and use a binary tree and apply this to our problem from the last lab. Since the tree is good at searching ( a theoretical O(log n) ) we should see an increase in performance.


### Overview

You will implement part of a binary search tree. The header file `bst.h` is in the repository, along with `bst.cpp` most of them are complete. Note that the files have the same public functions as the List class (from Lab 6), except there is a different `print` function.  `print_range` will take two strings as parameters, and print out the words in your tree lexically between those words. An explanation and the pseudo-code can be found on page 101 of your book. The code is included here for you:

```
Algorithm RangeQuery(key1, key2, v):

  Input: Search keys, key1 and key2 and a node v of a binary search tree T
  Output: The elements stored in the subtree of T rooted at v whose keys
          are in the range [key1,key2]

  if T.isExternal(v) then
    return 0
  if key1 <= key(v) <= key2 then
    print RangeQuery(key1, key2, T.leftChild(v))
    printData(v);
    print RangeQuery(key1, key2, T.rightChild(v))
  else if key(v) < key1 then
    print RangeQuery(key1, key2, T.rightChild(v))
  else if key2 < key(v) then
    print RangeQuery(key1, key2, T.leftChild(v))

end RangeQuery
```

Note: This pseudo-code has been modified slightly for this problem.


### What to do in the lab

After finishing the `print-range` function, you will need to change the `main` file. You can use your `main` file from last week, only this time replacing the Lists with Trees.  Your `main` should read in all the words from a book into a bst, and then display a range of words.

### Minimum Expectation for credit

In order to receive credit for the lab (attendance) you must at least:

1. implement the `print_range` function
2. read in the entire text of one of the books in the repository
3. display words on the screen:
   * recommended:
   - for Alice : eat to eels
   - for Tale  : tails to talk
   - for Pride : family to fashion
   - for War   : anxiety to anything

If you have completed this, you may be interested in going further:

You should experience a speed-up, but it is a good idea to quantify it. One method is with actual time passed, and we’ve already seen several examples of code to note the time. Add in code to measure the running time of reading and inserting the text of a book file to this Tree Lab and also the List Lab. Can you get some empirical data to support the theoretical running times of each?

