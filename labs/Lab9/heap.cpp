//
//  heap.cpp
//

#include "heap.h"
#include <iostream>
#include <cassert>

Heap::Heap(int cap) {
    array = new int [cap];
    n_elems = 0;
    capacity = cap;
}

Heap::~Heap() {
    delete [] array;
}

void Heap::swap(int i, int j) {
    // indices must be valid
    assert(i > 0 && i < capacity);
    assert(j > 0 && j < capacity);
    // swap these two indices in our heap
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}// end swap

bool Heap::isFull() {
    // this comparison also considers the dummy element array[0]
    return (capacity - n_elems) < 2;
}

void Heap::upHeap(int p) {
    // starting with index p, compare with the parent of p
    //  and swap if the parent is smaller.
    // Continue until we get to the root (or stop swapping).
}// end upHeap

void Heap::downHeap(int p) {
    // starting with index p, compare with the children of p
    //  and if they are bigger, swap with the larger child.
    // Continue until we are at the end of the heap (he.mySize() )
}// end downHeap

void Heap::insert(int element) {
    assert(!isFull());
    // to insert an element, simply add it to the end of the vector,
    // and call UpHeap on that index.
}// end insert

int Heap::removeMax() {
    // save the first element.

    // copy the last element into the first spot.

    // reduce the size of the vector by 1. (erase last position)

    // call downheap on the first element.

    // return the saved element
    return -1;
} // end removeMax

void Heap::buildHeap(std::vector<int> & arr) {
    // delete previous array and copy all elements from arr to a new array
    delete [] array;
    n_elems = arr.size();
    capacity = n_elems + 1;
    array = new int[capacity];
    for (int i = 0 ; i < n_elems ; i ++) {
        array[i+1] = arr[i];
    }
    // buildHeap, start at last internal node and go backwards
}// end buildHeap

void Heap::printAsTree() {
    // print out the contents of the heap, with each
    //  row being a level of the "tree" visualization
    for(int i = 1 ; i <= n_elems ; i++) {
        std::cout << array[i] << " ";
        // if i + 1 is a power of 2, then we are at the end of a row
        if( !(i+1 & (i)) ) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}// end printAsTree

void Heap::printAsVector() {
    // print out the contents of the heap, just as
    //  a simple vector
    for(int i = 1 ; i <= n_elems ; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}// end printAsVector

bool Heap::isMaxHeap() {
    // test to see if the heap is a max heap
    return isMaxHeap(1);
}

bool Heap::isMaxHeap(int p) {
    if (p > n_elems) {
        return true;
    }
    int l = 2 * p;
    int r = l + 1;
    if (l <= n_elems && array[p] < array[l]) {
        // this node is smaller than it's left child
        return false;
    }
    if (r <= n_elems && array[p] < array[r]) {
        // this node is smaller than it's right child
        return false;
    }
    // let recursion take care of the rest
    // (if I am a heap my children must be heaps as well)
    return isMaxHeap(l) && isMaxHeap(r);
}
