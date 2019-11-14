#include<stdio.h>
#define LIMIT 1000000
int main(void){
    int number=0;
    while(1){
        printf("Enter number: ");
        scanf("%d",&number);
        
        printf("%d is ", number);
        if(number%2==0){
            printf("even");
        }else{
            printf("odd");
        }
        printf(".\n");      
    }

    printf("Sum =%d\n", sum);
    return 0;
}
