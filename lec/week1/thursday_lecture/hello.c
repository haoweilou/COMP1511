#include <stdio.h>
int main(void){
    double f;
    double c;
    
    printf("Enter a number ");
    scanf("%lf", &f);
    c=(f-32)*5/9;
    printf("Celsius is %f\n",c);
 
    
    return 0;
} 
