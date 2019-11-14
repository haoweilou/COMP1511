//Haowei Lou
//z5258575
//12 April 2019
#include<stdio.h>
#define MAX 1000
int remove_duplicates(int length, int source[length], int destination[length]){
    int i = 0, j = 0, k = 0, num_of_des = 0, rep = 0;
    while(i < length){
        j = 0, rep = 0;
        while(j < num_of_des){
            if(destination[j] == source[i]){
                rep = 1;
                j = num_of_des;
            }
            j = j + 1;
        }
        if(rep == 0){
            destination[k] = source[i];
            k++;
            num_of_des = k;
        }
        i = i + 1;
    }
    return num_of_des;
}

int main(void){
    int array[8] = {1,2,3,4,6,7,9,9};
    int length = 8;
    int destination[MAX]={0};
    int count = remove_duplicates(length, array, destination);
    int i = 0;
    while(i < count){
        printf("source[%d] is %d\n", i, destination[i]);
        i++;
    }
    return 0;
}
