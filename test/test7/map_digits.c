//Haowei Lou
//z5258575
//21 April 2019
#include<stdio.h>
#define MAX_LENGTH 10
int digit_function(int input, char code[MAX_LENGTH]){
    if('0' <= input && '9' >= input){
        input = code[input - '0'];
    }
    return input;
}


int main(int argc, char *argv[]){
    int ch = getchar();
    char *swap = argv[1];
    while(ch != EOF){
        ch = digit_function(ch,swap);
        putchar(ch);
        ch = getchar();
    }
    return 0;
}

