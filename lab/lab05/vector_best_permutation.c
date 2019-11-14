//Haowei Lou
//z5258575
//17 Mar 2019
#include<stdio.h>
#include<math.h>
#define MAX 1000

int rank(int length, int v1[length], int v2[length], int permutation[length]){
    int i=0,j=0,k=0;
    int max1[MAX],max2[MAX];
    int order1[MAX], order2[MAX];                                               //order the nth vector from large(0) to small(n-1)
    int newv1[MAX],newv2[MAX];                                                  //change the vector and keep its 
    while(k<length){
        max1[k]=0;
        max2[k]=0;
        k=k+1;
    }
    while(j<length){
        i=0;
        while(i<length){                                                        
        
            if(max1[j]<v1[i] && j==0){
                max1[j]=v1[i];
                order1[j]=i;
            }else if(max1[j]<v1[i] && v1[i]<max1[j-1]){                         //find max1 && make order1[0]
                max1[j]=v1[i];
                order1[j]=i;
            }
            
            if(max2[j]<v2[i] && j==0){                                          //find max1 && make order1[0]
                max2[j]=v2[i];
                order2[j]=i;
            }else if(max2[j]<v2[i] && v2[i]<max2[j-1]){
                max2[j]=v2[i];
                order2[j]=i;
            }
            i=i+1;
        }
        j=j+1;
    }  
    
    j=0;
    i=0;
    while(i<length){                                                            //reorder order1 function
        j=0;
        while(j<length){
            if(order1[j]==i){
                newv1[i]=j;
            }
            if(order2[j]==i){
                newv2[i]=j;
            }
            j=j+1;
        }
        i=i+1;
    }
    
    j=0;
    int a=0;
    while(j<length){                                                            //find best permutation
       i=0;
       while(i<length){
            if(newv1[i]==newv2[j]){
                permutation[a]=i;
                a=a+1;
            }
            i=i+1;
       } 
       j=j+1;
    }
    
    return 0;
}

int permutation(int length, int v1[length], int best[length], int sv1[length]){
    int a=0;
    int b=0;
    int x[MAX];
    
    while(a<length){
        if(best[a]>=length || best[a]<0){                       
            printf("Invalid permutation");
            a=length+1;                                                         
        }else{
            x[a]=v1[best[a]];                                       
            a=a+1;                                                           
        }
    }
    while(b<length && a!=length+1){                                           
        sv1[b]=x[b];
        b=b+1;
    }
    return 0;
}

double distance(int length, int v2[length], int v1[length]){
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

int main(void){
    int length=0;
    int i=0;
    int j=0;
    int v1[MAX];
    int v2[MAX];
    
    printf("Enter vector length: ");                                            //define length
    scanf("%d",&length);
    printf("Enter vector 1: ");                                                 //Enter vector
    while(i<length){
        scanf("%d",&v1[i]);
        i=i+1;
    }
    printf("Enter vector 2: ");                                                 //Enter vector
    while(j<length){
        scanf("%d",&v2[j]);
        j=j+1;
    }
    
    int best[MAX];
    int a=rank(length,v1,v2, best);
    printf("Optimal permutation: ");
    i=0;
    while(i<length){
        printf("%d ",best[i]);
        i=i+1;
    }printf("\n");
    
    int sv1[MAX];
    int perm=permutation(length,v1,best,sv1);
    
    double dis=distance(length, v2, sv1);
    printf("Euclidean distance = %lf\n",dis);
    
    return 0;
}
