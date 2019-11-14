#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int          data;
};

int main(int argc, char *argv[]) {
    struct node node1;
    struct node *a;

    // printf("%d\n", a->data); // would be invalid - a is uninitialized

    a = NULL;

    //printf("%d\n", a->data); // invalid - a doesn't refer to a struct node
    printf("%p\n", a);       // prints (nil)

    a = &node1;

    //printf("%d\n", a->data); // invalid - node1.data is uninitialized
    printf("%p\n", a);       // prints address, e.g 0x7ffc18faa5c0

    node1.data = 42;
    node1.next = &node1;

    printf("%d\n", a->data); // prints 42
    printf("%p\n", a->next); // prints (nil)

    a->data = 13;

    printf("%d\n", a->data); // prints 13
    printf("%d\n", node1.data);  // prints 13

    return 0;
}
