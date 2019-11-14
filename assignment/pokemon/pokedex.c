// Assignment 2 19T1 COMP1511: Pokedex
// pokedex.c
//
// This program was written by Haowei Lou (z5258575)
// on 16 April 2019
//
// Version 1.0.0: Assignment released.
// Version 1.0.1: Minor clarifications about `struct pokenode`.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Add any extra #includes your code needs here.
//
// But note you are not permitted to use functions from string.h
// so do not #include <string.h>

#include "pokedex.h"

// Add your own #defines here.
#define MAX_NAME_LENGTH 10000
#define TRUE 1
#define FALSE 0
#define NO_EVOLUTION -1
#define SAME 1
#define NOT_SAME 0
#define LOWEST_POKEMON_ID -1
#define NONE_TYPE_POKEMON 0
// Note you are not permitted to use arrays in struct pokedex,
// you must use a linked list.
//
// You are also not permitted to use arrays in any of the functions
// below.
//
// The only exception is that char arrays are permitted for
// search_pokemon and functions it may call.
//
// You will need to add fields to struct pokedex.
// You may change or delete the head field.
struct pokedex {
    struct pokenode *head;
    struct pokenode *current;
    struct pokenode *last;
};

// You don't have to use the provided struct pokenode, you are free to
// make your own struct instead.
// If you use the provided struct pokenode, you will need to add fields
// to it to store other information.

struct pokenode {
    struct pokenode *next;
    struct pokenode *previous;
    Pokemon           pokemon;
    int                  find;
    int               from_id;
    int                 to_id;
};

// Add any other structs you define here.


// Add prototypes for any extra functions you create here.
// check_find function checks whether the selected pokemon is found
static int check_find(struct pokenode node);
static int check_name(char input_text[], char pokemon_name[]);
static int check_others(int index, char input_text[], char pokemon_name[]);
static int check_max(Pokedex pokedex);
static int check_minium (Pokedex pokedex, int last_minium, int max);
static int check_reputation (Pokedex pokedex, Pokemon pokemon);
static int count_number_of_pokemon(Pokedex pokedex, int upper_limit);
static void change_character_to_star(Pokemon pokemon);
static void print_pokemon_in_show_evolution(struct pokenode *temp);
static void find_added_pokemon(struct pokenode *head);


// You need to implement the following 20 functions.
// In other words, replace the lines calling fprintf & exit with your code.
// You can find descriptions of what each function should do in pokedex.h


Pokedex new_pokedex(void) {
    Pokedex new_pokedex = malloc(sizeof (struct pokedex));
    assert(new_pokedex != NULL);
    new_pokedex->head = NULL;
    new_pokedex->current = NULL;
    new_pokedex->last = NULL;
    return new_pokedex;
}
////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

void add_pokemon(Pokedex pokedex, Pokemon pokemon) {
    int id_rep = check_reputation(pokedex, pokemon);
    //if the new id is not reputed, keep adding
    if (id_rep == FALSE) {
        struct pokenode *temp = pokedex->last;
        struct pokenode *n = malloc(sizeof(struct pokenode));
        n->pokemon = pokemon;
        n->find = FALSE;
        n->next = NULL;
        n->previous = NULL;
        n->from_id = NO_EVOLUTION;
        n->to_id = NO_EVOLUTION;
        if (pokedex->head == NULL) {
            pokedex->head = n;
            pokedex->current = n;
        } else {
            temp = pokedex->last;
            pokedex->last->next = n;
        }
        pokedex->last = n;
        pokedex->last->previous = temp;
    //if the new id is same with previous ids, exit the program
    } else {
        free(pokemon);
        printf("Id reputated\n");
        exit(1);
    }    
}

void detail_pokemon(Pokedex pokedex) {
    //exit if there is no current pokemon in pokedex
    if (pokedex->current == NULL) {
        return;
    }
    Pokemon current = get_current_pokemon(pokedex);
    int find = check_find(*pokedex->current);
    int id = pokemon_id(current);
    int first_type = pokemon_first_type(current);
    int second_type = pokemon_second_type(current);
    //printf id
    printf("Id: ");
    printf("%03d\n",id);
    if (find == FALSE) {
        printf("Name: ");
        //if pokemon is not found, print the name with '*' with same numbers of
        //characters in the name
        change_character_to_star(current);
        printf("Height: --\n");
        printf("Weight: --\n");
        printf("Type: --\n");
    } else {
        printf("Name: %s\n", pokemon_name(current));
        printf("Height: %.1lfm\n", pokemon_height(current));
        printf("Weight: %.1lfkg\n", pokemon_weight(current));
        printf("Type: %s ", pokemon_type_to_string(first_type));
        if (second_type != 0) {
            printf("%s", pokemon_type_to_string(second_type));
        }
        printf("\n");
    }
}

