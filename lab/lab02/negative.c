//Haowei Lou
//z5258575
//25 Feb 2019
#include<stdio.h>
int main(void){
    double a;
    scanf("%lf",&a);
    if(a>0){
        printf("You have entered a positive number.\n");   
    }else if(a==0){
        printf("You have entered zero.\n"); 
    }else{
        printf("Don't be so negative!\n");
    }
    return 0;
}
