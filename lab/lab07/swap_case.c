//Haowei Lou
//z5258575
//01 April 2019
#include<stdio.h>
int swap(int character){
    if(character>=65 && character<=90){
        character = character + 32;
    }else if(character>=97 && character<=122){
        character = character - 32;
    }
    return character;
}
int main(void){
    int ch=getchar();
    while(ch!=EOF){
        int change=swap(ch);
        putchar(change);
        
        ch=getchar();
    }
    return 0;
}

