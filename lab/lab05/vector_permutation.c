//Haowei Lou
//z5258575
//17 Mar 2019
#include<stdio.h>
#define MAX 1000

int arrange(int length, int vector[length], int permutation[length]){
    int a=0;
    int b=0;
    int x[MAX];
    
    while(a<length){
        if(permutation[a]>=length || permutation[a]<0){                         //When permutaion is greater than length+1 or less than 0, it is false
            printf("Invalid permutation");
            a=length+1;                                                         //stop the while loop by make a=length+1
        }else{
            x[a]=vector[permutation[a]];                          //start from x[0],x[1].. vector[permutaion[0]]=vector[4]=x[0],vector[permutaion[1]]=vector[3]=x[2]
            a=a+1;                                                              //store x[a]
        }
    }
    while(b<length && a!=length+1){                                             //print x[a] from x[0] to x[length], only print it when permutation is valid.
        printf("%d ",x[b]);
        b=b+1;
    }
    printf("\n");
    return 0;
}

int main(void){
    int length=0;
    int i=0;
    int j=0;
    int vector[MAX];
    int permutation[MAX];
    
    printf("Enter vector length: ");                                            //define length
    scanf("%d",&length);
    printf("Enter vector: ");                                                   //Enter vector
    while(i<length){
        scanf("%d",&vector[i]);
        i=i+1;
    }
    printf("Enter permutation: ");                                              //Enter permutation
    while(j<length){
        scanf("%d",&permutation[j]);
        j=j+1;
    }
    int output=arrange(length,vector,permutation);                              //link to arrange function
    return 0;
}

