//2019 HARSHAVARDHAN

#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>
#include <stdio.h>

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

HEAP_NODE* init_heap_node(char data, int freq) {

    HEAP_NODE* node = (HEAP_NODE*) malloc(sizeof(HEAP_NODE));

    node->frequency = freq;
    node->data = data;

    node->right = NULL;
    node->left = NULL;

    return node;
}

HEAP* init_heap(unsigned int capacity) {

    HEAP* heap = (HEAP*) malloc(sizeof(HEAP));

    heap->capacity = capacity;
    heap->size = 0;

    heap->array = (HEAP_NODE**) malloc(sizeof(HEAP_NODE*) * capacity);

    return heap;
}

void min_heapify(HEAP* heap, int index) {

    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < heap->size && heap->array[left] < heap->array[smallest]) {
        smallest = left;
    }

    if(right < heap->size && heap->array[right] < heap->array[smallest]) {
        smallest = right;
    }

    if(smallest != index) 
        swap(&heap->array[smallest], &heap->array[index]);
    
    min_heapify(heap, smallest);
}

void max_heapify(HEAP* heap, int index) {

    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < heap->size && heap->array[left] > heap->array[largest]) {
        largest = left;
    }

    if(right < heap->size && heap->array[right] < heap->array[largest]) {
        largest = right;
    }

    if(largest != index) 
        swap(&heap->array[largest], &heap->array[index]);
    
    min_heapify(heap, largest);
}

HEAP_NODE* extract_min(HEAP* heap) {

    HEAP_NODE* node = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;

    min_heapify(heap, 0);

    return node;
}

int get_parent(int index) {

    if(index <= 0) {
        printf("Cannot get index of root\n");
        return -1;
    }

    return (index - 1) / 2;
}

int is_leaf(HEAP_NODE* node) {
    return node->left == NULL || node->right == NULL;
}

void insert(HEAP* heap, HEAP_NODE* node) {

    heap->size++;
    int index = heap->size - 1;
    

    while(index > 1 && (node->frequency < heap->array[get_parent(index)]->frequency)) {
        heap->array[index] = heap->array[get_parent(index)];
        index = get_parent(index);
    }

    heap->array[index] = node;
}

void build_heap(HEAP*  heap) {

    for(int i = (heap->size - 1) / 2; i >= 0; i--) {
        min_heapify(heap, i);
    }
}

void print_array(int* arr, int size) {
    
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
}

int is_leaf(HEAP_NODE* node) {
    return !(node->left) && !(node->right);
}

HEAP* create_build(char data[], int frequency[], int size) {

    HEAP* heap = init_heap(size);

    for(int i = 0; i < size; i++) {
        heap->array[i] = init_heap_node(data[i], frequency[i]);
    }

    heap->size = size;

    build_heap(heap);
}

#endif