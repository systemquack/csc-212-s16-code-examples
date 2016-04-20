#include "bintree.h"

#include <iostream>

BSTree::BSTree() {
    root = NULL;
}

BSTree::~BSTree() {
    destroy(root);
}

void BSTree::destroy(BSTNode *p) {
    if (p) {
        destroy(p->left);
        destroy(p->right);
        delete p;
    }
}

// it will IGNORE repeated values
void BSTree::insert(BSTNode **p, int d) {
    if (! *p) {
        // insert node here
        (*p) = new BSTNode(d);
    } else {
        // call recursively
        if ((*p)->data < d) insert(&((*p)->right), d);
        else if ((*p)->data > d) insert(&((*p)->left), d);
    }
}

void BSTree::insert(int d) {
    insert(&root, d);
}

bool BSTree::remove(int d) {
    return false;
}

BSTNode *BSTree::search(BSTNode *p, int d) {
    if (p) { 
        if (p->data == d) return p;
        else if (p->data < d) return search(p->right, d);
        else return search(p->left, d);
    }
    return NULL;
}

BSTNode *BSTree::search(int d) {
    return search(root, d);
}

void BSTree::preorder(BSTNode *p) {
    if (p) {
        std::cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

void BSTree::inorder(BSTNode *p) {
    if (p) {
        inorder(p->left);
        std::cout << p->data << " ";
        inorder(p->right);
    }
}

void BSTree::postorder(BSTNode *p) {
    if (p) {
        postorder(p->left);
        postorder(p->right);
        std::cout << p->data << " ";
    }
}

void BSTree::traversal(int type) {
    switch (type) {
        case PREORDER:
            std::cout << "Preorder: ";
            preorder(root);
            break;
        case INORDER:
            std::cout << "Inorder: ";
            inorder(root);
            break;
        case POSTORDER:
            std::cout << "Postorder: ";
            postorder(root);
            break;
    }    
    std::cout << std::endl;
}

// FB Int. q. ==> Find min depth of BST
