#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct heap {
    int* arr;
    int capacity;
    int size;
};

typedef struct heap Heap;

Heap* init_heap(int capacity) {

    Heap* heap = (Heap*) malloc(sizeof(Heap));
    heap->arr = (int*) malloc(sizeof(int) * capacity);
    heap->capacity = capacity;
    heap->size = 0;

    return heap;
}

int parent(int index) {
    return (index - 1) / 2;
}

int left(int index) {
    return 2 * index + 1;
}

int right(int index) {
    return 2 * index + 2;
}

void make_min_heap(Heap* heap, int key) {

    if(heap->size == heap->capacity) {
        return;
    }

    heap->size++;

    int insert_index = heap->size - 1;
    heap->arr[insert_index] = key;

    while(insert_index != 0 && heap->arr[parent(insert_index)] > heap->arr[insert_index]) {
        swap(&heap->arr[insert_index], &heap->arr[parent(insert_index)]);
        insert_index = parent(insert_index);
    }

    printf("inserted %d into heap\n", key);
}

void heapify(Heap* heap, int index) {

    if(heap) {

        int largest = index;
        int left = largest * 2 + 1;
        int right = largest * 2 + 2;

        if(left < heap->size && heap->arr[left] > heap->arr[largest]) {
            largest = left;
        }

        if(right < heap->size && heap->arr[right] > heap->arr[largest]) {
            largest = right;
        }

        if(largest != index) {
            swap(&heap->arr[index], &heap->arr[largest]);
            heapify(heap, largest);
        }
    }
}



#endif