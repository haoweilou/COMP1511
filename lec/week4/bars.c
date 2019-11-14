#include<stdio.h>
int main(void){
    int i=0;
    int row=1;
    int column=1;
    printf("Enter size: ");
    scanf("%d", &i);
    while(row<=i){
        while(column<=i){
            if(column%2==0){
                printf("*");
            }else{
                printf("-");
            }
            column=column+1;
        }printf("\n");column=1;
        row=row+1;
    }
    return 0;    
}
