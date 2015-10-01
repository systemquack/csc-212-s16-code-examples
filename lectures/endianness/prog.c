#include <stdio.h>

/* prints decimal and hexadecimal representation for an integer */
void print_info(int v);

int main (int argc, char **argv) {
    int var;

    /* iterate until the value of var is 0 */
    while(1) {
        /* read an integer from the user */
        printf("Enter a number (type 0 to exit): ");
        scanf("%d", &var);
        if (! var) break;
        /* inspect contents of var */
        print_info(var);
    }

    return 0;
}

void print_info(int v) {
    /* lets create a char * that points to v
       casting will be necessary because v is an int */
    unsigned char *p = (unsigned char *) &v;

    /* print deximal and hex representation */
    printf("Decimal: %d\tHexadecimal: 0x%08X\tBytes:", v, v);
    /* ... followed by the bytes in memory */
    for (int i = 0 ; i < 4 ; i ++) {
        printf(" %02x", *(p+i));
    }
    /* new line character */
    printf("\n\n");
}
