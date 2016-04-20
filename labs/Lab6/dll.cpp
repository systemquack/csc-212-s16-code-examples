//
//  dll.cpp
//  

#include "dll.h"
#include <iostream>

Node::Node(std::string word) {
    data.assign(word);    // copy the word into the node
    frequency = 1;        // this is the first of its kind
    next = NULL;
    prev = NULL;
}

Node::~Node() {
}

List::List() {
    head = NULL;
    tail = NULL;
}

List::~List() {
    Node *p;
    while (head) {
        p = head;
        head = p->next;
        delete p;
    }
}

// the rest of the functions: