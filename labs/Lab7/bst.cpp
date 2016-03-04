//
//  bst.cpp
//  

#include "bst.h"
#include <iostream>

BSTree::BSTree()
{
    root = NULL;
}

BSTree::~BSTree()
{
    destroy(root);
}

void BSTree::destroy(BSTNode *p)
{
    if(p)
    {
        destroy(p->left);
        destroy(p->right);
        delete p;
    }
}

BSTNode* BSTree::find(BSTNode *node, std::string word)
{
    BSTNode *p = node;
    
    if (p != NULL)
    {
    if(p->data == word)
        return p;
    else if(p->data < word)
        return find(p->right, word);
    else if(p->data > word)
        return find(p->left, word);
    }
    return NULL;
}

void BSTree::increment_frequency(BSTNode *ptr)
{
    ptr->frequency++;
}

void BSTree::insert(BSTNode **p, std::string word)
{
    if(! *p)
        (*p) = new BSTNode(word);
    else{
        if((*p)->data < word)
            insert(&((*p)->right), word);
        else if((*p)->data > word)
            insert(&((*p)->left), word);
    }
    
}

void BSTree::insert(std::string word)
{
    BSTNode *p = find(root, word);

    if(p)
        increment_frequency(p);
    else
        insert(&root, word);
}

void BSTree::print_tree(BSTNode *p, int *n)
{
    if(p && *n > 0)
    {
        print_list(p->left,n);
        std::cout << p->data << " : " << p->frequency << std::endl;
        (*n)--;
        print_list(p->right,n);
    }
}

void BSTree::print_tree(int n)
{
    print_list(root, &n);
}

// add more functions here..