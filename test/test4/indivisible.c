//Haowei Lou
//z5258575  
//28 Mar 2019
#include<stdio.h>
#define MAX 1000
int main(void){
    int i=0,j=0,input[MAX]={ },number_of_input=0;
    while(scanf("%d",&input[i])!=EOF){
        i++;
        number_of_input=i;
    }
    int d=0,k=0, div[MAX],number_of_div=0;
    i=0;
    while(i<number_of_input){
        j=0;d=0;
        while(j<number_of_input){
            if(input[i]%input[j]==0 && i!=j){
                d=1;
                j=number_of_input;
            }else if(input[i]==input[j] && i!=j){
                d=1;
                j=number_of_input;
            }
            j++;
        }
        if(d==0){
            div[k]=input[i];
            k++;
            number_of_div=k;
        }
        i=i+1;
    }
    i=0;
    printf("Indivisible numbers: ");
    while(i<number_of_div){
        printf("%d ",div[i]);
        i++;
    }printf("\n");
    return 0;
}
