//
//  bst.cpp
//  

#include "bst.h"

BSTree::BSTree()
{
    root = NULL;
}

BSTree::~BSTree()
{
    destroy(root);
}

void BSTree::destroy(BSTNode* p)
{
    if(p)
    {
        destroy(p->left);
        destroy(p->right);
        delete p;
    }
}

// the other functions..

