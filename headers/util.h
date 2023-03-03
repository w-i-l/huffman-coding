#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED


#define MAX_CHARS 1000
typedef struct{
    char word[MAX_CHARS];
    char encode[MAX_CHARS];
    int original;
    float probability;
}data;


void sort(data* letters, int no);
void reverse(data* letters, int no);
const char* find(data* letters, int no,const char* to_find, int index);
void display_encoded(data* letters, int no);
void display_entropy(data* letters, int no);

#endif // UTIL_H_INCLUDED