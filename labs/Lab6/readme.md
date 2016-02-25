# Word Frequency with Binary Search Trees

## Lab 6

Binary Search Trees are excellent for searching since their average seek time in O(lg n). Not bad.  In this lab you will finish constructing a BST class and then use it to search for words.

The class has been started for you with `bst.h` header file.  In the file there is a class definition.  Examine it and be sure you understand the `left` and `right` pointers.   You will need to write the `insert` and `find` functions.  You will probably need to add more functions as well.

Once you have finished your tree class, you will make use of it.

## Part A

The question you want to answer is:  What words from a text are not found in the dictionary?

Choose one dictionary file and read it in to your binary tree.  There are two included in the labs folder.  Then you will have a searchable dictionary.  Then choose a classic text, and look up each word in the text using your binary tree dictionary.  Which dictionary is better?  For which text?

## Part B

The question you want to answer is:  What 3 words appear most often in a classic text?  (which words and how many times).

In order to accomplish this, you will need to modify the binary search tree class you have written to include a data field for the frequency.  You will also need to modify `insert` so that when it inserts a word into the tree, it also increments the frequency.  Finally, you will need to make a new function to traverse the tree, looking for the top three frequencies.

## Files

Included in the Lab folder are a few dictionaries and a few classic texts to use.  The `main.cpp` file has the code needed to read in these files, just make sure you put them in your working directory.

Since more is required for this lab, please work with a partner or in a group of three.