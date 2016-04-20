#include <time.h>
#include <iostream>
#include <iterator>
#include <random>
#include <algorithm>
#include <cstring>

typedef unsigned long int ul_int;

void exchange(ul_int *x, ul_int *y) {
    // add this code
}



void qsort3(ul_int *A, int lo, int hi) {

    // add this code
}

void quicksort3(ul_int *A, ul_int n) {
    // add call to qsort3 ..
}



ul_int partition(ul_int *A, ul_int lo, ul_int hi) {
    ul_int temp, i = lo, j = hi + 1;
    while (1) {
        // while A[i] < pivot, increase i
        while (A[++i] < A[lo])
            if (i == hi) break;
        // while A[i] > pivot, decrease j
        while (A[lo] < A[--j])
            if (j == lo) break;
        // if i and j cross exit the loop
        if (i >= j) break;
        // swap A[i] and A[j]
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    // swap the pivot with A[j]
    temp = A[lo];
    A[lo] = A[j];
    A[j] = temp;
    // return pivot's position
    return j;
}

void r_quicksort(ul_int *A, ul_int lo, ul_int hi) {
    // base case
    if (hi <= lo) return;
    // partition
    ul_int p = partition(A, lo, hi);
    // recursively sort halves (also avoid negative indices)
    if (p > 0) r_quicksort(A, lo, p-1);
    r_quicksort(A, p+1, hi);
}

void quicksort(ul_int *A, ul_int n) {
    // shuffle the array
    std::random_device rng;
    std::mt19937 urng(rng());
    std::shuffle(A, A+n, urng);
    // call recursive quicksort
    r_quicksort(A, 0, n-1);
}

void merge(ul_int *A, ul_int *aux, ul_int lo, ul_int mid, ul_int hi) {
    // copy array
    std::memcpy(aux, A+lo, (hi-lo+1)*sizeof(ul_int));
    // merge
    ul_int i = lo, j = mid + 1;
    for (ul_int k = lo ; k <= hi ; k ++) {
        if (i > mid) A[k] = aux[j++];
        else if (j > hi) A[k] = aux[i++];
        else if (aux[j] < aux[i]) A[k] = aux[j++];
        else A[k] = aux[i++];
    }
}

void r_mergesort(ul_int *A, ul_int *aux, ul_int lo, ul_int hi) {
    // base case
    if (hi <= lo) return;
    // divide
    ul_int mid = (hi + lo) / 2;
    // recursively sort halves
    r_mergesort(A, aux, lo, mid);
    r_mergesort(A, aux, mid+1, hi);
    // merge results
    merge(A, aux, lo, mid, hi);
}

void mergesort(ul_int *A, ul_int n) {
    // allocate space for aux
    ul_int *aux = new ul_int[n];
    // call recursive mergesort
    r_mergesort(A, aux, 0, n-1);
    // free memory
    delete [] aux;
}

void bubblesort(ul_int *A, ul_int n) {
    ul_int temp, i, j;
    // pass through the array n-1 times
    for (i = 0 ; i < (n-1) ; i ++) {
        // check for out-of-order pairs in the 'unsorted' half
        for (j = 0 ; j < (n-i-1) ; j ++) {
            // if A[j] and A[j+1] are out-of-order, swap them
            if (A[j] > A[j+1]) {
                temp = A[j+1];
                A[j+1] = A[j];
                A[j] = temp;
            }
        }
    }
}

void insertionsort(ul_int *A, ul_int n) {
    ul_int temp, i, j;
    // grows the left part (sorted)
    for (i = 0 ; i < n ; i ++) {
        temp = A[i];
        // inserts A[j] into the right place in sorted part
        for (j = i ; j > 0 && A[j-1] > temp ; j --) {
            A[j] = A[j-1];
        }
        A[j] = temp;
    }
}

void selectionsort(ul_int *A, ul_int n) {
    ul_int i, j, min, temp;
    // grows the left part (sorted)
    for (i = 0 ; i < n ; i ++) {
        min = i;
        // find min in unsorted part
        for (j = i+1 ; j < n ; j ++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        // swap A[i] and A[min]
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
}

void time_func(void (*f_ptr)(ul_int *, ul_int), ul_int *array, ul_int n, const char *name) {
    clock_t tic = clock();
    (*f_ptr)(array, n);
    clock_t toc = clock();

    printf("%s:\t%f seconds\n", name, (double)(toc-tic)/CLOCKS_PER_SEC);
}

int is_sorted(ul_int *A, ul_int n) {
    for (ul_int i = 1 ; i < n ; i ++)
        if (A[i] < A[i-1])
            return 0;
    return 1;
}

int main() {
    const int n_algo = 6;
    // array of function names
    const char * fun_names[n_algo] = {"QuickSort", "MergeSort", "QuickSort3", "InsertionSort", "SelectionSort", "BubbleSort"};
    // array of pointers to functions
    void (*fun_ptrs[n_algo])(ul_int *, ul_int) = {&quicksort, &mergesort, &quicksort3, &insertionsort, &selectionsort, &bubblesort};

    std::cout << "Reading input sequence ...\n";

    // read first number
    ul_int n, i;
    std::cin >> n;

    // allocate space for arrays
    ul_int *array = new ul_int[n];
    ul_int *arr_copy = new ul_int[n];

    // read the sequence
    for (i = 0 ; i < n ; i++) {
        std::cin >> array[i];
    }

    std::cout << "Applying sorting algorithms ...\n";
    for (int i = 0 ; i < n_algo ; i ++) {
        // make a copy
        std::memcpy(arr_copy, array, n*sizeof(ul_int));
        // apply algorithm and measure time
        time_func(fun_ptrs[i], arr_copy, n, fun_names[i]);
        // check correctness
        if (! is_sorted(arr_copy,n)) std::cout << "Incorrect !!!\n";
    }

    // free memory
    delete [] array;
    delete [] arr_copy;
}
