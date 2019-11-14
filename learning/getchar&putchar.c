#include<stdio.h>
int main(){
    int ch = 0;
    while(ch != EOF){
        putchar(ch);
        ch = getchar();
    }
    return 0;
}
