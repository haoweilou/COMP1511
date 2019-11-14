//Haowei Lou
//z5258575
//09 April 2019

#include <stdio.h>
#include <string.h>

#define MAX_SPECIES_NAME_LENGTH  128
#define MAX_SIGHTINGS           10000
#define MAX_WHALE_SPECIES         256

// a struct to represent the date
// a whale pod sighting was made

struct date {
    int year;
    int month;
    int day;
};

// a struct to represent a sighting
// of a pod (group) of whales

struct pod {
    struct date when;
    int         how_many;
    char        species[MAX_SPECIES_NAME_LENGTH];
};


int read_sightings_file(char filename[], int len, struct pod sightings[len]);
int read_sighting(FILE *f, struct pod *w);
int read_date(FILE *f, struct date *d);

void whale_summary(int n_sightings, struct pod sightings[n_sightings]);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    struct pod whale_sightings[MAX_SIGHTINGS];
    int n_sightings = read_sightings_file(argv[1], MAX_SIGHTINGS, whale_sightings);

    if (n_sightings < 1) {
        return 1;
    }

    whale_summary(n_sightings, whale_sightings);

    return 0;
}


// a struct definition you can use if you wish

struct tally {
    int  pods;
    int  whales;
    char species[MAX_SPECIES_NAME_LENGTH];
};

//
// print a summary of all whale sightings
//
void whale_summary(int n_sightings, struct pod sightings[n_sightings]) {
    int i=0,j=0,k=0;
    int num_of_whales[MAX_SIGHTINGS]={0};
    int num_of_sightings[MAX_SIGHTINGS]={0};
    int whales=0, sight=0;
    int num_of_species = 0;
    int rep  = 0;                                                               //Assume not rep first
    //Store all species into an array
    char species[MAX_WHALE_SPECIES][MAX_SPECIES_NAME_LENGTH];
    while(i<n_sightings){
    //Store the species of first sighting
        if(i == 0){
            strcpy(species[0],sightings[i].species);
            k=k+1;
            num_of_species = k;
        }
        //Find whether next sighting's whale is same with previous species
        j = 0,rep = 0;
        while(j<num_of_species && i>0){
            if(strcmp(species[j],sightings[i].species)==0){
                rep = 1;
                j = num_of_species;
            }
            j++;
        }
        //If not repeted, store it into species[] array
        if(i>0 && rep == 0){
            strcpy(species[k],sightings[i].species);
            k=k+1;
            num_of_species = k;
        }
        i++;
    }
    //printf("species[%d] is %s\n",0,species[0]);
    i=0, j=0, k=0;
    while(i < num_of_species){
        j = 0,whales = 0, sight = 0;
        while(j < n_sightings){
            if(strcmp(species[i],sightings[j].species)==0){
                whales = whales + sightings[j].how_many;
                sight = sight + 1;
            }
            j++;
        }
        num_of_whales[i] = whales;
        num_of_sightings[i] = sight;
        i = i + 1;
    }
    i = 0;
    while(i<num_of_species){
        printf("%d %s pods containing %d whales\n", num_of_sightings[i], species[i], num_of_whales[i]);
        i=i+1;
    }
}


//
// DO NOT CHANGE THE FUNCTIONS BELOW HERE
//

// return number of sightings read from filename
// -1 is returned if there is an error

int read_sightings_file(char filename[], int len, struct pod sightings[len]) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr,"error: file '%s' can not open\n", filename);
        return -1;
    }

    int n_sightings = 0;
    while (read_sighting(f, &sightings[n_sightings]) == 1 && n_sightings < len) {
        n_sightings = n_sightings + 1;
    }

    fclose(f);
    return n_sightings;
}


// return 1 if a sighting can be read, 0 otherwise

int read_sighting(FILE *f, struct pod *s) {
    if (read_date(f, &(s->when)) != 1) {
        return 0;
    }
    if (fscanf(f, "%d", &(s->how_many)) != 1) {
        return 0;
    }
    fgetc(f);
    if (fgets(s->species, MAX_SPECIES_NAME_LENGTH, f) == NULL) {
        return 0;
    }

    // finish string at '\n' if there is one
    char *newline_ptr = strchr(s->species, '\n');
    if (newline_ptr != NULL) {
        *newline_ptr = '\0';
    }

    // also finish string at '\r' if there is one - files from Windows  will
    newline_ptr = strchr(s->species, '\r');
    if (newline_ptr != NULL) {
        *newline_ptr = '\0';
    }
    return 1;
}


// return 1 if a date can be read, 0 otherwise

int read_date(FILE *f, struct date *d) {
    int n_scanned = fscanf(f, "%d/%d/%d", &(d->year), &(d->month), &(d->day));
    return n_scanned == 3;
}
