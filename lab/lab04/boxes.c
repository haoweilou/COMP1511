//Haowei Lou
//z5258575
//09 Mar 2019
#include<stdio.h>
int main(void){
    int i;          //assign input value
    int height=1;
    int width=1;
    
    printf("How many boxes: ");     //input data
    scanf("%d",&i);
    
    while(height<=4*i-1){      //assign the max height
        while(width<=4*i-1){   //assign the max width
            if(height==1 || height==4*i-1){
                printf("#");
            }else if(width==1 || width ==4*i-1){
                printf("#");
            }else if(height%2==0){
                if(width<height && width%2!=0 && height<2*i){
                    printf("#");
                }else if(width>height && width%2!=0 && height>2*i){
                    printf("#");
                }else if(width>4*i-1-height && width%2!=0 && height<2*i){
                    printf("#");
                }else if(width<=4*i-1-height && width%2!=0 && height>2*i){          //include the value because 4i-1-height is needed to be shown as #
                    printf("#");
                }else if(height==2*i && width%2!=0){
                    printf("#");
                }else{
                    printf(" ");
                }
            }else if(height%2!=0){
                if(width%2==0 && (width<height ||width>4*i-1-height) && height<2*i){
                    printf(" ");
                }else if(width%2==0 && (width>height |width<=4*i-1-height) && height>2*i){  //include the value because 4i-1-height is needed to be shown as #
                     printf(" ");
                }else{
                    printf("#");
                }
            }else if(height%2!=0 && width>=height){
                
            }else{
                printf(" ");
            }
            width=width+1;
            }printf("\n"); width=1; //redefine width
            height=height+1;
        }
    return 0;
    }
