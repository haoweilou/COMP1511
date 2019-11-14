//Pass_fail
//Haowei Lou
//z5258575
//26 Feb 2019
#include<stdio.h>

int main(void){
    int width=0;
    int length=0;
    int ok1=0;
    int ok2=0;
    
    printf("Please enter rectangle length: ");
    ok1=scanf("%d",&length);
    printf("Please enter your rectangle width: ");
    ok2=scanf("%d",&width);
    int area=width*length;
    
    if(ok1==0 || ok2==0){
        printf("No\n");
    }else{
    }
    printf("The area of the reactangle is: %d\n", area);
    
    return 0;
}
