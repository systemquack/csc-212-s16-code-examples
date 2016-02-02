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
    DynArray array_1(20, 1.0); // grows 100% every time it reaches full capacity
    DynArray array_2(20, 0.75); // grows 75% every time it reaches full capacity
    DynArray array_3(20, 0.5); // grows 50% every time it reaches full capacity
    DynArray array_4(20, 0.25); // grows 25% every time it reaches full capacity
    DynArray array_5(20, 0.0);  // grows 1 element every time it reaches full capacity
    // get argument from command line (how many consecutive appends?)
    ul_int n = atoi(argv[1]);
    // measure time for each call
    time_func(&array_1, n);
    time_func(&array_2, n);
    time_func(&array_3, n);
    time_func(&array_4, n);
    time_func(&array_5, n);

    return 0;
}

