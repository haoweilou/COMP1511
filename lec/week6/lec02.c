#include<stdio.h>
#include<string.h>
void increment(int *x){
    *x=*x+1;
}
int main(){
    int num = 13;
    while(i<20){
        printf("%d\n", i);
        increment(&i);
    }
    return 0;
}
