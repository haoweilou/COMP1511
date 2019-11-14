//Haowei Lou
//z5258575
//04 April 2019
#include<stdio.h>
// copy all of the values in source1 which are also found in source2 into destination
// return the number of elements copied into destination
#define NUMBER 1000
int common_elements(int length, int source1[length], int source2[length],int destination[2*length]) {
    // PUT YOUR CODE HERE (you must change the next line!)
    int i=0, j=0, k=0;
    int repeat = 0,number_of_output=0;
    while(i < length){
        j=0;
        while(j<length){
            if(source1[i]==source2[j]){
                destination[k]=source1[i];
                k = k + 1;
                number_of_output = k;
                j = length;
            }j++;
        }
        i = i + 1;
    }
        

    return number_of_output;
}
