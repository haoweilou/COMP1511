//Haowei Lou
//z5258575
//01 April 2019
#include<stdio.h>
#include <stdlib.h>

int caesar(int character, int shift){
    if(character >= 65 && character <= 90){
        int difference_with_90=0;
        difference_with_90 = ((character + shift)-90)%26;
        if(difference_with_90<=0){
            character= 90 + difference_with_90;
        }else{
            character = 64+difference_with_90;
        }                                     
    }else if(character >= 97 && character <= 122){
        int difference_with_122=0;
        difference_with_122 = ((character + shift)-122)%26;
        if(difference_with_122<=0){
            character= 122 + difference_with_122;
        }else{
            character = 96 + difference_with_122;
        }
    }
    return character;
}

int main(int argc, char *argv[]){
    int ch=getchar();
    int shift=0;
    shift=shift+atoi(argv[1]);
    while(ch != EOF){
        int new=caesar(ch,shift);
        putchar(new);
        
        ch=getchar();
    }
    return 0;
}

