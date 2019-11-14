#include<stdio.h>
#define SQUARE_SIZE 6
int main(void){
    int number1,number2;
    int c=0;
    while (c==0){
        scanf("%d",&number1);
        if (number1 == number2){
            printf("Snap!\n");    
            c=1;        
        }
        scanf("%d",&number2);
        if (number1 == number2){
            printf("Snap!\n");   
            c=1;         
        }
    }
    return 0;
}
