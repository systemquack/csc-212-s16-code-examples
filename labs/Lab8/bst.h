//
//  bst.h
//

#ifndef bst_h
#define bst_h

#ifndef NULL
#define NULL 0x00
#endif


#include <string>

class BSTNode {
private:
    
    std::string data;
    int frequency;
    
    BSTNode *left;
    BSTNode *right;
    
public:
    
    BSTNode(std::string d) { data = d; frequency = 1; left = NULL; right = NULL; }
    ~BSTNode() {}

    friend class BSTree;
};


class BSTree {
private:
    
    BSTNode *root;

    void destroy(BSTNode*);
    
    BSTNode* find(BSTNode*, std::string);

    void increment_frequency(BSTNode *ptr);
    
    void insert(BSTNode**, std::string);
    
    void print_tree(BSTNode*, int*);
    
    void print_range(std::string, std::string, BSTNode*);

    
public:
    
    BSTree();
    ~BSTree();
    
    void insert(std::string);
    
    void print_tree(int n);
    
    void print_range(std::string, std::string); // output all the strings in the tree lexically between the parameters
};


#endif
