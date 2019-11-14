//Haowei Lou
//z5258575
//25 Feb 2019
#include<stdio.h>
int main(void){
    int a;
    double b,c;
    printf("How many scoops? ");
    scanf("%d",&a);
    printf("How many dollars does each scoop cost? ");
    scanf("%lf",&b);
    c=a*b;
    if(c<=10){
        printf("You have enough money!\n");
    }else{
        printf("Oh no, you don't have enough money :(\n");
    }
    return 0;
}
