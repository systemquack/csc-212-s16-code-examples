#ifndef __LIST_H__ 
#define __LIST_H__ 

#ifndef NULL
#define NULL 0x00
#endif

class Node {

    private:
        int data;    // this data can be of any type
        Node *next;  // this is a pointer to the next node

    public:
        Node(int d);
        ~Node();

    friend class List;
};

class List {

    private:
        Node *head;
        Node *tail;

    public:
        List();
        ~List();

        void print_list();
        void insert_end(int);
        void remove(int);
};

#endif
