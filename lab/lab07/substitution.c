//Haowei Lou
//z5258575
//02 April 2019
#include<stdio.h>
#include <stdlib.h>
#define NUM_OF_LETTER 26
int substitution(int character, char code[NUM_OF_LETTER]){
    if(character >= 'a' && character <= 'z'){
        character = code[character- 'a']; 
    }else if(character >= 'A' && character <= 'Z'){
        character = code[character- 'A']-('a'-'A');
    }
    return character;
    
}
int main(int argc, char *argv[]){
    int ch=getchar();
    char *code=argv[1];
    
    while(ch != EOF){
        int new=substitution(ch,code);
        ch=getchar();
        putchar(new);
    }
    
    return 0;
}
