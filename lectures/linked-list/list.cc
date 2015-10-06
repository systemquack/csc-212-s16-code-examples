#include "list.h"

Node::Node(int d) {
    data = d;
    nxt = NULL;
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
        head = p->nxt;
        delete p;
    }
}

void List::insert_end(int d) {
    if (head) {
        tail->nxt = new Node(d);
        tail = tail->nxt;
    }
    else {
        head = tail = new Node(d);
    }
}
