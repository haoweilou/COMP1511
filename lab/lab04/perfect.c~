//Haowei Lou
//z5258575
//09 Mar 2019
#include<stdio.h>
int main(void){
    int i=0;                            //assign variables
    int sum=0;
    int factor=1;
    printf("Enter number: ");           //assign i value
    scanf("%d",&i);
    printf("The factors of %d are:\n", i);
    while(factor<=i){
        if(i%factor==0){                //when factor is a factor of i, output factor and make sum=sum+factor
            printf("%d\n",factor);
            sum=sum+factor;
        }
        factor = factor + 1;            //Loop keep factor adding
    }
    printf("Sum of factors = %d\n",sum);
    if(2*i==sum){                       //determain whether it is a perfect number
        printf("%d is a perfect number",i);
    }else{
        printf("%d is not a perfect number",i);
    }printf("\n");
    return 0;
}
