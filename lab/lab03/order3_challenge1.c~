//Haowei Lou
//z5258575
//02 May

#include<stdio.h>
int main(void){
    int a,b,c;
    int x,y,z;
    
    printf("Enter integer: ");scanf("%d",&a);
    printf("Enter integer: ");scanf("%d",&b);
    printf("Enter integer: ");scanf("%d",&c);
    
    x=a*(a<b && a<c && a!=b && b!=c)
     +b*(b<c && b<a && b!=c && c!=a)
     +c*(c<b && c<a && c!=a && a!=b)
     +a*(a<b && b==c)
     +b*(b<a && a==c)
     +c*(c<b && b==a)
     +a*(a==b && b<c)+a*(a==c && a<b)
     +b*(c==b && b<a)
     +c*(c==b && b<c)
     +a*(a==b && a==c);//asign x to find the lowest number
     
    y=b*((b<c && b>a && b!=c && c!=a)+
      (b>c && b<a && b!=c && b!=a))
     +c*((c<a && c>b && c!=a && a!=b)+
      (c>a && c<b && c!=a && c!=b))
     +a*((a<b && a>c && a!=b && b!=c)+
      (a>b && a<c && a!=b && a!=c))
     +a*(a==b && b<c)
     +c*(c==a && c<b)+c*(c==b && b<a)
     +a*(a==b && b>c)
     +c*(c==a && c>b)+c*(c==b && c>a)
     +a*(a==b && b==c);//assign y to find the middle number
    
    z=c*(c>b && c>a && b!=a)
     +a*(a>b && a>c && b!=c)
     +b*(b>a && b>c && a!=c)
     +a*(a>b && b==c)+a*(a>c && a==b)
     +c*(c>b && b==a)+c*(c>b && c==a)
     +b*(b>a && c==a)+b*(b>a && b==c)
     +a*(a==b && b==c);//asign z to find the biggest number
    
    printf("The integers in order are: %d %d %d\n", x,y,z);
        
    return 0;
}
