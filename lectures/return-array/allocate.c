#include <stdlib.h>

/* will return an array of 'how_many' integers */
int *foo(int how_many) {
    /* create a local pointer */
    int *p;

    /* allocate memory for the array */
    p = (int *) malloc (how_many * sizeof(int));

    /* here you can write the elements of p using array notation */
    p[0] = 5;
    p[1] = 3; /* and so on ... */

    /* return the array */
    return p;
}

int main() {
    /* foo will allocate an array of size 10 */
    int *my_array = foo(10);

    /* here you can access the information in the array using array notation */
    my_array[0] += 10; /* and so on ... */

    /* before exiting the program, we need to deallocate memory */
    free(my_array);

    return 0;
}
