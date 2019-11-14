#include <stdio.h>

int f(int j) {
    static int x;
    x = x + j;
    return x;
}
int main(void) {
    printf("%d\n", f(1)); // prints 1
    printf("%d\n", f(2)); // prints 3
    printf("%d\n", f(4)); // prints 7
    return 0;
}
