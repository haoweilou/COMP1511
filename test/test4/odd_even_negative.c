//Haowei Lou
//z5258575  
//28 Mar 2019
#include<stdio.h>
int main(void){
    int i=0,j=0,k=1;
    int numbers[1000]={ };
    while(k==1){
        scanf("%d",&numbers[i]);
        if(numbers[i]<0){
           k=0;
        }
        i++;
    }
    j=0;
    printf("Odd numbers were: ");
    while(j<i){
        if(numbers[j]%2!=0 && numbers[j]>=0){
            printf("%d ",numbers[j]);
        }
        j++;
    }printf("\n");
    j=0;
    printf("Even numbers were: ");
    while(j<i){
        if(numbers[j]%2==0 && numbers[j]>=0){
            printf("%d ",numbers[j]);
        }
        j++;
    }printf("\n");
    return 0;
}
