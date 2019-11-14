//Haowei Lou
//z5258575
//06 Mar 2019

#include<stdio.h>
int main(void){
    int d,i,j;
    scanf("%d",&i);
    scanf("%d",&j);
    
    d=i-j;
    if(d<0){
        printf("%d",-d);
    }else if(d>0){
        printf("%d",d);
    }else{
        printf("equal");
    }printf("\n");
    
    return 0;
}
