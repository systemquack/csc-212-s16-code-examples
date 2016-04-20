#ifndef __BINTREE_H__
#define __BINTREE_H__

#include <stddef.h> // defines NULL

#define PREORDER 0x01
#define INORDER 0x02
#define POSTORDER 0x03

class BSTNode {
    private:
        int data;
        BSTNode *left;
        BSTNode *right;

    public:
        BSTNode(int d) { data = d; left = right = NULL; }
        ~BSTNode() {}

    friend class BSTree;
};

class BSTree {
    private:
        BSTNode *root;

        BSTNode *search(BSTNode *p, int d);
        void insert(BSTNode **p, int d);
        void destroy(BSTNode *p);
        void preorder(BSTNode *p);
        void inorder(BSTNode *p);
        void postorder(BSTNode *p);
        
    public:
        BSTree();
        ~BSTree();

        void insert(int d);
        bool remove(int d);
        BSTNode *search(int d);
        void traversal(int type);
};

#endif
