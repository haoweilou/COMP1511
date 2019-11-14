//Haowei Lou
//z5258575
//20 Mar 2019
#include<stdio.h>
int main(void){
    int lower, upper;
    int i=0;
    
    printf("Enter lower: ");
    scanf("%d",&lower);
    printf("Enter upper: ");
    scanf("%d",&upper);
    i=lower;
    while(i<upper){
        if(i>lower && i<upper){
            printf("%d\n",i);
        }
        i=i+1;
    }
    
    return 0;
}
