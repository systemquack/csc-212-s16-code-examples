//
//  main.cpp
//  heap
//

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "heap.h"

void fillVector(std::vector<int> &array, int n) {
    srand((int) time(NULL));
    // just to test, insert N random items into the vector
    for (int i = 0 ; i < n ; i++) {
        array.push_back((rand() % (2*n)) + 1);
    }
}

int main(int argc, const char * argv[]) {
    // create a random array with n elements
    std::vector<int> array;
    fillVector(array, 16);

    Heap my_heap(100);
    my_heap.buildHeap(array);
    my_heap.printAsTree();

    std::string ans = (my_heap.isMaxHeap()) ? " " : " not ";
    std::cout << "This is" << ans << "a Max-Heap." << std::endl;

    return 0;
}
