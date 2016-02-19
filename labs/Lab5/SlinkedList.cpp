//
//  SlinkedList.cpp
//  

#include "SlinkedList.h"
#include <iostream>

using namespace std;
//TODO: introduce errors  (3? on delete..?)

//
// Print the data in the list
//
void List::Print() {
    
    // make a temporary pointer
    Node *tmp = head;

    // Case 1:
    // The List is empty
    //
    if ( tmp == NULL ) {
        cout << "EMPTY" << endl;
        return;
    }

    // Case 2:
    // One node in the list
    //
    if ( tmp->GetNext() == NULL ) {
        cout << tmp->GetData();
        cout << " --> ";
        cout << "NULL" << endl;
    }
    else {
        // Case 3:
        // More than one node in the list
        //  visit each node and print its data
        do {
            cout << tmp->GetData();
            cout << " --> ";
            tmp = tmp->GetNext();
        }
        while ( tmp != NULL );
        
        cout << "NULL" << endl;
    }
}// end Print

//
// Append a node to the linked list
//
void List::Append(char data) {
    
    // make a new node
    Node* newNode = new Node();
    newNode->SetData(data);
    newNode->SetNext(NULL);
    
    // make a temporary pointer
    Node *tmp = head;
    
    if ( tmp != NULL ) {
        // list is not empty, so
        // go to the end of the list
        while ( tmp->GetNext() != NULL ) {
            tmp = tmp->GetNext();
        }
        
        // point the last node to the new node
        tmp->SetNext(newNode);
    }
    else {
        // adding to an empty list,
        // so the new node is the
        // first node in the list
        head = newNode;
    }
}// end Append

//
// Delete a node from the list
//
void List::Remove(char data) {
    
    // make a temporary pointer
    Node *tmp = head;
    
    // Case 1:
    // the list is empty
    if ( tmp == NULL )
        return;
    
    // Case 2:
    // the list has one node, delete it
    if ( tmp->GetNext() == NULL ) {
        delete tmp;
        head = NULL;
    }
    else {
        // Case 3:
        // More than one node in the list
        // search the list for data
        Node *prev = nullptr;
        do {
            if ( tmp->GetData() == data ) break;
            prev = tmp;
            tmp = tmp->GetNext();
        } while ( tmp != NULL );
        
        // Adjust the pointers
        prev->SetNext(tmp->GetNext());
        
        // Delete the current node
        delete tmp;
    }
}// end Remove