Pokemon get_current_pokemon(Pokedex pokedex) {
    Pokemon current_pokemon = NULL;
    if (pokedex->current != NULL) {
        current_pokemon = pokedex->current->pokemon;
    }
    return current_pokemon;
}

void find_current_pokemon(Pokedex pokedex) {
    if (pokedex->current == NULL) {
        return;
    }
    pokedex->current->find = TRUE;
}

void print_pokemon(Pokedex pokedex) {
    int id = 0;
    int find = FALSE;
    if (pokedex->head == NULL) {
        return;
    }
    struct pokenode *temp = pokedex->head;
    Pokemon current_pokemon = get_current_pokemon(pokedex);
    Pokemon pokemon = temp->pokemon;
    id = pokemon_id(temp->pokemon);
    while (temp != NULL && temp->pokemon != NULL) {
        pokemon = temp->pokemon;
        //print arrow if the temp->pokemon is sane with the current pokemon
        if (pokemon == current_pokemon) {
            printf("-->");
        } else {
            printf("   ");
        }
        id = pokemon_id(pokemon);
        printf(" #%03d: ",id);
        find = check_find(*temp);
        if (find == FALSE) {
            change_character_to_star(pokemon);
        } else {
            printf("%s\n",pokemon_name(pokemon)); 
        }
        temp = temp->next;
    }
}

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

void next_pokemon(Pokedex pokedex) {
    if (pokedex->head != NULL) {
        if (pokedex->current->next != NULL && pokedex->current->next != NULL) {
            pokedex->current = pokedex->current->next;
        } 
    }
}

void prev_pokemon(Pokedex pokedex) {
    if (pokedex->head != NULL) {
        if (pokedex->current != NULL && pokedex->current->previous != NULL) {
            pokedex->current = pokedex->current->previous;
        }
    }
}

void change_current_pokemon(Pokedex pokedex, int input_id) {
    struct pokenode *temp = pokedex->head;
    int id = 0;
    while (temp != NULL) {
        Pokemon pokemon = temp->pokemon;
        id = pokemon_id(pokemon);
        //change the pokenode current to the pokenode who have same id with 
        //input_id
        if (id == input_id) {
            pokedex->current = temp;
            break;
        }
        temp = temp->next;
    }
}

void remove_pokemon(Pokedex pokedex) {
    if (pokedex->head == NULL) {
        return;
    }
    struct pokenode *upper = pokedex->current->previous;
    struct pokenode *now = pokedex->current;
    struct pokenode *next = pokedex->current->next;
    if (pokedex->current == pokedex->head) {
        upper = NULL;
        pokedex->head->previous = NULL;
    } else if (pokedex->current == pokedex->last) {
        next = NULL;
        pokedex->last->next = NULL;
    }
    //if the removed pokenode is last, no next. Make the previous pokenode be
    //the new last
    if (next == NULL) {
        if (upper != NULL) {
            pokedex->current = upper;
            pokedex->current->next = NULL;
        //if no upper and next, which means pokedex only has one pokemon, then 
        //re-assign head, current and last to be NULL
        } else {
            pokedex->head = NULL;
            pokedex->current = NULL;
            pokedex->last = NULL;
        }
    } else {
        pokedex->current = next;
        //if upper is Null, which means the current pokemon is head, remove it 
        //and make next pokemon be new head
        if (upper == NULL) {
            pokedex->head = pokedex->current;
            pokedex->current->previous = NULL;
        } else {
            pokedex->current->previous = upper;
            upper->next = next;  
        } 
    }
    //remove the current pokenode by free function
    destroy_pokemon(now->pokemon);
    free(now);
}
////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

