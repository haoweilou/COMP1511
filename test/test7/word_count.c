//Haowei Lou
//z5258575
//21 April 2019
#include<stdio.h>
#define MAX_LENGTH 100000
int main(void){
    int ch = getchar();
    //int next = getchar();
    int line = 0;
    int word = 0;
    int previous = 'null';
    int character = 0;
    while(ch != EOF){
        //count lints
        if(ch == '\n'){
            line = line + 1;
        }
        //count words
        if((ch == ' ' || ch == '\n') && previous != 'null'){
            word++;
            previous = ch;
        }
        //count characters
        if(ch != 'null'){
            character++;
            previous = ch;
        }
        ch = getchar();
        //if there has SPACE and ENTER at the end of sentence, minus one word
        if(ch == EOF && (previous == ' ' || previous == '\n')){
            word--;
        }
        //if there hasbot 'SPACE and ENTER at the end of sentence, plus one word
        if(ch == EOF && (previous != ' ' || previous != '\n')){
            word++;
        }
        //minus the repeated ENTER and SPACE
        if((previous == ' ' || previous == '\n') && (ch == ' ' || ch == '\n')){
            word--;
            previous = ch;
        }
    }
    printf("%d lines %d words %d characters\n",line, word, character);
    return 0;
}
