//
//  dll.h
//  

#ifndef ____dll__
#define ____dll__

#ifndef NULL
#define NULL 0x00
#endif

#include <string>

class Node {
    
private:
    std::string data;
    int frequency;
    Node *next;
    Node *prev;
    
public:
    Node(std::string word);
    ~Node();
    
    friend class List;
};

class List {
    
private:
    Node *head;
    Node *tail;

    Node* find(std::string);          // returns a pointer to the node containing the string,
                                      //  or NULL if the string is not in the list

    void insert_end(std::string);         // insert the string at the end of the list
    void increment_frequency(Node* ptr);  // increments the frequency of the node pointed to by ptr
    
public:
    List();
    ~List();
    
    void insert(std::string);         // inserts the string into the list, unless it is already there,
                                      //   in which case it increments the frequency of that string
    void print_list(int n);           // print the first n items
    
};


#endif /* defined(____dll__) */
