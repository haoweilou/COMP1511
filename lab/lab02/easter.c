//Haowei Lou
//z5258575
//25 Feb 2019
#include<stdio.h>
int main(void){
    int a,b,c,d,e,f,g,h,i,k,l,m,p;//all relevant variable to calculate date
    int year,month,date; //final output, wiil be shown in output
    printf("Enter year: ");
    scanf("%d",&year);
    
    a=year%19;
    b=year/100;
    c=year%100;
    d=b/4;
    e=b%4;
    f=(b+8)/25;
    g=(b-f+1)/3;
    h=(19*a+b-d-g+15)%30;
    i=c/4;
    k=c%4;
    l=(32+2*e+2*i-h-k)%7;
    m=(a+11*h+22*l)/451;
    
    month =(h+l-7*m+114)/31;//month is calculated
    p=(h+l-7*m+114)%31;
    date=p+1;//date is calculated
    
    printf("Easter is ");
    if(month==4){
        printf("April");
    }else if (month==3){
        printf("March");
    }
    printf(" %d in %d.\n", date,year);
    return 0;   
}
