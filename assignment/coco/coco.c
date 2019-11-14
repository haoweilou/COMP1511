// Assignment 1 19T1 COMP1511 Coco
// This program was written by Haowei Lou (z5258575)
// on 23 Mar 2019

// This is a program to play a name called coco
// First will print player's name, which is Haowei Lou

// Then the palyer will receive ten cards that in the range between 10..49
// The program will choose three cards who is greater than 42 to discard
// If the number of cards above 42 is less than three, choose the prime cards to discard

// Then the program will play the card follow the COCO rule to play cards
// https://en.wikipedia.org/wiki/John_von_Neumann
// The program will play cards in a simple strategy, which has shown in below codes 


#include <stdio.h>
#include <assert.h>


#define ACTION_PLAYER_NAME    0
#define ACTION_DISCARD        1
#define ACTION_PLAY_CARD      2

#define N_CARDS              40
#define N_CARDS_INITIAL_HAND 10
#define N_PLAYERS             4
#define N_CARDS_DISCARDED     3

#define CARD_MIN             10
#define CARD_MAX             49


// IF YOU NEED MORE #defines ADD THEM HERE


void print_player_name(void);
void choose_discards(void);
void choose_card_to_play(void);


// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE
int check_prime(int input){
    int output = 0;
    if(input%2 == 0 || input%3 == 0 || input%5 == 0 || input%7 == 0){
        output = 0;
    }else if(input%2 != 0 && input%3 != 0 && input%5 != 0 && input%7 != 0){
        output = 1;
    }
    return output;
}

int cards_played_in_history(int cards_in_hand){
    int output = 0;
    output = (10 - cards_in_hand) * 4;
    return output;
}

// You should not need to change this main function

int main(void) {

    int which_action = 0;
    scanf("%d", &which_action);
    if (which_action == ACTION_PLAYER_NAME) {
        print_player_name();
    } else if (which_action == ACTION_DISCARD) {
        choose_discards();
    } else if (which_action == ACTION_PLAY_CARD) {
        choose_card_to_play();
    }

    return 0;
}

void print_player_name(void) {
    //PRINT PLAYER'S NAME
    printf("Haowei Lou\n");
}
#define MAX 1000
void choose_discards() {
    int cards[MAX],i = 0;
    
    while(i < 10){
        scanf("%d", &cards[i]);
        i = i + 1;
    }
        
    i = 0;
    int p = 0,prime[MAX],j = 0,k = 0,factor = 2,num_of_prime = 0;
    while(i < 10){
        factor = 2;
        while(factor <= 11 && factor != cards[i]){
            //IF THE INPUT NUMBER IS PRIME, RETURN 1                              
            if(cards[i] % factor != 0){                                         
                p = 1;
            }else if(cards[i] % factor == 0){
            //IF THE INPUT NUMBER IS NOT PRIME, RETURN 2
                p = 0;
                factor = 12;
            }factor = factor + 1;
        }
        if(p == 1){
            //STORE THE PRIME NUMBER INTO AN ARRAY
            prime[k] = cards[i];
            k = k + 1;
            num_of_prime = k;
        }i = i + 1;
    }
        
    int primemax[3] = { },max[3] = { };                                             
    //FIND FIRST 3 BIGGEST NUMBER FROM BOTH PRIME[] AND CARDS[]
    j = 0;
    while(j < 3){
        i = 0;
        while(i < 10){                                                            
            //MAX=FIRST 3 BIGGEST NON-PRIME NUMBER
            if(check_prime(cards[i]) == 0){
                if(j == 0){
                    if(max[j] < cards[i] && cards[i] != 42){
                        max[j] = cards[i];
                    }
                }else if(j >= 1){
                    if(cards[i] > max[j] && cards[i] < max[j-1] && cards[i] != 42){
                        max[j] = cards[i];  
                    }
                }
            }
            i = i + 1;
        }        
        i = 0;
        while(i < num_of_prime){                                              
            //PRIMEMAX=FIRST 3 BIGGEST PRIME NUMBER
            if(j == 0){
                if(prime[i] > primemax[j]){
                    primemax[j] = prime[i]; 
                }
            }else if(j >= 1){
                if(prime[i] < primemax[j-1] && prime[i] > primemax[j]){
                    primemax[j] = prime[i]; 
                }
            }
            i = i + 1;
        }
        j = j + 1;
    }
    
    i = 0,j = 0,k = 0;
    while(i < 3){
        if(max[k] > 42){                                                      
            //IF THE MAX[i] IS GREATER THAN 42, DISCARD THESE FIRST
            printf("%d " ,max[k]);
            k = k + 1;
            i = i + 1;
        }else if(max[k] < 42){                                                
            //IF THE MAX[i] IS SMALLER THAN 42
            if(primemax[j] >= 10 && primemax[j] <= 49){                         
                //IF THE PRIMEMAX[i] EXIST IN THE RANGE OF [10,49], THEN DISCARD THEM
                printf("%d " ,primemax[j]);
                j = j + 1;
                i = i + 1;
            }else{                                                          
                //IF THERE IS NO MORE PRIMEMAX[i], THEN DISCARD THE REMAIN MAX[i]
                printf("%d " ,max[k]);
                i = i + 1;
                k = k + 1;
            }
        }
    }printf("\n");
}

