#include<stdio.h>
#define MAX 10000
int main(void){
    //PREVIOUS CARDS PLAYED
    int cards_played=2;
    int previous_card[MAX],i=0;
    i=0;
    while(i<cards_played){                                                      //LOOP
        scanf("%d",&previous_card[i]);                                          //SCANF
        i=i+1;
    }
    //FIND FACTOR
    int factor[MAX],j=0,prime=0;
    i=2;
    while(i>=2 && i<previous_card[0]){
        if(previous_card[0]%i==0){
            factor[j]=i;
            j=j+1;
        }
        i=i+1;
    }
    i=0;
    while(i<j){
        printf("factor[%d] = %d\n",i,factor[i]);
        i=i+1;
    }
    return 0;
}
