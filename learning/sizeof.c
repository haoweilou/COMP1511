#include <stdio.h>

int main(void) {

    printf("sizeof (char) = %d\n", (int)sizeof (char));
    printf("sizeof (int) = %d\n", (int)sizeof (int));
    printf("sizeof (double) = %d\n", (int)sizeof (double));
    printf("sizeof int[10] = %d\n", (int)sizeof (int[10]));
    printf("sizeof int * = %d\n", (int)sizeof (int *));
    printf("sizeof \"hello\" = %d\n", (int)sizeof "hello");

    return 0;
}
