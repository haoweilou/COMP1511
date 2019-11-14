#include <stdio.h>
#include <stdlib.h>

/*
$ dcc list_intro.c
$ ./a.out
a=0xf5500710 a->data=27 a->next=0xf55006f0
b=0xf55006f0 b->data=12 b->next=0xf55006d0
c=0xf55006d0 c->data=32 c->next=0xf55006b0
d=0xf55006b0 d->data=42 d->next=(nil)

p=0xf5500710 p->data=27 p->next=0xf55006f0
p=0xf55006f0 p->data=12 p->next=0xf55006d0
p=0xf55006d0 p->data=32 p->next=0xf55006b0
p=0xf55006b0 p->data=42 p->next=(nil)

113
*/

struct node {
    struct node *next;
    int          data;
};

int sum_list(struct node *head);

int main(int argc, char *argv[]) {
    struct node *a = malloc(sizeof (struct node));
    struct node *b = malloc(sizeof (struct node));
    struct node *c = malloc(sizeof (struct node));
    struct node *d = malloc(sizeof (struct node));

    a->data = 27;
    b->data = 12;
    c->data = 32;
    d->data = 42;

    a->next = b;
    b->next = c;
    c->next = d;
    d->next= NULL;

    printf("a=%p a->data=%d a->next=%p\n", a, a->data, a->next);
    printf("b=%p b->data=%d b->next=%p\n", b, b->data, b->next);
    printf("c=%p c->data=%d c->next=%p\n", c, c->data, c->next);
    printf("d=%p d->data=%d d->next=%p\n", d, d->data, d->next);

    int sum = sum_list(a);
    printf("%d\n", sum);
}

int sum_list(struct node *head) {
    struct node *p = head;
    int total = 0;
    while (p != NULL) {
        printf("p=%p p->data=%d p->next=%p\n", p, p->data, p->next);
        total = total + p->data;
        p = p->next;
    }
    return total;
}
