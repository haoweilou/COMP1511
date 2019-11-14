//Haowei Lou
//z5258575
//06 Mar 2019

#include<stdio.h>
int main(void){
    double i,j,k;
    double a,b,c;   
    printf("Please enter three numbers: ");
    scanf("%lf",&i);scanf("%lf",&j);scanf("%lf",&k);
    
    a=i+j;
    b=i+k;
    c=j+k;
    
    if(a>k && b>j && c>i){
        printf("triangle\n");
    }else{
        printf("not a triangle\n");
    }
    
    return 0;
}
