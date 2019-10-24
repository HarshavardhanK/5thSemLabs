#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>

struct min_heap_node {

    char data;
    unsigned int frequency;

    struct min_heap_node* right;
    struct min_heap_node* left;
};

typedef struct min_heap_node HEAP_NODE;

struct min_heap {

    unsigned int size;
    unsigned int capacity;

    HEAP_NODE** array;
};

typedef struct min_heap HEAP;

void swap(HEAP_NODE** A, HEAP_NODE** B) {
    HEAP_NODE *tmp = *A;
    *A = *B;
    *B = tmp;
}

HEAP* init_heap(unsigned int capacity) {

    HEAP* heap = (HEAP*) malloc(sizeof(HEAP));

    heap->capacity = capacity;
    heap->size = 0;

    heap->array = (HEAP_NODE**) malloc(sizeof(HEAP_NODE*) * capacity);

    return heap;
}





#endif