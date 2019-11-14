//Haowei Lou
//z5258575
//12 April 2019

#include<stdio.h>
int count_even(int length, int array[length]){
    int i = 0,num = 0;
    while(i < length){
        if(array[i] % 2 == 0){
            num++;
        }
        i++;
    }
    return num;
}

int main(void){
    int array[8] = {1,2,3,4,6,7,8,9};
    int length = 8;
    int count = count_even(length, array);
    printf("Even number is %d\n",count);
    return 0;
}
