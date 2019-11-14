//Haowei Lou
//z5258575
//08 April 2019
#include<stdio.h>
#define MAX 4096

int main(){
    printf("Enter a string: ");
    int ch = getchar();
    while(ch != '\n' ){
        putchar(ch);
        printf("\n");
        ch=getchar();  
    }
    return 0;
}
