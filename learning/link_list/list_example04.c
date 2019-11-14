#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int         data;
};

int main(int argc, char *argv[]) {
    struct node *n1;
    struct node *n2;
    struct node *n3;

    n1 = malloc(sizeof (struct node));
    n2 = malloc(sizeof (struct node));
    n3 = malloc(sizeof (struct node));

    n1->data = 23;
    n1->next = n2;
    n2->data = 11;
    n2->next = n3;
    n3->data = 42;
    n3->next = NULL;

    struct node *head;

    head = n1;

    printf("%d\n", head->data);                   // prints 23
    printf("%p\n", head->next);                   // prints address, e.g. 0x602000000050
    printf("%d\n", head->next->data);             // prints 11
    printf("%p\n", head->next->next);             // prints address, e.g. 0x602000000070
    printf("%d\n", head->next->next->data);       // prints 42
    printf("%p\n", head->next->next->next);       // prints (nil)
    //printf("%d\n", head->next->next->next->data); // invalid head->next->next->next does not refer to a struct

    return 0;
}
