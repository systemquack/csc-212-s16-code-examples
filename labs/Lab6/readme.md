# Using Doubly Linked Lists to Explore Word Occurence

## Lab 6

We can apply our Linked Lists from the last lab to some problems involving classic texts. Since our data structure can very easily add items, let’s add many. We will be loading a dictionary and using it to look up words in a book.


### Overview of the Repository

The repository has code files:
* dll.h       - complete header file for doubly linked lists
* dll.cpp     - incomplete implementation of the lists
* main.cpp    - code fragment illustrating reading a text file

Dictionary files:
* dictionary-brit.txt - plain text dictionary
* dictionary.txt      - larger plain text dictionary

Books:
* AliceInWonderland.txt  - Lewis Carroll writes about Alice
* ATaleOfTwoCities.txt   - Dickens’ French Revolution
* Pride                  - Just a few words, for TESTING
* PrideAndPrejudice.txt  - Jane Austen Classic
* WarAndPeace.txt        - Tolstoi

### What to do:

1. Download the DLL class from the repository.  This has a complete `dll.h` file but an incomplete `dll.cpp` file.  You must finish it.  You will need to implement a `find` function that searches the list for the given string parameter and returns a pointer to the node with the string, otherwise it returns NULL if the string is not found in the list.  The `insert_end` function inserts the string at the tail of the linked list.  The `print_list` function prints out the linked list up to the first n items.  Note that frequencies have been added to the Nodes, along with a simple function to `increment_frequency` given a pointer to a Node. Since ‘insert_end’ and ‘increment_frequency` are private, you will use them in `insert` function, which simply inserts a word if it is not already in the list, and increments its frequency if it is.

2. Once your class is complete, you will need to write a `main` function to test and use it.  

Take the `main.cpp` file from the repository, because it has code that can open a text file and read in each word from that file. Make sure you can understand what the code is doing.
