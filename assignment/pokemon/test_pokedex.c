// Assignment 2 19T1 COMP1511: Pokedex
// test_pokedex.c
//
// This file allows you to automatically test the functions you
// implement in pokedex.c.
//
// This program was written by Haowei Lou (z5258575)
// on INSERT-DATE-HERE
//
// Version 1.0.0: Assignment released.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "pokedex.h"

// Add your own #defines here.
// Sample data on Squirtle, the Pokemon with pokemon_id 7.
#define SQUIRTLE_ID 7
#define SQUIRTLE_NAME "Squirtle"
#define SQUIRTLE_HEIGHT 0.5
#define SQUIRTLE_WEIGHT 9.0
#define SQUIRTLE_FIRST_TYPE WATER_TYPE
#define SQUIRTLE_SECOND_TYPE NONE_TYPE

// Sample data on Pikachu, the Pokemon with pokemon_id 7.
#define PIKACHU_ID 25
#define PIKACHU_NAME "Pikachu"
#define PIKACHU_HEIGHT 0.4
#define PIKACHU_WEIGHT 6.0
#define PIKACHU_FIRST_TYPE ELECTRIC_TYPE
#define PIKACHU_SECOND_TYPE NONE_TYPE

// Sample data on Bulbasaur, the Pokemon with pokemon_id 1.
#define BULBASAUR_ID 1
#define BULBASAUR_NAME "Bulbasaur"
#define BULBASAUR_HEIGHT 0.7
#define BULBASAUR_WEIGHT 6.9
#define BULBASAUR_FIRST_TYPE GRASS_TYPE
#define BULBASAUR_SECOND_TYPE POISON_TYPE

// Sample data on Ivysaur, the Pokemon with pokemon_id 2.
#define IVYSAUR_ID 2
#define IVYSAUR_NAME "Ivysaur"
#define IVYSAUR_HEIGHT 1.0
#define IVYSAUR_WEIGHT 13.0
#define IVYSAUR_FIRST_TYPE GRASS_TYPE
#define IVYSAUR_SECOND_TYPE POISON_TYPE

// Add your own prototypes here.
static void test_prev_pokemon(void);
static void test_add_pokemon_evolution(void);
static void test_get_type_pokemon(void);

// Tests for Pokedex functions from pokedex.c.
static void test_new_pokedex(void);
static void test_add_pokemon(void);
static void test_next_pokemon(void);
static void test_get_found_pokemon(void);
static void test_search_pokemon(void);


// Helper functions for creating/comparing Pokemon.
static Pokemon create_bulbasaur(void);
static Pokemon create_ivysaur(void);
static Pokemon create_squirtle(void);
static Pokemon create_pikachu(void);
static int same_pokemon(Pokemon A, Pokemon B);



int main(int argc, char *argv[]) {
    printf("Welcome to the COMP1511 Pokedex Tests!\n");

    printf("\n==================== Pokedex Tests ====================\n");

    test_new_pokedex();
    test_add_pokemon();
    test_next_pokemon();
    test_prev_pokemon();
    test_add_pokemon_evolution();
    test_get_found_pokemon();
    test_get_type_pokemon();
    test_search_pokemon();

    printf("\nAll Pokedex tests passed, you are Awesome!\n");
}


////////////////////////////////////////////////////////////////////////
//                     Pokedex Test Functions                         //
////////////////////////////////////////////////////////////////////////

