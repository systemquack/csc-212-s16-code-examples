//
//  main.cpp
//  SLinkedList
//

#include "SlinkedList.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    // New list
    List list;
    
    // Append nodes to the list
    list.Append('a');
    list.Print();
    list.Append('b');
    list.Print();
    list.Append('c');
    list.Print();
    list.Append('d');
    list.Print();
    list.Append('e');
    list.Print();
    
    // Delete nodes from the list
    list.Remove('d');
    list.Print();
    list.Remove('c');
    list.Print();
    list.Remove('b');
    list.Print();
    list.Remove('e');
    list.Print();
    list.Remove('a');
    list.Print();
    
    return 0;
}
