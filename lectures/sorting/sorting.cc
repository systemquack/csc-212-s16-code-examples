#include <time.h>
#include <iostream>
#include <iterator>

typedef unsigned long int ul_int;

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
    std::cout << "Reading input sequence ...\n";

    // read first number
    ul_int n, i;
    std::cin >> n;

    // allocate space for array
    ul_int *array = new ul_int[n];
    ul_int *arr_copy = new ul_int[n];

    // read the sequence
    for (i = 0 ; i < n ; i++)
        std::cin >> array[i];

    std::cout << "Applying sorting algorithms ...\n";

    // make a copy, measure time for call, check correctness
    std::copy(array, array+n, arr_copy);
    time_func(&mergesort, arr_copy, n, "MergeSrt");
    if (! is_sorted(arr_copy,n)) std::cout << "Incorrect !!!\n";

    // make a copy, measure time for call, check correctness
    std::copy(array, array+n, arr_copy);
    time_func(&insertionsort, arr_copy, n, "InsertSrt");
    if (! is_sorted(arr_copy,n)) std::cout << "Incorrect !!!\n";

    // make a copy, measure time for call, check correctness
    std::copy(array, array+n, arr_copy);
    time_func(&selectionsort, arr_copy, n, "SelectSrt");
    if (! is_sorted(arr_copy,n)) std::cout << "Incorrect !!!\n";

    // make a copy, measure time for call, check correctness
    std::copy(array, array+n, arr_copy);
    time_func(&bubblesort, arr_copy, n, "BubbleSrt");
    if (! is_sorted(arr_copy,n)) std::cout << "Incorrect !!!\n";

    // free memory
    delete [] array;
    delete [] arr_copy;
}
