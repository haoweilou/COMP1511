//Haowei Lou
//z5258575
//13 Mar
#include<stdio.h>
int main(void){
    int i;
    int column=1;
    int row=1;
    
    printf("Enter size: ");
    scanf("%d",&i);
    
    while(row<=i){
        while(column<=i){
            if((column==1 && row!=i) || row==i){
                printf("*");
            }else{
                printf(" ");
            }
            column=column+1;
        }printf("\n");columnged=1;
        row=row+1;
    }
    
    return 0;
}
