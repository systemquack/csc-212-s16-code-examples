#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long int ul_int;

ul_int fib_iter(ul_int n) {
    ul_int f;
    ul_int fib[] = {0, 1};

    if (n == 0 || n == 1) {
        return n;
    }

    for (int i = 2 ; i <= n ; i++ ) {
        f = fib[0] + fib[1];
        fib[0] = fib[1];
        fib[1] = f;
    }

    return f;
}

ul_int fib_rec(ul_int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    return fib_rec(n-2) + fib_rec(n-1);
}

void time_func(ul_int (*f_ptr)(ul_int), ul_int n, char *name) {
    clock_t tic = clock();
    ul_int tt = (*f_ptr)(n);
    clock_t toc = clock();

    printf("%s:\tOutput value: %ld\t%f seconds\n", name, tt, (double)(toc-tic)/CLOCKS_PER_SEC);
}

int main(int argc, char **argv) {
    // get argument from command line
    ul_int n = (ul_int) atoi(argv[1]);
    // measure time for each call
    time_func(&fib_iter, n, "Iter");
    time_func(&fib_rec, n, "Rec");
}
