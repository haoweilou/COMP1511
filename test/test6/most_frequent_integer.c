//Haowei Lou
//z5258575
//12 April 2019
#include<stdio.h>
#define MAX 100000
int duplicate(int length, int input[length], int duplication[length]){
    int i = 0, j = 0, k = 0, num_of_des = 0, rep = 0;
    while(i < length){
        j = 0, rep = 0;
        while(j < num_of_des){
            if(duplication[j] == input[i]){
                rep = 1;
                j = num_of_des;
            }
            j = j + 1;
        }
        if(rep == 0){
            duplication[k] = input[i];
            k++;
            num_of_des = k;
        }
        i = i + 1;
    }
    return num_of_des;
}
int count(int length, int input[length], int duplication[length], int duplicate){
    int frequency[MAX] = {0}, i = 0, j = 0;
    while(i < duplicate){
        j = 0;
        while(j < length){
            if(duplication[i] == input[j]){
                frequency[i] = frequency[i] + 1;
            }
            j++;
        }
        i++;
    }
    //Find Max frequency
    i = 0;
    int max = 0;
    while(i < duplicate){
        if(max < frequency[i]){
            max = frequency[i];
        }
        i++;
    }
    //Find the number that have max frequency
    int output[MAX] = {0}, num_of_output =0;
    i = 0, j = 0;
    while(i < duplicate){
        if(frequency[i] == max){
            output[j] = duplication[i];
            j++;
            num_of_output=j;
        }
        i++;
    }
    //find greatest output if they have same frequenct
    int g = 0;
    i = 0;
    while(i < num_of_output){
        if(output[i] > g){
            g = output[i];
        }
        i++;
    }
    return g;
}
int main(void){
    int i = 0, length = 0;
    int input[MAX] = {0};
    //Input the value into array
    while(scanf("%d", &input[i]) != EOF){
        i++;
        length = i;
    }
    //int find duplicate
    int duplication[MAX] = {0};
    int copy_number = duplicate(length, input, duplication);
    //count the duplication number
    int counting = count(length, input, duplication, copy_number);
    printf("%d\n",counting);
    return 0;
}

