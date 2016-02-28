# Using our Linked Lists to Explore Word Frequency

## Lab 6

We can apply our Linked Lists from the last lab to some problems involving classic texts.  Since our data structure can very easily add items, let’s add many.  We will be loading a dictionary and using it to look up words in a book.  Then we will be loading the book and counting the words.


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
* PrideAndPrejudice.txt  - Jane Austen Classic
* WarAndPeace.txt        - Tolstoi

### What to do:

1. Download the DLL class from the repository.  This has a complete `dll.h` file but an incomplete `dll.cpp` file.  You must finish it.  You will need to implement a `locate` function that searches the list for the given string parameter and returns a pointer to the node with the string, otherwise it returns NULL if the string is not found in the list.  The `insert` function inserts the string into the linked list, and `remove` removes the node with that string.  There is also a `find` function that returns true if the string is in the list and false otherwise.


2. Once your class is complete, you will need to write a `main` function to test and use it.  

Take the `main.cpp` file from the repository, because it has code that can open a text file and read in each word from that file.  Make sure you can understand what the code is doing.

## Part A

The question you want to answer is:  What words from a text are not found in the dictionary?

Using your data structure, and the code to read in files, write code in `main.cpp` that will read in a dictionary file to your linked list.  This will give you a dictionary of words that you can access with your `find` function.  Select a book from the repository and look up all the words in that book to see if they are in the dictionary or not.  Output the words that are not in the dictionary to the screen.

## Part B

The question you want to answer is:  What 3 words appear most often in a classic text?  (which words and how many times).


In order to accomplish this, you will need to read in the book file to your list structure.  Be sure to call `increment_frequency` when the word is already in your list!  When it is read in, you should have the book in memory, in a searchable structure.  How will you be able to find the top 3 most frequent words?

Note:  for this assignment, you will most likely write a function that will traverse your list, searching for the most frequent words.