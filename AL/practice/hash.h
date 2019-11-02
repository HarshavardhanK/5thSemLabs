#ifndef HASH_H
#define HASH_H

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct table_node {
    struct table_node *next;
    char* val;
};

typedef struct table_node T_node;

T_node* init_node(char* val) {

    T_node* node = (T_node*) malloc(sizeof(T_node));

    int len = strlen(val);

    node->val = (char*) malloc(sizeof(char) * len);
    strcpy(node->val, val);
    node->next = NULL;

    return node;
}

struct hash_table {

    T_node** table;
    int buckets;
};

typedef struct hash_table Hash;

Hash* init_hash(int buckets) {

    Hash* table = (Hash*)malloc(sizeof(Hash));
    table->table = (T_node**)malloc(sizeof(T_node**) * buckets);
    table->buckets = buckets;

    for(int i = 0; i < buckets; i++)
        table->table[i] = NULL;

    return table;
}

int hash_function(Hash*hash, char* data) {

    int weighted_sum = 0;

    for(int i = 0; data[i] != '\0'; i++) {
        weighted_sum += i * data[i];
    }

    return weighted_sum % hash->buckets;

}

void hash(Hash* table, char * data) {

    int bucket = hash_function(table, data);
    //printf("Bucket: %d\n", bucket);

    T_node* insert = init_node(data);

    if(table->table[bucket] != NULL) {
       // printf("Chaining %s\n", data);
        insert->next = table->table[bucket];
        table->table[bucket] = insert;

    } else {
       // printf("Normal insert %s\n", data);
        table->table[bucket] = insert;
    }

}

int search(Hash* table, char* data) {

    int bucket = hash_function(table, data);

    printf("Searching \"%s\" in bucket %d\n", data, bucket);

    int chain = 0;

    if(strcmp(table->table[bucket]->val, data) == 0) {
        return -1;

    } else {

        T_node* iter = table->table[bucket];

        while(iter) {
            iter = iter->next;
            chain++;

            if(iter)
            
                if(strcmp(iter->val, data) == 0) {
                    return chain;
                }
        }
    }

    return 0;

}

void print_hash_table(Hash* table) {

    if(table) {

        for(int i = 0; i < table->buckets; i++) {
            printf("Bucket %d: ", i);

            T_node* node = table->table[i];

            while(node) {
                printf("%s->", node->val);
                node = node->next;
            }

            printf("\n");
        }

        printf("\n");

    }
}


#endif