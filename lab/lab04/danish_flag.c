//Haowei Lou
//z5258575
//09 Mar 2019
#include<stdio.h>
int main(void){
    int i;          //assign input value
    int height=1;
    int width=1;
    
    printf("Enter the flag size: ");
    scanf("%d",&i);
    
    while(height<=4*i){
        while(width<=9*i){
            if(height==i*2||height==i*2+1||width==i*3||width==i*3+1){
                printf(" ");
            }else{
                printf("#");
            }
            width = width + 1; 
        }printf("\n");width=1;
        height = height + 1;
    }
    
    return 0;
}
