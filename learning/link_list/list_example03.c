#include <stdio.h>

struct node {
    struct node *next;
    int         data;
};

int main(int argc, char *argv[]) {
    struct node node1;
    struct node node2;
    struct node node3;

    node1.data = 23;
    node1.next = &node2;
    node2.data = 11;
    node2.next = &node3;
    node3.data = 42;
    node3.next = NULL;

    struct node *head;

    head = &node1;

    printf("%d\n", head->data);                   // prints 23
    printf("%p\n", head->next);                   // prints address, e.g. 0x7fff12d793a0
    printf("%d\n", head->next->data);             // prints 11
    printf("%p\n", head->next->next);             // prints address, e.g. 0x7ffeb0b423a0
    printf("%d\n", head->next->next->data);       // prints 42
    printf("%p\n", head->next->next->next);       // prints (nil)
    //printf("%d\n", head->next->next->next->data); // invalid head->next->next->next does not refer to a struct

    return 0;
}
