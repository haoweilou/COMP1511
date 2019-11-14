//Haowei Lou
//z5258575
//20 Mar 2019
#include<stdio.h>
#define MAX 10000
int main(void){
    int input,number=0;
    int factor=0;
    int i=1,j=0;
    
    printf("Enter number: ");
    scanf("%d",&input);
    
    i=1;
    int originalinput=input;
    
    i=2;
    
    int prime=1;
    while(i<originalinput){                                                     //determine wheter it is a prime
        if(i>1 && i!=originalinput && originalinput%i==0){
            prime=0;
            i=originalinput;
        }else{
            prime=1;
        }
        i=i+1;
    }
    
    i=0;
    if(prime==0){                                                               //if it is not prime
        printf("The prime factorization of %d is:\n",originalinput);
        while(input!=1){
            while(i<originalinput){
                if(i>1 && input%i==0){
                    input=input/i;
                    factor=i;
                    if(input!=1){
                        printf("%d ",factor);
                        printf("* ");  
                    }else if(input==1){
                        printf("%d",factor);
                        printf(" =");
                    }
                    i=1;
                }
                i=i+1;
            }
        }
            printf(" %d\n",originalinput);
    }else if(prime==1){
        printf("%d is prime\n",originalinput);
    }
    return 0;
}
