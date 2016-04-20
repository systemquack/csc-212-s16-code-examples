#ifndef __DYN_ARRAY_H__
#define __DYN_ARRAY_H__

typedef unsigned long int ul_int;

class DynArray {
    private:
        int n_resizes; // keeps track of how many times the array grows
        ul_int *data; // pointer to the actual array
        ul_int size; // number of elements currently using the array
        ul_int capacity; // maximum number of elements
        float rate; // growth rate

        // auxiliary function for initializing data
        void Initialize(ul_int c, float r);

    public:
        // constructor -- needs capacity and uses default rate
        DynArray(ul_int c);
        // constructor -- needs capacity and rate
        DynArray(ul_int c, float r);
        // destructor -- frees memory
        ~DynArray();
        // appends a new element to the end of the array
        void append(ul_int elem);
        // returns the current size
        ul_int get_size(void);
        // returns the current capacity
        ul_int get_capacity(void);
        // returns the current rate
        float get_rate(void);
        // returns the current capacity
        int get_n_resizes(void);
        // returns the element at position i
        ul_int get(ul_int i);
};
        
#endif
