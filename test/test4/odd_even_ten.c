//Haowei Lou
//z5258575  
//28 Mar 2019
#include<stdio.h>
int main(void){
    int i=0;
    int numbers[10]={ };
    while(i<10){
        scanf("%d",&numbers[i]);
        i++;
    }
    i=0;
    printf("Odd numbers were: ");
    while(i<10){
        if(numbers[i]%2!=0){
            printf("%d ",numbers[i]);
        }
        i++;
    }printf("\n");
    i=0;
    printf("Even numbers were: ");
    while(i<10){
        if(numbers[i]%2==0){
            printf("%d ",numbers[i]);
        }
        i++;
    }printf("\n");
    return 0;
}
