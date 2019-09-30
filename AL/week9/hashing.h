#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char** table;
    int size;
} dict;

dict* init_dict(int size) {

    dict* new_dict = (dict*) malloc(sizeof(dict));
    new_dict->table = (char**) malloc(sizeof(char*) * size);
    new_dict->size = size;

    for(int i = 0; i < new_dict->size; i++) {
        new_dict->table[i] = (char*) malloc(sizeof(char) * 10);
        strcpy(new_dict->table[i], "EMPTY");
    }

    return new_dict;
}

int hash(char* data, dict* _dict_) {
    
    int count = 0;

    for(int i = 0; data[i] != '\0'; i++) 
        count = data[i] * i;

    return count % _dict_->size; 
}

void store(char* data, dict* _dict_) {

    int key = hash(data, _dict_);
    printf("Key: %d\n", key);

    strcpy(_dict_->table[key], data);
}

int get(char* str, dict* _dict_) {

    if(str) {

        int key = hash(str, _dict_);

        if(strcmp(str, _dict_->table[key]) == 0) {
            return key;
        }
    }

    return -1;
}

// UTILS

void print_table(dict* _dict_) {

    printf("Printing (key, value)\n");

    for(int i = 0; i < _dict_->size; i++) {

        if(strcmp(_dict_->table[i], "EMPTY") != 0)
            printf("(%d, %s) ", i, _dict_->table[i]);
    }

    printf("\n");
}

