//Haowei Lou
//z5258575
//08 April 2019
#include<stdio.h>
#include <stdlib.h>
#define MAX 4096
int palindrome(char character[MAX],int num_of_cha){
    int i = 0, j = num_of_cha - 1;
    int p = 1;
    while(i<num_of_cha){
        if(character[i] != character[j - i]){
            p = 0;
            i = num_of_cha;
        }
        i++;
    }
    
    return p;
}
int main(){
    int p = 0;
    char input[MAX]={0};
    int number_of_input=0;
    printf("Enter a string: ");
    int i = 0;
    fgets(input, MAX, stdin);
    while(input[i] != '\n' && input[i] != '\0'){
        i++;
    }

    p = palindrome(input, i);

    if(p == 1){
        printf("String is a palindrome\n");
    }else{
        printf("String is not a palindrome\n");        
    }
    return 0;
}
