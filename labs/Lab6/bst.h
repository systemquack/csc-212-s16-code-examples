//
//  bst.h
//

#ifndef bst_h
#define bst_h

#include <stddef.h>
#include <string>

class BSTNode {
private:
    
    std::string data;
    
    BSTNode* left;
    BSTNode* right;
    
public:
    
    BSTNode(std::string d) { data = d; left = NULL; right = NULL; }
    ~BSTNode() {}

    friend class BSTree;
};


class BSTree {
private:
    
    BSTNode* root;

    void destroy(BSTNode*);
    
public:
    
    BSTree();
    ~BSTree();
    
    void insert(std::string);
    bool find(std::string);
};


#endif
