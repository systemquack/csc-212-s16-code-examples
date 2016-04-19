//
//  Heap.h
//

#ifndef __HEAP__
#define __HEAP__

#include <vector>

class Heap {
    private:
        // array[0] will be ignored
        int *array;
        // number of elements in the Heap
        // does not count the dummy element at array[0]
        int n_elems;
        // capacity of 'array'
        // an array is full when (n_elem == capacity+1)
        int capacity;

        void swap(int i, int j);
        bool isMaxHeap(int i);
        void upHeap(int i);
        void downHeap(int i);

    public:
        Heap(int cap);
        ~Heap();

        void insert(int element);
        int removeMax();
        void buildHeap(std::vector<int> &arr);

        void printAsTree();
        void printAsVector();
        bool isMaxHeap();
        bool isFull();
};

#endif
