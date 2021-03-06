#include <stdio.h>

struct node {
    struct node *next;
    int           data;
};

int main(int argc, char *argv[]) {
    struct node node1;

    // printf("%d\n", node1.data); // would be invalid - s.data is uninitialized

    node1.data = 7;
    node1.next = NULL;

    printf("%d\n", node1.data); // prints 7
    printf("%p\n", node1.next); // prints (nil)

    return 0;
}
