#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "util.h"




// read and store the data in a dynamic allocated array
data* read_data(int *no){

    int no_of_chars;
    printf("How many chars?: ");
    scanf("%d",&no_of_chars);
    printf("\n");

    data* letters = (data*)malloc((2*no_of_chars-1) * sizeof(data));

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



// encode the symbol based on its position in the heap
void encode(data* letters, int no, int reverse){

    // to change the encoded version from standard(i.e. left = 0, right = 1)
    char left[2], right[2];
    strcpy(left,(reverse == 0 ? "1" : "0"));
    strcpy(right, reverse == 0 ? "0" : "1");

    for(int i=1; i<no; i++){

        // if it is the first two nodes we manually allocate
        if(i==1 || i == 2){
            strcat(letters[i].encode, i%2==0 ? left: right);
        }
        else{
            // we search for its parent node and use its encoded string
            strcat(letters[i].encode,find(letters,no,letters[i].word,i-1));
            // than add the corresponding code
            strcat(letters[i].encode, i%2==0 ? left : right);
        }
    }
}




int main()
{   
    
    int x;
    data* store = read_data(&x);

    sort(store,x);

    complete_nodes(store,&x);

    reverse(store,x);
    encode(store,x,0);

    display_encoded(store,x);
    display_entropy(store,x);

    free(store);


    return 0;
}
