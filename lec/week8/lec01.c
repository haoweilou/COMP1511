#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *next;
    int         data;
};

void print_nodes(struct node *head){
    struct node *p;
    
    p = head;
    while(p != NULL){
        printf("%d,", p->data);
        p = p->next;
    }
    printf("%p",p);
    printf("\n");
}
int main(int argc, char *argv[]){
    struct node s1,s2,s3,s4;
    struct node *a = malloc(sizeof (struct node));
    struct node *b = malloc(sizeof (struct node));
    struct node *c = malloc(sizeof (struct node));
    struct node *d = malloc(sizeof (struct node));
    
    a->data = 1;
    a->next = NULL;
    b->data = 42;
    b->next = a;
    c->data = 3;
    c->next = b;
    d->data = 11;
    d->next = c;
    c = a;
    c->data = 5000;
    /*printf("d->next->data=%d\n", d->next->data);
    printf("a=%p &(a->data)=%p a->data=%d a->next=%p\n", a, &(a->data), a->data, a->next);
    printf("b=%p b->data=%d b->next=%p\n", b, b->data, b->next);
    printf("c=%p c->data=%d c->next=%p\n", c, c->data, c->next);
    printf("d=%p d->data=%d d->next=%p\n", d, d->data, d->next);*/
    print_nodes(d);

}
