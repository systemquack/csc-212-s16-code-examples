//
// Implementation of DynArray Class
//
//  CSC212  Lab #3
//

#include "dyn-array.h"
#include <stdio.h>
// both constructors assume that capacity is greater than zero
// you can also catch exceptions for allocation errors
DynArray::DynArray(ul_int cap) {
    Initialize(cap, 1.5);
}

DynArray::DynArray(ul_int c, float r) {
    Initialize(c, r);
}

void DynArray::Initialize(ul_int c, float r) {
    size = 0;
    n_resizes = 0;
    capacity = c;
    rate = r;
    data = new ul_int[c];
}

//
// Destructor
//
DynArray::~DynArray() {
    delete [] data;
}

//
// makes an insertion at the end of the array
//
void DynArray::append(ul_int elem) {

// check if the array needs to grow
    if (size == capacity) {
// calculate new capacity
        capacity = size*rate;
// allocate space for new array
        ul_int* temp = new ul_int[capacity];
// copy all elements
        for (ul_int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
// delete old array
    delete[] data;
// point old pointer to new array
    data = temp;

    }
// make the insertion
    data[size++] = elem;
}

ul_int DynArray::get_size() {
    return size;
}

ul_int DynArray::get_capacity() {
    return capacity;
}

int DynArray::get_n_resizes() {
    return n_resizes;
}

float DynArray::get_rate() {
    return rate;
}

// not checking for out-of-bounds here but ... could
// throw exceptions in such a case
ul_int DynArray::get(ul_int i) {
    return data[i];
}
