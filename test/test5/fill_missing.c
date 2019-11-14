//Haowei Lou
//z5258575
//04 April 2019
#include<stdio.h>
#define MAX 10000
int main(void){
    int i=0;
    int input[MAX]={0},number_of_input=0;
    while(scanf("%d",&input[i])!=EOF){
        i++;
        number_of_input = i;
    }
    i=0;
    int max=0;
    while(i<number_of_input){
        if(input[i]>max){
            max=input[i];
        }
        i++;
    }
    int possible[MAX]={0},num_of_possible=0,a=0;
    possible[0]=1;
    i = 1;
    while(a<max){
        possible[i] = possible[i-1]+1;
        a = possible[i];
        i = i + 1;
        num_of_possible = i;
    }
    i = 0;
    int j=0,output[MAX]={0},repeat=0,k=0,num_of_output=0;
    while(i<num_of_possible){
        repeat=0;
        j=0;
        while(j<number_of_input){
            if(possible[i]==input[j]){
                repeat = 1;
                j = number_of_input;
            }
            j++;
        }
        if(repeat==0){
            output[k] = possible[i];
            k = k + 1;
            num_of_output = k;
        }
        i++;
    }
    i=0;
    while(i < num_of_output){
        printf("%d ", output[i]);
        i++;
    }printf("\n");
    return 0;
}
