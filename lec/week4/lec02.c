#include<stdio.h>
#define N_NUMBERS 1000
int main(void){
    int x[N_NUMBERS];
    int i = 0;
    while(i < N_NUMBERS){
        printf("Enter a number? ");
        scanf("%d",&x[i]);
        int j = 0;
        while(j < i){
            if(x[i]==x[j]){
                printf("Snap\n");
                j=i;
            }
            j=j+1;
        }
        i=i+1;
    }
    return 0;
}
