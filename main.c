#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "heap.h"

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

// read and store the data in a dynamic allocated array
data* read_data(int *no){

    int no_of_chars;
    printf("How many chars?: ");
    scanf("%d",&no_of_chars);
    printf("\n");

    data* letters = malloc((2*no_of_chars-1) * sizeof(data));

    if(letters == NULL){
        return NULL;
    }

    // data read
    int i=0;
    for(i=0; i<no_of_chars; i++){
        printf("Char_no %i: ",i);
        scanf("\n%s",letters[i].word);

        printf("Prob_no %i: ",i);
        scanf("%g",&letters[i].probability);

        printf("\n");

        letters[i].original = 1;
    }

    // update the array item's number
    *no = i;

    return letters;
}

// adds to letters array the missing nodes
// to complete the huffman heap
void complete_nodes(data* letters, int* no){

    // current index of letters
    int i = *no;
    // the smallest items in array
    int j=0,k=1;

    while(j < 2*(*no)-1 && k < 2*(*no)-1 ){

        // letters[i] is the new node that combines
        // the smallest probability nodes


        // calculating the probability
        letters[i].probability = letters[j].probability + letters[k].probability;

        //combines the two symbols of the nodes
        strcpy(letters[i].word,letters[j].word);
        strcat(letters[i].word,letters[k].word);

        i++;
        // rearrange the array
        sort(letters,i);
        j+=2;
        k+=2;
    }

    // update the array item's number
    *no = i;

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

// encode the symbol based on its position in the heap
void encode(data* letters, int no){
    for(int i=1; i<no; i++){
        // if it is the first two nodes we manually allocate
        if(i==1 || i == 2){
            strcat(letters[i].encode, i%2==0 ? "1" : "0");
        }
        else{
            // we search for its parent node and use its encoded string
            strcat(letters[i].encode,find(letters,no,letters[i].word,i-1));
            // than add the corresponding code
            strcat(letters[i].encode, i%2==0 ? "1" : "0");
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

int main()
{
    int x;
    data* store = read_data(&x);

    sort(store,x);

    complete_nodes(store,&x);

    reverse(store,x);
    encode(store,x);

    display_encoded(store,x);
    display_entropy(store,x);

    free(store);


    return 0;
}
