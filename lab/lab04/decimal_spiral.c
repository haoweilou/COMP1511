//Haowei Lou
//z5258575
//09 Mar 2019
#include<stdio.h>
int main(void){
    int i=0;          //assgin variables
    int column=1;
    int row=1;
    int a;
    int rr[j];
    int cc[j];
    
    printf("Enter size: ");
    scanf("%d",&i);
    
    a=(i-1)*(i+1)/2+i-1;
       
    while(row<=i){
        while(column<=i){
            if(row%2!=0){                                                  //assign the odd line
                if(2*row<i && (column<row-1 || column>i-row)  && column%2==0){  //upper,left&right
                    printf("-");
                }else if(row==i/2+1 && column==i/2){                            //special point
                    printf("%d",a%10);
                    a=a-1;
                }else if(2*row>i && (column>row ||  column<=i-row) && column%2==0){ //lower, left&right
                    printf("-");
                }else{
                    printf("%d",a%10);
                    a=a-1;
                }
            }else if(row%2==0){                                                  //even line                                                  
                if(2*row<i && (column<row-1 || column>i-row) && column%2!=0){  //upper,left&right
                    printf("%d",a%10);
                    a=a-1;
                }else if(row==i/2+1 && column==i/2){                            //special point
                    printf("-");
                }else if(2*row>i && (column>row || column<=i-row) && column%2!=0){  //lower,left&right
                    printf("%d",a%10);
                    a=(a-1);
                }else{
                     printf("-");
                } 
            }
            column=column+1;
        }printf("\n");column=1;row=row+1;
    }
    return 0;
}
