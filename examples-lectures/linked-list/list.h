#ifndef __LIST_H__ 
#define __LIST_H__ 

#ifndef NULL
#define NULL 0x00
#endif

class Node {

    private:
        int data;
        Node *nxt;

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

        void insert_end(int);
};

#endif
