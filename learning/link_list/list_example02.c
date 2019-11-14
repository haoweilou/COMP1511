#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int         data;
};

int main(int argc, char *argv[]) {
    struct node *a;

    // printf("%d\n", a->data); // would be invalid - a is uninitialized

    a = NULL;

    //printf("%d\n", a->data); // invalid - a doesn't refer to a struct node
    printf("%p\n", a);       // prints (nil)

    a = malloc(sizeof (struct node));
    printf("size of a is %lu\n",sizeof(a));

    //printf("%d\n", a->data); // invalid - a->data is uninitialized
    printf("%p\n", a);       // prints address, e.g 0x7ffc18faa5c0

    a->data = 42;
    a->next = a;

    printf("%d\n", a->data); // prints 42
    printf("%p\n", a->next); // prints (nil)

    return 0;
}
