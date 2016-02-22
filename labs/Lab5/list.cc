#include "list.h"
#include <iostream>

Node::Node(int d) {
    data = d;
    next = NULL;
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

void List::print_list() {

    // make a temporary pointer
    Node *temp = head;
    
    // Case 1:
    // The List is empty
    //
    if (temp == NULL)
    {
        std::cout << "EMPTY" << std::endl;
        return;
    }// end if
    
    // Case 2:
    // One node in the list
    //
    if (temp->next == NULL) {
        std::cout << temp->data;
        std::cout << " --> ";
        std::cout << "NULL" << std::endl;
    }
    else
    {
        // Case 3:
        // More than one node in the list
        //  visit each node and print its data
        while (temp != NULL)
        {
            std::cout << temp->data << " --> ";
            temp = temp->next;
        }
        
        std::cout << "NULL" << std::endl;
    }
}


void List::insert_end(int d) {
    if (head) {
        tail->next = new Node(d);
        tail = tail->next;
    }
    else {
        head = tail = new Node(d);
    }
}


void List::remove(int d) {
    
    // make a temporary pointer
    Node *temp = head;
    
    // Case 1:
    // the list is empty
    if (temp == NULL)
        return;
    
    // Case 2:
    // the list has one node, delete it
    if (temp->next == NULL)
    {
        delete temp;
        head = NULL;
        tail = NULL;
    }
    else
    {
        // Case 3:
        // More than one node in the list
        //
        //
        Node *prev = NULL;
        while (temp != NULL)
        {
            if (temp->data == d) break;
            prev = temp;
            temp = temp->next;
        }
        
        // Adjust the pointers
        prev->next = temp->next;
        
        // Delete the current node
        delete temp;
    }
    
}