void choose_card_to_play(void) {
    // ADD CODE TO READ THE FIRST THREE NUMBERS WHICH ARE:
    int cards_in_hand,cards_played,table_position;
    int i = 0;
    while(i < 3){
        if(i == 0){
            scanf("%d",&cards_in_hand);                                         
        //NUMBER OF CARDS IN HAND
        }else if(i == 1){
            scanf("%d" ,&cards_played);                                          
        //NUMBER OF CARDS PLAYED THIS ROUND
        }else if(i == 2){
            scanf("%d" ,&table_position);                                        
        //TABLE POSITION
        }
        i = i + 1;
    }
    // ADD CODE TO READ THE CARDS IN HAND INTO AN ARRAY
    int cards[cards_in_hand];
    i = 0;
    while(i < cards_in_hand){                                                     
        scanf("%d" ,&cards[i]);                                                  
        i = i + 1;
    }
    // ADD CODE TO READ THE CARDS PREVIOUSLY PLAYED THIS ROUND INTO AN ARRAY
    int previous_card[MAX]={ },max_previous_card=0;
    i = 0;
    while(i < cards_played){                                                      
        scanf("%d" ,&previous_card[i]);                                          
        i = i + 1;
    }
    i = 0;
    int prime_is_played = 0;
    while(i < cards_played){                                                                            
        if(max_previous_card < previous_card[i]){                                 
            //FIND THE VALUE OF MAX VALUE OF PREVIOUS PLAYED CARD 
            max_previous_card = previous_card[i];
        }
        if(check_prime(previous_card[i]) == 1){
            //INDICATE PRIME IS PLAYED IN PREVIOUS
            prime_is_played = 1;                                                  
        }
        i = i + 1;
    }
    // ADD CODE TO READ THE CARDS PLAYED IN THE HISTORY OF THE GAME INTO AN ARRAY
    int history_card[MAX] = { },total_cards = 40,a = 0;
    i = 0;
    while(i < cards_played_in_history(cards_in_hand)){                         
        scanf("%d" ,&history_card[i]);                                           
        a = a + 1;
        i = i + 1;
    }
    i = 0;
    while(i < a){
        if(check_prime(history_card[i]) == 1){
            prime_is_played = 1;                                                  
            //INDICATE PRIME IS PLAYED IN HISTORY
            i = a;
        }
        i = i + 1;
    }
    //FIND THE FACTOR OF FIRST PLAYED CARDS
    int factor[MAX] = { },num_of_factor = 0,primality = 1,k = 0;
    i = 2;
    while(i >= 2 && i < previous_card[0]){                                          
        //FIND FACTOR OF FIRST PLAYED CARD
        if(previous_card[0]%i == 0){
            factor[k] = i;
            k = k + 1;
            num_of_factor = k;
            primality = 0;
        }
        i = i + 1;
    }
    //FIND THE PRIME NUMBER
    int prime[MAX] = { },p = 1,num_of_prime = 0,fac = 2;
    i = 0,k = 0;
    while(i < cards_in_hand){
        fac = 2,p = 1;
        while(fac <= 13 && fac != cards[i]){                                        
            if(cards[i] % fac == 0){
                p = 0;                                                          
                //P=0 MEANS IT IS NOT PRIME
                fac = 14;
            }
            fac = fac + 1;
        }
        if(p == 1){                                                               
            //P=1 MEANS IT IS PRIME
            prime[k] = cards[i];                                                  
            //SAVE THESE PRIME INTO ARRAY CALLED PRIME[]
            k = k + 1;
            num_of_prime = k;
        }
        i = i + 1; 
    }
    //FIND ALL POSSIBLE COCOMPOSITE NUMBERS
    int num_of_co = 0,j = 0,cocom[MAX] = { };
    i = 0,j = 0,k = 0;
    while(i < cards_in_hand){
        j = 0;
        while(j < num_of_factor){                                                 
            //FIND ALL OTHER CARDS WHOLE HAVE SAME FACTOR OF FIRST CARD
            if(cards[i]%factor[j] == 0 && factor[j]<cards[i]){
                if(k==0 && cards[i]!=cocom[k]){
                    //COCOM[] MEANS ALL POSSIBLE CARDS WHO HAS SAME FACTOR OF FIRST CARD
                    cocom[k] = cards[i];                                             
                    k = k + 1;
                    num_of_co = k;     
                }else if(k>=1 && cards[i]!=cocom[k-1]){
                    cocom[k] = cards[i];                                             
                    k = k + 1;
                    num_of_co = k;  
                }
            }
            j = j + 1;
        }
        i = i + 1;
    }
    //FIND THE LEGIT OUTPUT
    int legit_output[MAX] = { },num_of_legit_output = 0;
    i = 0,j = 0,k = 0;
    if(cards_played != 0){                                                        
    //IF DON'T PLAY FIRST
        while(i < cards_in_hand){
            j = 0;
            if(primality == 1){                                                   
                //IF FIRST OUTPUT CARD IS PRIME
                if(num_of_prime == 0){                                            
                    //IF DON'T HAVE PRIME CARD
                    legit_output[k] = cards[i];                                   
                    //CAN PLAY ANY CARD
                    k = k + 1;
                    num_of_legit_output = k;
                }else if(num_of_prime >= 1){                                     
                    //IF HAVE PRIME CARD
                    legit_output[k] = prime[i];                                   
                    //CAN ONLY PLAY PRIME CARD
                    k = k + 1;
                    num_of_legit_output = k; 
                }
            }else if(primality == 0){                                             
                //IF FIRST OUTPUT CARD IS NOT PRIME       
                if(num_of_co == 0){                                               
                    //IF NOT HAVE SAME COMPOSITE NUMBER            
                    if(prime_is_played == 1){                                     
                        //IF PRIME IS PLAYED IN HISTORY ROUND
                        legit_output[k] = cards[i];                               
                        //CAN PLAY ANY CARD IN HAND
                        k = k + 1;
                        num_of_legit_output = k; 
                    }else if(prime_is_played == 0){                               
                        //IF PRIME IS NOT PLAYED IN HISTORY ROUND
                        if(cards_in_hand == num_of_prime){                        
                            //IF ONLY HAVE THESE PRIME CARD
                            legit_output[k] = cards[i];                           
                            //CAN PLAY THESE PRIME CARD
                            k = k + 1;
                            num_of_legit_output = k; 
                        }
                        if(cards_in_hand > num_of_prime){                   
                            //IF THE REMAIN CARD HAS NO PRIME NUMBER IN IT
                            if(check_prime(cards[i]) == 0){
                                legit_output[k] = cards[i];                       
                                //CAN ONLY PLAY THESE NO PRIME NUMBER
                                k = k + 1;
                                num_of_legit_output = k;
                            }  
                        }  
                    }
                }else if(num_of_co >= 1){                                         
                    //IF HAVE SAME COMPOSITE NUMBER
                    legit_output[k] = cocom[i];                                   
                    //CAN ONLY PLAY THESE COCOMPOSITE NUMBER
                    k = k + 1;
                    num_of_legit_output = num_of_co; 
                }    
            }
            i = i + 1;
        }
    }else if(cards_played == 0){                                                  
        //IF PLAY FIRST CARD
        i = 0;
        while(i < cards_in_hand){
            if(prime_is_played == 1){                                             
                //IF PRIME IS PLAYED IN HISTORY ROUND
                legit_output[k] = cards[i];                                       
                //PLAY ANY CARD IN HAND
                k = k + 1;
                num_of_legit_output = k; 
            }else if(prime_is_played == 0){                                       
                //IF PRIME IS NOT PLAYED IN HISTORY ROUND
                if(num_of_prime == cards_in_hand){                                
                    //IF ONLY HAVE PRIME CARD
                    legit_output[k] = cards[i];                                   
                    //CAN PLAY THESE PRIME CARD
                    k = k + 1;
                    num_of_legit_output = k;
                }else if(cards_in_hand > num_of_prime){                           
                    //IF NO OTHER NON-PRIME CARD
                    if(check_prime(cards[i]) == 0){
                        legit_output[k] = cards[i];                               
                        //CAN PLAY ANY CARD EXCEPT PRIME CARD
                        k =  k + 1;
                        num_of_legit_output = k;
                    } 
                }
                 
            }i = i + 1;        
        }
    }
    
    //FIND THE DISCARD CARDS
    int discard_cards[MAX] = { },num_of_discards = 3;
    i = 0;
    while(i < num_of_discards){
        scanf("%d" ,&discard_cards[i]);
        i = i + 1;
    }
    //FIND THE RECEIVED CARDS
    int received_cards[MAX] = { },num_of_receive = 3;
    i = 0;
    while(i < num_of_receive){
        scanf("%d" ,&received_cards[i]);
        i = i + 1;
    }
    //FIND THE APPRPOPRIATE OUTPUT 
    int output = 0,max_previous_cards[MAX] = { };
    i = 0;
    if(cards_played == 0){                                                        
        //IF PLAY FIRST
        if(prime_is_played == 1){                                                 
            //IF PRIME IS PLAYED
            if(num_of_prime != 0){                                                
                //IF HAVE PRIME
                output = prime[0];                                                
                while(i < num_of_prime){
                    if(output > prime[i]){                                        
                        //OUTPUT THE LOWEST PRIME NUMBER
                        output = prime[i]; 
                    }
                    i = i + 1;
                }  
            }else if(num_of_prime == 0){                                          
                //IF NOT HAVE PRIME
                output = legit_output[0];
                while(i < num_of_legit_output){
                    if(legit_output[i] < output){                                 
                        //PRINT THE LOWEST NON-PRIME NUMBER
                        output = legit_output[i]; 
                    }
                    i = i + 1;
                }
            }
        }else if(prime_is_played == 0){                                           
            //IF PRIME IS NOT PLAYED
            output = legit_output[0];
            while(i < num_of_legit_output){
                if(output > legit_output[i]){                                     
                    //PRINT THE LOWEST NON-PRIME NUMBER
                    output = legit_output[i]; 
                }
                i = i + 1;
            } 
        }  
    }else if(cards_played > 0){                                                   
        //IF NOT PLAY FIRST
        if(primality==1){                                                       
            //IF FIRST CARD IS PRIME
            if(num_of_prime > 0){                                                 
                //IF HAVE PRIME
                output = 0;
                while(i < num_of_legit_output){                                 
                    //PLAY THE LARGEST CARD IN HAND THAT SMALLER THAN THE PREVIOUS BIGGEST CARD 
                    if(legit_output[i] < max_previous_card){
                        if(legit_output[i] > output){
                            output=legit_output[i];
                        }                                
                    //OUTPUT THE GREATEST CARD WHO IS SMALLER THAN PREVIOUS MAX
                    }
                    i = i + 1;
                }
                if(output == 0){                                    
                    //OUTPUT DOES NOT CHANGE,HENCE NO CARD SAMLLER THAN PREVIOUS MAX
                    i = 0;                   
                    while(i < num_of_legit_output){
                        if(output < legit_output[i]){
                            output = legit_output[i];                             
                        //OUTPUT THE SMALLEST CARD
                        }i = i + 1;
                    }
                }
            }else if(num_of_prime == 0){                                          
                //IF NOT HAVE PRIME
                output = legit_output[0];
                while(i < num_of_legit_output){
                    if(output < legit_output[i]){                                 
                        //CAN OUTPUT THE GREATEST NUMBER IN HAND
                        output = legit_output[i]; 
                    }else if(legit_output[i] == 42){                              
                        //IF LEGIT_OUTPUT=42, OUTPUT IT TO ADD PENALTY POINT TO OTHER PLAYER
                        output = 42;
                        i = num_of_legit_output;
                    }i = i + 1;
                }  
            }
        }else if(primality == 0){                                                 
            //IF FIRST CARD IS NOT PRIME
            if(num_of_co >= 0){                                                   
                //IF HAVE SAME COMPOSITE NUMBER
                output = 0;
                i = 0;
                while(i < num_of_legit_output){
                    if(legit_output[i] == 42 && max_previous_card > 42){      
                        //IF LEGIT_OUTPUT=42, OUTPUT IT IN ORDER TO ADD PENALTY POINT FOR OTHER PLAYER
                        output = 42;
                        i = num_of_legit_output;
                    }else if(legit_output[i] < max_previous_card){ 
                        //IF THERE IS A CARD IN HAND SMALLER THAN PREVIOUS MAX, PLAY THE LARGEST
                        if(legit_output[i] > output){
                            output = legit_output[i];
                        }
                    }
                    i = i + 1;
                }
                if(output == 0){                                    
                    //IF THE OUTPUT DOES NOT CHANGE, NO CARD SAMLLER THAN PREVIOUS MAX
                    output = legit_output[0];
                //OUTPUT THE LEAST
                }
            }else if(num_of_co == 0){                                             
                //IF NOT HAVE SAME COMOPOSITE NUMBER
                if(prime_is_played == 1){                                         
                    //IF PRIME IS PLAYED
                    i = 0;
                    if(num_of_prime > 0){                                         
                        //IF THERE IS PRIME CARD IN HAND
                        while(i < num_of_prime){
                            if(output < prime[i]){                                
                            //OUTPUT THE GREATEST PRIME
                                output = prime[i];
                            }
                            i = i + 1;
                        }   
                    }else{                                                      
                        //IF THERE IS NO PRIME CARD IN HAND
                        while(i < num_of_legit_output){
                            if(output < legit_output[i]){                         
                                //OUTPUT THE GREATEST CARD
                                output = legit_output[i];                               
                            }else if(legit_output[i] == 42){
                                output = 42;
                                i = num_of_legit_output;
                            }
                            i = i + 1;
                        } 
                    }
                }else if(prime_is_played == 0){                                   
                    //IF PRIME IS NOT PLAYED
                    while(i < num_of_legit_output){
                        if(output < legit_output[i]){                             
                            //OUTPUT THE GREATEST CARD
                            output = legit_output[i];                               
                        }else if(legit_output[i] == 42){                          
                            //IF LEGIT_OUTPUT=42, OUTPUT IT TO ADD PENALTY POINT FOR OTHER PLAYER
                            output = 42;
                            i = num_of_legit_output;
                        }
                        i = i + 1;
                    }
                }
            }
        }
    }
    //PRINT OUTPUT
    printf("%d\n" ,output);
}
