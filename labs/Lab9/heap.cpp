//
//  Heap.cpp
//  

#include "Heap.h"
#include <iostream>

Heap::Heap() {
    he.insert(he.begin(), -12345); // insert first dummy element
};

Heap::~Heap() {};

int Heap::mySize() {
    return (int) he.size() - 1;
}

void Heap::swap(int i, int j)
{
    // swap these two indices in our heap
    int temp = he[i];
    he[i] = he[j];
    he[j] = temp;
}// end swap
    
void Heap::upHeap(int p)
{
    // starting with index p, compare with the parent of p
    //  and swap if the parent is smaller.
    // Continue until we get to the root (or stop swapping).


}// end upHeap

void Heap::downHeap(int p)
{
    // starting with index p, compare with the children of p
    //  and if they are bigger, swap with the larger child.
    // Continue until we are at the end of the heap (he.mySize() )


}// end downHeap

void Heap::insert(int element)
{
    // to insert an element, simply add it to the end of the vector, and call UpHeap on that index..


} // end insert

int Heap::removeMax()
{
    // save the first element.

    
    // copy the last element into the first spot.

    
    // reduce the size of the vector by 1. (erase last position)

    
    // call downheap on the first element.

    
    // return the saved element

    
} // end removeMax

void Heap::buildHeap(std::vector<int> & arr)
{
    he = arr; // DEEP COPY
    he.insert(he.begin(), -12345); // Ignore first value always
    
    // for Build Heap, start at last internal node and go backwards

    
    
}// end buildHeap

void Heap::printAsTree()
{
    // print out the contents of the heap, with each
    //  row being a level of the "tree" visualization
    for(int i = 1; i <= mySize(); i++)
    {
        std::cout << he[i] << " ";
        // if i + 1 is a power of 2, then we are at the end of a row
        if( !(i+1 & (i)) )
        {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    
}// end printAsTree

void Heap::printAsVector()
{
    // print out the contents of the heap, just as
    //  a simple vector
    
    for(int i = 1; i <= mySize(); i++)
    {
        std::cout << he[i] << " ";
    }
    std::cout << std::endl;
    
}// end printAsVector

bool Heap::isMaxHeap()
{
    // test to see if the heap is a max heap
    return isMaxHeap(1);
    
}

bool Heap::isMaxHeap(int k)
{
    // is subtree rooted at k a max heap?
    
    if (k > mySize()) return true;
    int left = 2*k;
    int right = 2*k+1;
    if(left <= mySize() && he[k] < he[left]) return false;  // this node is smaller than it's child, so
    if(right <= mySize() && he[k] < he[right]) return false;//  this is not a max heap.
    return isMaxHeap(left) && isMaxHeap(right);
}