      else if(row%2==0){                                                  //even line                                                  
                if(2*row<i && /*column<row-1 || column>i-row*/ && column%2!=0){//upper,left&right
                     printf("%d",a%10);
                }else if(row==i/2+1 && column==i/2){                            //special point
                    printf("-");
                }else if(2*row>i && /*column>row || column<=i-row*/ && column%2!=0){  //lower,left&right
                    printf("%d",a%10);
                    a=(a+1);
                }else{
                     printf("-");
                }   
            } 
            else if(row%2!=0){                                                  //assign the odd line
                if(2*row<i && /*column<row-1 || column>i-row*/  && column%2==0){  //upper,left&right
                    printf("-");
                }else if(row==i/2+1 && column==i/2){                            //special point
                    printf("%d",a%10);
                    a=(a+1);
                }else if(2*row>i && /*column>row||*/  column<=i-row && column%2==0){ //lower, left&right
                    printf("-");
                }else{
                    printf("%d",a%10);
                    a=(a-1);
                    
                }
            }
