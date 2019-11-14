//Haowei Lou
//z5258575
//02 April 2019
#include<stdio.h>
#include <stdlib.h>
#define NUM_OF_LETTER 26
void frequency(int character, int count[NUM_OF_LETTER]){
    int i=0,array[]={};
    
    if(character>='A' && character<='Z'){
        character = character + 'a' - 'A';
        count[character-'a']=count[character-'a']+1;
    }else if(character>='a' && character <= 'z'){
        count[character-'a']=count[character-'a']+1;
    }
}
void output(int count[NUM_OF_LETTER]){
    int i = 0;  
    double sum=0;
    double percentage[NUM_OF_LETTER]={0};
    while(i<26){
        sum=sum+count[i];
        i=i+1;
    }
    i=0;
    while(i<26){
        percentage[i]=count[i]/sum;
        i++;
    }
    i = 0;
    while(i<26){
        printf("'%c' %f %d\n",'a'+i, percentage[i], count[i]);
        i = i + 1;
    }
    
}
int main(void){
    int ch=getchar();
    int count[NUM_OF_LETTER]={0};
    while(ch != EOF){
        frequency(ch,count);
        ch=getchar();
    }
    output(count);
    
    return 0;
}
