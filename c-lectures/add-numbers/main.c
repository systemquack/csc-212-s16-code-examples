#include <stdio.h>
#include "sum.h"

int main(int argv, char **args) {
    int k = do_sum(10, 20);

    printf("output: %d\n", k);

    return 0;
}