void go_exploring(Pokedex pokedex, int seed, int factor, int how_many) {
    int id = 0;
    int i = 0;
    int random_find_id = 0;
    int num_of_pokemon = count_number_of_pokemon(pokedex, factor);
    if (num_of_pokemon == 0) {
        printf("There aren't any Pokemon to find with pokemon_id from 0 to ");
        printf("(%d - 1)!\n", factor);
        exit(1);
    }
    srand(seed);
    while (i < how_many) {      
        random_find_id = rand()%(factor) + 0;        
        struct pokenode *temp = pokedex->head;
        while (temp != NULL) {
            id = pokemon_id(temp->pokemon);
            if (id == random_find_id) {
                temp->find = TRUE;
                i = i + 1;
                break;
            }
            temp = temp->next;
        }
    }
}

int count_found_pokemon(Pokedex pokedex) {
    struct pokenode *temp = pokedex->head;
    int num_of_found_pokemon = 0;
    while (temp != NULL) {
        if (temp->find == TRUE) {
            num_of_found_pokemon++;
        }
        temp = temp->next;
    }
    return num_of_found_pokemon;
}

int count_total_pokemon(Pokedex pokedex) {
    struct pokenode *temp = pokedex->head;
    int num_of_total_pokemon = 0;
    while (temp != NULL) {
        num_of_total_pokemon++;
        temp = temp->next;
    }
    return num_of_total_pokemon;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

void add_pokemon_evolution(Pokedex pokedex, int from_id, int to_id) {
    struct pokenode *check = pokedex->head;
    int from = NOT_SAME, to = NOT_SAME;
    //check whether the pokedex contain pokemon who has same id with from_id and
    //to_id
    while (check != NULL) {
        if (pokemon_id(check->pokemon) == from_id) {
            from = SAME;
        }
        if (pokemon_id(check->pokemon) == to_id) {
            to = SAME;
        }
        check = check->next;
    }
    if (from == NOT_SAME || to == NOT_SAME) {
        printf("No pokemon with 'from_id' or 'to_id' in the pokedex\n");
        exit(1);
    }
    //find the pokemon who has from_id and make its to_id be the to_id given
    struct pokenode *temp1 = pokedex->head;
    int current_id = 0;
    while (temp1 != NULL) {
        current_id = pokemon_id(temp1->pokemon);
        if (from_id == current_id) {
            temp1->to_id = to_id;
            break;
        }
        temp1 = temp1->next;
    }
    //find the pokemon who has to_id and make its from_id be from_id given
    struct pokenode *temp2 = pokedex->head;
    while (temp2 != NULL) {
        current_id = pokemon_id(temp2->pokemon);
        //overide the pokemon who has same from_id but is not equal to to_id
        if (temp2->from_id == from_id && current_id != to_id) {
            temp2->from_id = NO_EVOLUTION;
        }
        if (to_id == current_id) {
            temp2->from_id = from_id;
        }
        temp2 = temp2->next;
    }
}

void show_evolutions(Pokedex pokedex) {
    if (pokedex->current == NULL) {
        return;
    }
    //print the current selected pokemon
    print_pokemon_in_show_evolution(pokedex->current);
    struct pokenode *temp = pokedex->head;
    int next_id = pokedex->current->to_id;
    while (temp != NULL) {
        int current_id = pokemon_id(temp->pokemon);
        if (next_id == current_id) {
            printf(" --> ");
            //print the pokemon who has the id equal 'to_id' with temp 
            print_pokemon_in_show_evolution(temp);
            //if there still has evolute information, start while loop from head
            if (temp->to_id != NO_EVOLUTION) {
                next_id = temp->to_id;
                temp = pokedex->head;
            //break the loop and stop show_evolution function
            } else {
                break;
            }
        }
        temp = temp->next;
    }
    printf("\n"); 
}

int get_next_evolution(Pokedex pokedex) {
    struct pokenode *temp = pokedex->current;
    if (temp == NULL) {
        printf("empty pokedex\n");
        exit(1);
    }
    if (temp->to_id == NO_EVOLUTION) {
        return DOES_NOT_EVOLVE;
    } else {
        int evol_id = temp->to_id;
        return evol_id;
    }
}

////////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                          //
////////////////////////////////////////////////////////////////////////

Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {
    if (type == NONE_TYPE || type == INVALID_TYPE || type == MAX_TYPE) {
        printf("Invalid input type\n");
        exit(1);
    }
    Pokedex type_pokedex = new_pokedex();
    struct pokenode *temp = pokedex->head;
    Pokemon pokemon = temp->pokemon;
    int type1 = NONE_TYPE_POKEMON, type2 = NONE_TYPE_POKEMON;
    type_pokedex->head = NULL;
    int find = TRUE;
    while (temp != NULL) {
        pokemon = temp->pokemon;
        find = check_find(*temp);
        if (find == TRUE) {
            type1 = pokemon_first_type(pokemon);
            type2 = pokemon_second_type(pokemon);
            if ((type1 == type || type2 == type)) {
                Pokemon new_pokemon = clone_pokemon(temp->pokemon);
                add_pokemon(type_pokedex, new_pokemon);
                find_added_pokemon(type_pokedex->head);               
            } 
        }
        temp = temp->next;
    }
    return type_pokedex;
}

Pokedex get_found_pokemon(Pokedex pokedex) {
    Pokedex found = new_pokedex();
    struct pokenode *temp = pokedex->head;
    int maximum = check_max(pokedex);
    int minium = maximum, last_minium = LOWEST_POKEMON_ID;
    found->head = NULL; 
    while (temp != NULL) {
        minium = check_minium(pokedex, last_minium, maximum);
        last_minium = minium;
        struct pokenode *new_temp = pokedex->head;
        //only add the pokemon if there exsits a minium id who is greater than 
        //previous minium value and is found & shortes in the remain value 
        while (new_temp != NULL) {  
            if (pokemon_id(new_temp->pokemon) == minium) {
                Pokemon new_pokemon = clone_pokemon(new_temp->pokemon);
                add_pokemon(found, new_pokemon);
                find_added_pokemon(found->head);
                break;
            }
            new_temp = new_temp->next;
        }
        temp = temp->next;
    }
    return found;
}

Pokedex search_pokemon(Pokedex pokedex, char *text) {
    Pokedex search = new_pokedex();
    struct pokenode *temp = pokedex->head;
    int find = TRUE;
    int check = TRUE;
    while (temp != NULL) {
        find = check_find(*temp);
        if (find == TRUE) {
            check = check_name(text, pokemon_name(temp->pokemon));
            //add pokemon into pokedex if this function pass the check_name
            //function
            if (check == TRUE) {
                Pokemon new_pokemon = clone_pokemon(temp->pokemon);
                add_pokemon(search, new_pokemon);
                find_added_pokemon(search->head);
            }
        }
        temp = temp->next;
    }
    return search;
}

void destroy_pokedex(Pokedex pokedex) {
    struct pokenode *temp = pokedex->head;
    struct pokenode *previous = pokedex->head;
    while (temp != NULL) {
        previous = temp;
        destroy_pokemon(temp->pokemon);
        temp = temp->next;
        free(previous);
    }
    free(pokedex);
}
// Add definitions for your own functions below.
// Make them static to limit their scope to this file.

// check_find function checks whether the selected pokemon is found
static int check_find(struct pokenode node) {
    int find =  node.find;
    return find;
}

// check_name function will check if the pokemon's name contain strings that
// searched in the get_search_pokedex function. Two characters with different
// cases should be considered as same, where 'Ao' and 'aO' is same
static int check_name(char input_text[], char pokemon_name[]) {
    int check = FALSE;
    //count number of characters in pokemon's name
    int i = 0, j = 0;
    int number_of_name = 0;
    while (pokemon_name[i] != 0) {
        number_of_name++;
        i++;
    }
    //change the character from upper to lower case 'A_a' and lower to upper
    //case 'a_A'
    int A_a = 'A' - 'a';
    int a_A = 'a' - 'A';
    i = 0, j = 0;
    int first = input_text[0];
    while (i < number_of_name) {
        int pok = pokemon_name[i];
        //if there is a character in the pokemon's name is same with the first
        //word in input_text, operating check full name function
        if ((pok == first) || (pok + a_A == first) || (pok + A_a == first)) {
            check = check_others(i, input_text, pokemon_name);
            if (check == TRUE) {
                break;
            }
        }
        i++;
    }
    return check;
}

// check_others function will check whether input_text are same with some part
// of pokemon_name
static int check_others(int index, char input_text[], char pokemon_name[]) {
    int check = TRUE;
    int A_a = 'A' - 'a';
    int a_A = 'a' - 'A';
    int i = 0, j = index;
    int number_of_input = 0;
    while (input_text[i] != 0) {
        number_of_input++;
        i++;
    }
    i = 0;
    //check whether remain character are same with remain characters in input
    //text
    while (i < number_of_input) {
        int po = pokemon_name[j];
        int in = input_text[i];
        if ((in == po) || (in + a_A == po) || (in + A_a == po)) {
            j++;
            i++;
            check = TRUE;
        } else {;
            check = FALSE;
            break;               
        }
    }
    return check;
}

// check_max function will find and return the maximum id of pokemon in pokedex
static int check_max(Pokedex pokedex) {
    int max = -1;
    struct pokenode *temp = pokedex->head;
    while (temp != NULL) {
        int id = pokemon_id(temp->pokemon);
        if (id > max) {
            max = id;
        }
        temp = temp->next;
    }
    return max;

}

// check_minium function will find and return the minium id of pokemon in the
// pokedex so pokemons can be sorted in order in the found_pokedex. 
// Last_minium refer to the previous minium number, the new minium should
// greater than previous minium number. otherwise the function will always
// return the id with minimum number rather than order them from lowest to
// greatest.
static int check_minium(Pokedex pokedex, int last_minium, int max) {
    struct pokenode *temp = pokedex->head;
    int minium = max+1;
    while (temp != NULL) {
        int id = pokemon_id(temp->pokemon);
        int find = check_find(*temp);
        if (find == TRUE) {
            if (id > last_minium && minium > id) {
                minium = id;
            }
        }
        temp = temp->next;
    }
    return minium;
}

// check_reputation function whether the new pokemon's Id is same with the
// id of pokemons that has already been stored in the pokedex. If it does, this
// function will return False and stop adding this pokemon into pokedex
static int check_reputation(Pokedex pokedex, Pokemon pokemon) {
    int id_rep = FALSE;
    struct pokenode *temp = pokedex->head;
    int id = pokemon_id(pokemon);
    while (temp != NULL) {
        if (id == pokemon_id(temp->pokemon)) {
            id_rep = TRUE;
            break;
        }
        temp = temp->next;
    }
    return id_rep;
}

// count_number_of_pokemon function will check the number of pokemon lower than
// the limit defiend by exploring command
static int count_number_of_pokemon(Pokedex pokedex, int upper_limit) {
    int num_of_pokemon = 0;
    struct pokenode *temp = pokedex->head;
    while (temp != NULL) {
        if (pokemon_id(temp->pokemon) < upper_limit) {
            num_of_pokemon++;
        }
        temp = temp->next;
    }
    return num_of_pokemon;
}

// change_character_to_star will change the pokemon's name to '*' if pokemon is 
// not found 
static void change_character_to_star(Pokemon pokemon) { 
    int i = 0;
    while (pokemon_name(pokemon) [i] != 0) {
        printf("*");
        i++;
    }printf("\n");
}

// print_pokemon_in_show_evolution will print the pokemon when show_evolution is 
// called with required format
static void print_pokemon_in_show_evolution(struct pokenode *temp) {
    int id = 0;
    int first_type = pokemon_first_type(temp->pokemon);
    int second_type = pokemon_second_type(temp->pokemon);
    id = pokemon_id(temp->pokemon);
    printf("#%03d ",id);
    if (temp->find == TRUE) {
        printf("%s ", pokemon_name(temp->pokemon));
    } else {
        printf("???? ");
    }
    printf("[");
    if (temp->find == TRUE) {
        printf("%s", pokemon_type_to_string(first_type));
        if (second_type != NONE_TYPE_POKEMON) {
            printf(", %s", pokemon_type_to_string(second_type));
        }
    } else {
        printf("????");
    }
    printf("]");
}

// find_added_pokemon function will set all of pokemon in the new created 
// pokedex as 'find' so the detail, print function working properly.
static void find_added_pokemon(struct pokenode *head) {
    struct pokenode *temp = head;
    while (temp != NULL) {
        temp->find = TRUE;
        temp = temp->next;
    }
}
