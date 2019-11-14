//Haowei Lou
//z5258575
//09 Mar 2019
#include<stdio.h>
int main(void){
    int column=1;             //assgin variables
    int row=1;
    int i;
    printf("Enter size: ");
    scanf("%d", &i);
    while(row<=i){
        while(column<=i){
            if(column==row || i+1==row + column){
                printf("*");
            }else{
                printf("-");
            }
            column=column+1;
        }printf("\n"); column=1;
        row=row+1;
    }
    return 0;
}
