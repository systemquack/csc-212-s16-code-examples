//
//  main.cpp
//  heap
//

#include <iostream>
#include <cstdlib>
#include <time.h>
#include “heap.h"

void fillVector(std::vector<int> &array, int n)
{
    srand((int) time(NULL));
    // just to test, insert some items into the vector
    for (int i = 0; i < n; i++)
    {
        array.push_back(rand() % 100 + 1); // put numbers between 1 - 100
    }
}


int main(int argc, const char * argv[]) {
    // create a random array with n elements
    std::vector<int> array;
    fillVector(array, 16);
    
    // first declare a heap
    Heap myHeap;
    myHeap.buildHeap(array);
    
    myHeap.printAsTree(); // show them
    
    std::string ans = (myHeap.isMaxHeap())?" ":" not ";
    std::cout << "This is" << ans << "a Max Heap." << std::endl;
    
    return 0;
}
