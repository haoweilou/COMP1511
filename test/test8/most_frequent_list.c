//Haowei Lou
//z5258575
//25 April 2019
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int most_frequent(struct node *head);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    int result = most_frequent(head);
    printf("%d\n", result);

    return 0;
}


// return the value which occurs most frequently in a linked list
// if several values are equally most frequent
// the value that occurs earliest in the list is returned
int most_frequent(struct node *head) {

    // PUT YOUR CODE HERE (change the next line!)
    int most_frequent_number = 0;
    int frequency = 0;
    struct node *temp = head;
    while(temp != NULL){
        struct node *temp_2 = head;
        int temp_most_frequent = 0, temp_frequency = 0;
        while(temp_2 != NULL){
            if(temp -> data == temp_2 -> data){
                temp_most_frequent = temp -> data;
                temp_frequency++;
            }
            temp_2 = temp_2 -> next;
        }
        if(temp_frequency > frequency){
            frequency = temp_frequency;
            most_frequent_number = temp_most_frequent;
        }
        temp = temp -> next;
    }
    return most_frequent_number;

}


// DO NOT CHANGE THIS FUNCTION

// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}
