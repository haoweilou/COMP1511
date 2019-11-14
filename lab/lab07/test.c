#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int sum = 0;
    int argument = 1;
    while (argument < argc) {
        sum = sum + atoi(argv[argument]);
        argument= argument + 1;
    }
    printf("sum of command-line arguments = %d\n", sum);

    return 0;
}
