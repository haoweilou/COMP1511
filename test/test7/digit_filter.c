//Haowei Lou
//z5258575
//21 April 2019
#include<stdio.h>
int main(void){
    int ch = getchar();
    while(ch != EOF){
        if((ch >= '0' && ch <= '9') || ch == ' ' || ch == '\n'){
            putchar(ch);
        }else{
            putchar('.');
        }
        ch = getchar();
    }
    return 0;
}
