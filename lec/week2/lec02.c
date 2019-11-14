//Haowei Lou
#include<stdio.h>
#define LIMIT 100.0
// 1+1/1+1/2+1/(1*2*3)
int main(void){
    double i;
    double sum;
    double divisor=1;

    i = 1;
    sum = 0;    
    while(i <= LIMIT){
        //printf("i=%.0f, sum=%lf\n", i, sum);
        sum = sum + 1.0/divisor;
        divisor = divisor*i;
        i =i + 1;
    }
    printf("Sum of first %.0lf integers is %.14lf\n", LIMIT, sum);

    return 0;
}
