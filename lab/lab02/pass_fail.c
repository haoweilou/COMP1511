//Pass_fail
//Haowei Lou
//z5258575
//26 Feb 2019
#include<stdio.h>
#define MAX_MARK 100

int main(void){
    int mark=0;
    int ok=0;
    printf("Please enter your mark: ");
    ok=scanf("%d",&mark);
    if(ok == 0 || (mark<=49 && mark>=0)){
        printf("FAILED\n");
    }else if(mark >MAX_MARK || mark<100){
        printf("ERROR\n");
    }else{
        printf("PASSED\n");
    }
    return 0;
}
