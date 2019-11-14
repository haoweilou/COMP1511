//Haowei Lou
//z5258575
//01 May

#include<stdio.h>
int main(void){
    int a,b,c;
    //Enter a,b,c value by user
    printf("Enter integer: ");
    scanf("%d",&a);
    printf("Enter integer: ");
    scanf("%d",&b);
    printf("Enter integer: ");
    scanf("%d",&c);
   
    //Arrange the input data
    printf("The integers in order are: ");//Output sentence 
    //when a is smallest
    if(a<=b && a<=c){
        printf("%d ",a);
        if(b<=c){
            printf("%d %d\n",b,c);            
        }else{
            printf("%d %d\n",c,b);
        } 
    }else if(b<=c && b<=a){//when b is smallest
        printf("%d ",b);
        if(a<=c){
            printf("%d %d\n",a,c);            
        }else{
            printf("%d %d\n",c,a);
        } 
    }else{//when c is smallest
        printf("%d ",c);
        if(a<=b){
            printf("%d %d\n",a,b);            
        }else{
            printf("%d %d\n",b,a);
        } 
    }
    return 0;
}
