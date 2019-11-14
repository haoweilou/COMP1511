//Haowei Lou
//z5258575
//02 May
#include<stdio.h>
int main(void){

    double mark,totalMark;
    
    printf("Enter the total number of marks in the exam: ");
    scanf("%lf",&totalMark);
    printf("Enter the number of marks the student was awarded: ");
    scanf("%lf",&mark);
    
    if(totalMark<mark){
        printf("Erro since mark cannot be greater than total mark\n");
    }else{
        printf("The student scored %.0lf%% in this exam.\n", (mark/totalMark)*100);
    }
    
    return 0;
}
