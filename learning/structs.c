#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct student {
 int studentID;
 char name[64];
 char tut_lab[16];
 int assign1_mark;
};

int main(void){
    struct student student1;
    strcpy(student1.name, "Haowei");
    student1.studentID = 5258575;
    
    printf("Student: %s ID: %d\n", student1.name, student1.studentID);
}
