//Haowei Lou
//z5258575
//02 April 2019
#include<stdio.h>
#include <stdlib.h>
#define NUM_OF_LETTER 26
int decode(int character, char code[NUM_OF_LETTER]){
    int i=0;
    if(character >= 'a' && character <= 'z'){
        while(i<26){
            if(character == code[i]){
                character = 'a' + i;
                i=26;
            }
            i++;
        } 
    }else if(character >= 'A' && character <= 'Z'){
        while(i<26){
            if(character == code[i] - ('a' - 'A')){
                character = 'A' + i;
                i=26;
            }
            i++;
        }
    }
    return character;
    
}
int main(int argc, char *argv[]){
    int ch=getchar();
    char *code=argv[1];
    
    while(ch != EOF){
        int new=decode(ch,code);
        ch=getchar();
        putchar(new);
    }
    
    return 0;
}