// `test_new_pokedex` checks whether the new_pokedex and destroy_pokedex
// functions work correctly, to the extent that it can.
//
// It does this by creating a new Pokedex, checking that it's not NULL,
// then calling destroy_pokedex.
//
// Note that it isn't possible to check whether destroy_pokedex has
// successfully destroyed/freed the Pokedex, so the best we can do is to
// call the function and make sure that it doesn't crash..
static void test_new_pokedex(void) {
    printf("\n>> Testing new_pokedex\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("       --> Checking that the returned Pokedex is not NULL\n");
    assert(pokedex != NULL);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed new_pokedex tests!\n");
}

// `test_add_pokemon` checks whether the add_pokemon function works
// correctly.
//
// It does this by creating the Pokemon Bulbasaur (using the helper
// functions in this file and the provided code in pokemon.c), and
// calling add_pokemon to add it to the Pokedex.
//
// Some of the ways that you could extend these test would include:
//   - adding additional Pokemon other than just Bulbasaur,
//   - checking whether the currently selected Pokemon is correctly set,
//   - checking that functions such as `count_total_pokemon` return the
//     correct result after more Pokemon are added,
//   - ... and more!
static void test_add_pokemon(void) {
    printf("\n>> Testing add_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    
    printf("    ... Creating Ivysaur\n");
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    
    printf("    ... Adding Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, ivysaur);
    
    printf("       --> Checking Bulbasaur is current select Pokemon\n");
    assert(same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf("       --> Checking total pokemon in the pokedex is 2\n");
    assert(count_total_pokemon(pokedex) == 2);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed add_pokemon tests!\n");
}

// `test_next_pokemon` checks whether the next_pokemon function works
// correctly.
//
// It does this by creating two Pokemon: Bulbasaur and Ivysaur (using
// the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, then checks that calling the
// next_pokemon function changes the currently selected Pokemon from
// Bulbasaur to Ivysaur.
//
// Some of the ways that you could extend these tests would include:
//   - adding even more Pokemon to the Pokedex,
//   - calling the next_pokemon function when there is no "next" Pokemon,
//   - calling the next_pokemon function when there are no Pokemon in
//     the Pokedex,
//   - ... and more!
static void test_next_pokemon(void) {
    printf("\n>> Testing next_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("       --> Checking that the current Pokemon is NULL\n");
    assert(get_current_pokemon(pokedex) == NULL);

    printf("    ... Creating Bulbasaur, Squirtle, Pikachu and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon squirtle = create_squirtle();
    Pokemon pikachu = create_pikachu();    

    printf("    ... Adding 4 created pokemon to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, squirtle);
    add_pokemon(pokedex, pikachu);    

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Squirtle\n");
    assert(same_pokemon(get_current_pokemon(pokedex), squirtle));
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Pikachu\n");
    assert(same_pokemon(get_current_pokemon(pokedex), pikachu));
    
    printf("    ... Moving to the next pokemon when there is no 'next'\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is still Pikachu\n");
    assert(same_pokemon(get_current_pokemon(pokedex), pikachu));

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed next_pokemon tests!\n");
}
// `test_get_found_pokemon` checks whether the get_found_pokemon
// function works correctly.
//
// It does this by creating two Pokemon: Bulbasaur and Ivysaur (using
// the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, sets Bulbasaur to be found, and
// then calls the get_found_pokemon function to get all of the Pokemon
// which have been found (which should be just the one, Bulbasaur).
//
// Some of the ways that you could extend these tests would include:
//   - calling the get_found_pokemon function on an empty Pokedex,
//   - calling the get_found_pokemon function on a Pokedex where none of
//     the Pokemon have been found,
//   - checking that the Pokemon in the new Pokedex are in ascending
//     order of pokemon_id (regardless of the order that they appeared
//     in the original Pokedex),
//   - checking that the currently selected Pokemon in the returned
//     Pokedex has been set correctly,
//   - checking that the original Pokedex has not been modified,
//   - ... and more!
static void test_get_found_pokemon(void) {
    printf("\n>> Testing get_found_pokemon\n");
    
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Getting all found Pokemon when pokedex is empty\n");
    Pokedex found_pokedex = get_found_pokemon(pokedex);
    
    printf("       --> Checking that the found_pokedex is NULL\n");
    assert(get_current_pokemon(found_pokedex) == NULL);
    
    printf("    ... Destroying found_pokedx\n");
    destroy_pokedex(found_pokedex);
    
    printf("    ... Creating Bulbasaur, Pikachu, Squirtle and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon pikachu = create_pikachu();
    Pokemon squirtle = create_squirtle();

    printf("    ... Adding four pokemons into the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, pikachu);
    add_pokemon(pokedex, squirtle);
    
    printf("    ... Getting all found Pokemon when no found pokemon\n");
    assert(count_found_pokemon(pokedex) == 0);
    found_pokedex = get_found_pokemon(pokedex);
    
    printf("       --> Checking that the found_pokedex is NULL\n");
    assert(get_current_pokemon(found_pokedex) == NULL);
    
    printf("    ... Destroying found_pokedx\n");
    destroy_pokedex(found_pokedex);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(get_current_pokemon(pokedex) == bulbasaur);

    printf("    ... Setting Bulbasaur to be found\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Move and find all rest pokemon(Squirtle is last)\n");
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);

    printf("    ... Getting all found Pokemon\n");
    found_pokedex = get_found_pokemon(pokedex);

    printf("       --> Checking the correct Pokemon were returned\n");
    assert(count_total_pokemon(found_pokedex) == 4);
    assert(count_found_pokemon(found_pokedex) == 4);
    
    printf("       --> Checking Pokemons in new pokedex is in correct order\n");
    assert(same_pokemon(get_current_pokemon(found_pokedex), bulbasaur));
    next_pokemon(found_pokedex);
    assert(same_pokemon(get_current_pokemon(found_pokedex), ivysaur));
    next_pokemon(found_pokedex);
    assert(same_pokemon(get_current_pokemon(found_pokedex), squirtle));
    next_pokemon(found_pokedex);
    assert(same_pokemon(get_current_pokemon(found_pokedex), pikachu));
    
    printf("    ... Check original selected pokemon in pokedex not change\n");
    assert(same_pokemon(get_current_pokemon(pokedex), squirtle));
    
    printf("    ... Check original pokedex is not modified\n");
    assert(same_pokemon(get_current_pokemon(pokedex), squirtle));
    prev_pokemon(pokedex);
    assert(same_pokemon(get_current_pokemon(pokedex), pikachu));
    prev_pokemon(pokedex);
    assert(same_pokemon(get_current_pokemon(pokedex), ivysaur));
    prev_pokemon(pokedex);
    assert(same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf("    ... Destroying both Pokedexes\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(found_pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}


// Write your own Pokedex tests here!
// this function will test whether prev_pokemon function will work
static void test_prev_pokemon(void) {
    printf("\n>> Testing prev_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("       --> Checking that the current Pokemon is NULL\n");
    assert(get_current_pokemon(pokedex) == NULL);

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();  

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);    

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Moving to the previous pokemon\n");
    prev_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is still Bulbasaur\n");
    assert(same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Moving to the previous pokemon\n");
    prev_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed prev_pokemon tests!\n");
}

// test_add_pokemon_evolution will test whether the evolute informations are 
// correclty added into the pokedex.
static void test_add_pokemon_evolution(void) {
    printf("\n>> Testing add_pokemon_evolution\n");
     
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur,Pikachu and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon pikachu = create_pikachu();
    
    printf("    ... Adding Bulbasaur, Pikachu and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, pikachu);    
    
    printf("    ... Make Bulbasaur evolve to  Ivysaur\n");
    add_pokemon_evolution(pokedex, BULBASAUR_ID, IVYSAUR_ID);
    
    printf("       --> Check Bulbasaur's evolution is Ivysaur\n");
    assert(same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    assert(get_next_evolution(pokedex) == IVYSAUR_ID);
    
    printf("    ... Make Bulbasaur evolve to Pikachu\n");
    add_pokemon_evolution(pokedex, BULBASAUR_ID, PIKACHU_ID);
    
    printf("       --> Check Bulbasaur's evolution is Pikachu\n");
    assert(same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    assert(get_next_evolution(pokedex) == PIKACHU_ID);
    
    printf(">> Passed add_pokemon_evolution tests!\n");
    
}

// `test_get_type_pokemon` checks whether the get_found_pokemon
// function works correctly.
static void test_get_type_pokemon(void) {
    printf("\n>> Testing get_type_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(get_current_pokemon(pokedex) == bulbasaur);

    printf("    ... Setting Bulbasaur to be found\n");
    find_current_pokemon(pokedex);

    printf("    ... Getting all same type Pokemon\n");
    Pokedex type_pokedex = get_pokemon_of_type(pokedex, BULBASAUR_FIRST_TYPE);
    
    printf("       --> Checking the correct Pokemon were returned\n");
    assert(same_pokemon(get_current_pokemon(type_pokedex), bulbasaur));

    printf("    ... Destroying both Pokedexes\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(type_pokedex);

    printf(">> Passed get_type_pokemon tests!\n");
}

// `test_search_pokemon` checks whether the get_found_pokemon
// function works correctly.
static void test_search_pokemon(void) {
    printf("\n>> Testing search_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(get_current_pokemon(pokedex) == bulbasaur);

    printf("    ... Setting Bulbasaur and Ivysaur to be found\n");
    find_current_pokemon(pokedex);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);

    printf("    ... Getting all fitted Pokemon who contain 'au'\n");
    Pokedex search_pokedex = search_pokemon(pokedex, "au");
    
    printf("       --> Checking the correct Pokemon were returned\n");
    assert(same_pokemon(get_current_pokemon(search_pokedex), bulbasaur));
    next_pokemon(search_pokedex);
    assert(same_pokemon(get_current_pokemon(search_pokedex), ivysaur));

    printf("    ... Destroying both Pokedexes\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(search_pokedex);

    printf(">> Passed search_pokemon tests!\n");
}
////////////////////////////////////////////////////////////////////////
//                     Helper Functions                               //
////////////////////////////////////////////////////////////////////////

// Helper function to create Bulbasaur for testing purposes.
static Pokemon create_bulbasaur(void) {
    Pokemon pokemon = new_pokemon(
            BULBASAUR_ID, BULBASAUR_NAME,
            BULBASAUR_HEIGHT, BULBASAUR_WEIGHT,
            BULBASAUR_FIRST_TYPE,
            BULBASAUR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Ivysaur for testing purposes.
static Pokemon create_ivysaur(void) {
    Pokemon pokemon = new_pokemon(
            IVYSAUR_ID, IVYSAUR_NAME,
            IVYSAUR_HEIGHT, IVYSAUR_WEIGHT,
            IVYSAUR_FIRST_TYPE,
            IVYSAUR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to compare whether two Pokemon are the "same", based
// on whether their attributes match (e.g. id, height, weight, etc).
//
// This function doesn't (yet) check that the Pokemon's names match
// (but perhaps you could add that check yourself...).
static int same_pokemon(Pokemon first, Pokemon second) {
    return (pokemon_id(first) == pokemon_id(second))
    &&  (pokemon_height(first) == pokemon_height(second))
    &&  (pokemon_weight(first) == pokemon_weight(second))
    &&  (pokemon_first_type(first) == pokemon_first_type(second))
    &&  (pokemon_second_type(first) == pokemon_second_type(second));
}

// Write your own helper functions here!

// Helper function to create squirtle for testing purposes.
static Pokemon create_squirtle(void) {
    Pokemon pokemon = new_pokemon(
            SQUIRTLE_ID, SQUIRTLE_NAME,
            SQUIRTLE_HEIGHT, SQUIRTLE_WEIGHT,
            SQUIRTLE_FIRST_TYPE,
            SQUIRTLE_SECOND_TYPE
    );
    return pokemon;
}
// Helper function to create pikachu for testing purposes.
static Pokemon create_pikachu(void) {
    Pokemon pokemon = new_pokemon(
            PIKACHU_ID, PIKACHU_NAME,
            PIKACHU_HEIGHT, PIKACHU_WEIGHT,
            PIKACHU_FIRST_TYPE,
            PIKACHU_SECOND_TYPE
    );
    return pokemon;
}
