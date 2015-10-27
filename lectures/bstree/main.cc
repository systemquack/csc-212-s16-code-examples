#include "bintree.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

int main() {
    int key;
    BSTree mytree;

    // use current time as seed
    std::srand(std::time(0));

    // insert 20 random numbers
    for (int i = 0 ; i < 20 ; i ++) {
        key = std::rand() % 100 + 1;
        std::cout << "Insert: " << key << std::endl;
        mytree.insert(key);
        mytree.traversal(PREORDER);
        mytree.traversal(INORDER);
        mytree.traversal(POSTORDER);
        std::cout << std::endl;
    }

    return 0;
}
