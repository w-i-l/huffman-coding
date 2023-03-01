#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "heap.h"

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

data* read_data(int *no){

    int no_of_chars;
    printf("How many chars?: ");
    scanf("%d",&no_of_chars);
    printf("\n");

    data* letters = malloc((2*no_of_chars-1) * sizeof(data));
    printf("before rea : %p\n",letters);

    if(letters == NULL){
        return NULL;
    }

    int i=0;
    for(i=0; i<no_of_chars; i++){
        printf("Char_no %i: ",i);
        scanf("\n%s",letters[i].word);
        printf("Prob_no %i: ",i);
        scanf("%g",&letters[i].probability);
        printf("\n");
    }

    *no = i;
    return letters;
}

void complete_nodes(data* letters, int* no){

    //letters = realloc(letters, (2*(*no)-1) * sizeof(data));
    //printf("After rea : %p\n",letters);
    //printf("%s %f\n",letters[0].word,letters[0].probability);
    //sort(letters,*no);
    //printf("%s %f\n",letters[0].word,letters[0].probability);
    int i = *no;
    //printf("size: %d\n",(2*(*no)-1));
    int j=0,k=1;

    while(j < 2*(*no)-1 && k < 2*(*no)-1 ){
        letters[i].probability = letters[j].probability + letters[k].probability;
        strcpy(letters[i].word,letters[j].word);
        strcat(letters[i].word,letters[k].word);
        printf("prob: %f\n",letters[i].probability);
        i++;
        sort(letters,i);
        j++;
        k++;
    }

    *no = i;

}

int main()
{
    int x;
    data* store = read_data(&x);
    for(int i=0;i<x;i++){
        printf("%s - %f\n",store[i].word,store[i].probability);
    }
    printf("sorted:\n");
    sort(store,x);
    for(int i=0;i<x;i++){
        printf("%s - %f\n",store[i].word,store[i].probability);
    }
    printf("\n");
        complete_nodes(store,&x);
    for(int i=0;i<x;i++){
        printf("%s - %f\n",store[i].word,store[i].probability);
    }


    return 0;
}
