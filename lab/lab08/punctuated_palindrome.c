//Haowei Lou
//z5258575
//08 April 2019
#include<stdio.h>
#include<stdlib.h>
#define MAX 4096
int palindrome(char character[MAX],int num_of_cha){
    int i = 0, j = num_of_cha - 1;
    int p = 1;
    i=0;
    while(i<num_of_cha){
        if(character[i] != character[j - i]){
            p = 0;
            i = num_of_cha;
        }
        i++;
    }
    return p;
}

int keep_letter(char character[MAX], int num_of_cha, char new[MAX]){
    int i = 0;
    int num_new = 0;
    while(i<num_of_cha){
        if(character[i] <= 'Z' && character[i] >= 'A'){
            character[i] = character[i] + 'a' - 'A'; 
        }
        i++;
    }
    i = 0;
    int j=0;
    while(i<num_of_cha){
        if(character[i]<='z' && character[i]>='a'){
            new[j]=character[i];
            j++;
            num_new=j;
        }
        i++;
    }
    return num_new;
}

int main(void){
    printf("Enter a string: ");
    
    int p=0;                                                                    //not a palin
    char input[MAX]={0};
    int i = 0;
    
    fgets(input,MAX,stdin);
    
    while(input[i] != '\n' && input[i] != '\0'){
        i++;
    }
    
    char new[MAX]={0};
    int num_new = keep_letter(input,i,new);
    
    p = palindrome(new, num_new);
    if(p == 1){
        printf("String is a palindrome\n");
    }else if(p == 0){
        printf("String is not a palindrome\n");        
    }
    return 0;
}
