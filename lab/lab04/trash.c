    /*while(column<=i){
            if(2*row<i){                                                        //upper part 
                if(row==1){                                                     //first row
                    printf("%d",a%10);
                    a=a-1;
                }else if(row%2==0){                                             //even line
                    if(column>i-row && column%2!=0){                            //right column b
                        if(column==i){
                            printf("%d",b%10); 
                            b=b-1;
                        }
                    }else{
                        printf("-");
                    }
                }else if(row%2!=0){                                             //odd line
                    if(column>i-row && column%2==0){                            
                        printf("-");
                    }else if(column>i-row && column%2!=0){                      //right column b
                        if(column==i){
                            printf("%d",b%10);
                            b=b-1;
                        }else{
                            printf(" ");
                        }
                    }else if(column<=row-2 && column%2!=0){          //left column
                        if(column==1){
                            printf("%d",c%10);
                            c=c+1;
                        }
                    }else{
                        printf("-"); 
                    }
                }
            }else if(row==i/2+1){                                               //middle row
                if(row%2!=0){                                                 //for even row when i= 5,9,13 etc
                    if(column==1){
                        printf("%d",c);
                        c=c-1;
                    }else if(column==i-row ||(column<=i-row+1 && column%2!=0)){
                        printf("%d",c%10);
                        c=c-1;
                    }else if(column==i){
                        printf("%d",b%10);
                        b=b-1;
                    }else{
                        printf("-"); 
                    }
                }else if(row%2==0){                                             //for odd row where i=7,11,15
                     
                }
            }else if(2*row>i){                                                  //lower part
                if(row==i){
                    printf("%d",last%10);
                    last=last+1;                                                //last row last
                }else if(row%2==0){                                             //even line
                    if(column>row && column%2!=0){                              //right column
                        printf("%d",b%10); 
                        b=b-1;
                    }else if(column<=i-row && column%2!=0){
                        if(column==1){
                            printf("%d",c%10);
                            c=c+1;
                        }
                    }else{
                        printf("-");
                    }
                    
                }else if(row%2!=0 && row!=i){                                   //odd line
                    if(column>row && column%2==0){
                        printf("-");
                    }else if(column>row && column%2!=0){                        //right column
                        printf("%d",b%10);
                        b=b-1;
                    }else if(column<=i-row && column%2!=0){                     //left column
                        printf("%d",c%10);
                        c=c-1;
                    }else{
                        printf("-");
                    }
                    
                }
            
            
            }*/
