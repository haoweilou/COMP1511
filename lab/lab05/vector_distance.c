//Haowei Lou
//z5258575
//17 Mar 2019
#include<stdio.h>
#include <math.h>

double eucilidean_distance(int length, double v1[length], double v2[length]){
    int i=0;
    double difference[length];
    double sum=0;
    while(i<length){
        difference[i]=(v1[i]-v2[i])*(v1[i]-v2[i]);
        sum=difference[i]+sum;
        i=i+1;
    }
    return sqrt(sum);
}
#define MAX_SIZE 1000
int main(void){
    int i=0;
    int j=0;
    int length=0;                                                                    //length
    double v1[MAX_SIZE];
    double v2[MAX_SIZE];
    
    printf("Enter vector length: ");
    scanf("%d",&length);
    
    printf("Enter vector 1: ");
    while(i<length){
        scanf("%lf",&v1[i]);
        i=i+1;
    }
    printf("Enter vector 2: ");
    while(j<length){
        scanf("%lf",&v2[j]);
        j=j+1;
    }
    
    double output=eucilidean_distance(length,v1,v2);
    printf("Euclidean distance = %lf\n", output);
    
    return 0;
}
