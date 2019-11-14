#include<stdio.h>
int main(void){
    int ch = getchar();
    while(ch != EOF){
        if (ch >= 'a' && ch<= 'z'){
            putchar('A'+(ch - 'a'));
        } else {
            putchar(ch);
        }
        ch = getchar();
    }
    return 0;
}
