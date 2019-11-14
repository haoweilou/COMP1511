//Haowei Lou
//z5258575
//09 Mar 2019
#include<stdio.h>
int main(void){
    int i;          //assgin variables
    int column=1;
    int row=1;
    printf("Enter size: ");
    scanf("%d",&i);
    while(row<=i){
        while(column<=i){
            if(row==1 || row==i){
                printf("*");
            }else if(row%2==0){
                if(2*row<i && column<row-1 && column%2!=0){
                     printf("*");
                }else if(2*row<i && column>row && column>i-row && column%2!=0){
                     printf("*");
                }else if(row==i/2+1 && column==i/2){
                    printf("-");
                }else if(2*row>i && column<=i-row && column%2!=0){
                    printf("*");
                }else if(2*row>i && column>row && column%2!=0){
                    printf("*");
                }else{
                     printf("-");
                }    
            }else if(row%2!=0){
                if(2*row<i && column<row-1 && column%2==0){
                    printf("-");
                }else if(2*row<i && column>row && column>i-row && column%2==0){
                    printf("-");
                }else if(row==i/2+1 && column==i/2){
                    printf("*");
                }else if(2*row>i && (column>row || column<=i-row) && column%2==0){
                    printf("-");
                }else{
                    printf("*");
                }
            }
            column=column+1;
        }printf("\n");
        row=row+1;column=1;
    }
    return 0;
}
