//
// Implementation of DynArray Class
//
//  CSC212  Lab #3
//

#include "dyn-array.h"

// both constructors assume that capacity is greater than zero
// you can also catch exceptions for allocation errors
DynArray::DynArray(ul_int cap) {
    Initialize(cap, 0.1);
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



        // calculate new capacity


        // allocate space for new array

        // copy all elements


        // delete old array



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
