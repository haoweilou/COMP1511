// COMP1511 Week 5 Lab: Array Maximum
//
// This program was written by Haowei Lou (z5258575)
// on 17 Mar 2019
//
// This program calculates the maximum value in an array of integers.
//

#include <stdio.h>

int array_maximum(int size, int array[size]) {

    int max = 0;
    int i=0;
    int j=0;
    while(i<size){
        if(max<array[i]){//store the array[i] when it is biggest                                                              //overwrite it
            max=array[i];
        }
        i=i+1;
    }
    return max;
}

#define MAX_SIZE 100

int main(void) {
    int size1 = 7;
    int array1[MAX_SIZE] = {3, 14, 15, 9, 2, 6, 5};

    int result1 = array_maximum(size1, array1);
    printf("The largest value from array1 is: %d\n", result1);

    int size2 = 10;
    int array2[MAX_SIZE] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

    int result2 = array_maximum(size2, array2);
    printf("The largest value from array2 is: %d\n", result2);
    
    int size3 = 1;
    int array3[MAX_SIZE] = {11};

    int result3 = array_maximum(size3, array3);
    printf("The largest value from array2 is: %d\n", result3);

    // Note: you can add more tests here (but they won't be marked).

    return 0;
}
