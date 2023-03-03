#include <stdio.h>
#include <string.h>
#include <math.h>
#include "util.h"


// sort the letters array based on probability
void sort(data* letters, int no){
    for(int i=0; i<no; i++){
        for(int j=i; j<no; j++){
            if(letters[i].probability > letters[j].probability){
                data aux = letters[i];
                letters[i] = letters[j];
                letters[j] = aux;
            }
        }
    }
}

// reverse the letters array
void reverse(data* letters, int no){
    for(int i=0; i<no/2; i++){
        data aux = letters[i];
        letters[i] = letters[no-1-i];
        letters[no-1-i] = aux;
    }
}

// find the last data struct which word contains
// the to_find string
// returns its encoding string
const char* find(data* letters, int no,const char* to_find, int index){
    for(int i=index; i>0; i--){
        if(strstr(letters[i].word,to_find) != NULL){
            return letters[i].encode;
        }
    }
}

// display all the symbols along with
// their encoded strings
void display_encoded(data* letters, int no){
    for(int i=0; i<no; i++){
        // the .original attribute means if the symbol
        // was read from the user
        // 1 means read from the user (i.e. 'A', 'B')
        // 0 if it was created by program (i.e. "AB")
        if(letters[i].original){
            printf("%s encode: %s\n",letters[i].word,letters[i].encode);
        }
    }
}


// calculate and display the shannon entropy
// and current entropy for our encoding
void display_entropy(data* letters, int no){
    float shanon_entropy = 0, current_entropy;

    for(int i=0; i<no; i++){
        if(letters[i].original){
            shanon_entropy -= letters[i].probability * log2(letters[i].probability);
            current_entropy += letters[i].probability * (float)strlen(letters[i].encode);
        }
    }

    printf("Shanon Entropy: %f\nCurrent Entropy: %f\n",shanon_entropy,current_entropy);
}