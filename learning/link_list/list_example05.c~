#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int         data;
};

int main(int argc, char *argv[]) {
    struct node *head;

    head = malloc(sizeof (struct node));
    head->data = 42;
    head->next = malloc(sizeof (struct node));
    head->next->data = 23;
    head->next->next = malloc(sizeof (struct node));;
    head->next->next->data = 11;
    head->next->next->next = NULL;

    // prints 42 23 11
    struct node *p = head;
    while (p != NULL) {
        printf("%d \n", p->data);
        printf("position is: %p \n", p);
        p = p->next;
    }
    printf("\n");

    return 0;
}
