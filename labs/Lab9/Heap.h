//
//  Heap.h
//  

#ifndef ____Heap__
#define ____Heap__

#include <stdio.h>
#include <vector>

#endif /* defined(____Heap__) */


class Heap {
private:
    std::vector<int> he;
    
    void swap(int i, int j);
    int mySize();
    
    bool isMaxHeap(int);
    
public:
    Heap();
    ~Heap();
    
    void upHeap(int i);
    void downHeap(int i);
    void insert(int element);
    int removeMax();
    void buildHeap(std::vector<int> &arr);
    
    void printAsTree();
    void printAsVector();
    bool isMaxHeap();
};
