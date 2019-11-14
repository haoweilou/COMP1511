#include<stdio.h>
int check_name(char input_text[], char pokemon_name[]){
    //assume true at first
    int check = 0;
    int number_of_input = 0;    
    int i = 0;
    while(input_text[i] != 0){
        number_of_input++;
        i++;
    }
    i = 0;
    int number_of_name = 0;
    while(pokemon_name[i] != 0){
        number_of_name++;
        i++;
    }
    i = 0;
    int j = 0, k = 0;
    while(i < number_of_name){
        if(pokemon_name[i] == input_text[0]){
            k = i;
            while(j < number_of_input){
                if(input_text[j] == pokemon_name[k]){
                    j++;
                    k++;
                    check = 1;
                }else{
                    j = 0;
                    check = 0;
                    break;
                }                
            }
            if(check == 1){
                break;
            }
        }
        i++;
    }
    return check;
}
int main(void){
    char *input = "po";
    char *pokemon_name = "pokemon";
    int check = check_name(input, pokemon_name);
    if(check == 1){
        printf("valid\n");
    }else{
        printf("Invalid\n");
    }
}
