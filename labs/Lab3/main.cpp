#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "dyn-array.h"

void time_func(DynArray *ptr, ul_int n) {
    clock_t tic = clock();
    for (ul_int i = 0 ; i < n ; i++) {
        ptr->append(i);
    }
    clock_t toc = clock();

    printf("Capacity: %ld\tSize: %ld\tRate: %.4f\t# resizes: %d\t%f seconds\n", ptr->get_capacity(), ptr->get_size(), ptr->get_rate(), ptr->get_n_resizes(), (double)(toc-tic)/CLOCKS_PER_SEC);
}

int main(int argc, char **argv) {
//  DynArray array_1(??);

    // get argument from command line (how many consecutive appends?)
    ul_int n = atoi(argv[1]);

    // measure time for each call
    time_func(&array_1, n);

    return 0;
}

