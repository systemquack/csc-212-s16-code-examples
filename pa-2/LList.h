#ifndef __llist__
#define __llist__
#include <string>

class LLNode {
    private:
        double lat;
        double lon;
        std::string name;
        LLNode *next;

        double distance(double _la, double _lo);

    public:
        LLNode(double la, double lo, const std::string &desc);
        ~LLNode();

    friend class LinkedList;
};

class LinkedList {
    private:
        unsigned int size;
        LLNode *head;

        void destroy(LLNode *p);

    public:
        LinkedList();
        ~LinkedList();

        void insert(double la, double lo, const std::string &desc);
        unsigned int printNeighbors(double la, double lo, double rad, const std::string &filter);
        unsigned int getSize();
};

#endif
