//Haowei Lou
//z5258575
//13 Mar 2019
#include<stdio.h>
int main(void){
    int a,b,c;
    
    printf("Enter integer: ");
    scanf("%d",&a);
    printf("Enter integer: ");
    scanf("%d",&b);
    printf("Enter integer: ");
    scanf("%d",&c);
    
    if((a<b && b<c) || (c<b && b<a)){
        printf("Middle: %d",b);
    }else if((a<c && c<b)||(b<c && c<a)){
        printf("Middle: %d",c);
    }else if((b<a && a<c) || (c<a && a<b)){
        printf("Middle: %d",a);
    }else if(a==b && a<c){
        printf("Middle: %d",b);
    }else if(a==c && a<b){
        printf("Middle: %d",a);
    }else if(c==b && c<a){
        printf("Middle: %d",c);
    }else if(a==b && a>c){
        printf("Middle: %d",b);
    }else if(a==c && a>b){
        printf("Middle: %d",a);
    }else if(c==b && c>a){
        printf("Middle: %d",c);
    }else if(c==b && a==c){
        printf("Middle: %d",a);
    }printf("\n");
    
    return 0;
}
