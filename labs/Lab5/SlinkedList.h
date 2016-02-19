//
//  SlinkedList.h
//  
//
//  Created by Gabriel on 2/19/16.
//
//

#ifndef ____SlinkedList__
#define ____SlinkedList__

// Node class
class Node {
private:
    char data;  // this data can be any type
    Node* next; // this is a pointer to the next node
    
public:
    Node() {};
    void SetData(char aData) { data = aData; };
    void SetNext(Node* aNext) { next = aNext; };
    char GetData() { return data; };
    Node* GetNext() { return next; };
};

// List class
class List {
    Node *head;

public:
    List() { head = nullptr; };
    void Print();
    void Append(char data);
    void Remove(char data);
};

#endif /* defined(____SlinkedList__) */
