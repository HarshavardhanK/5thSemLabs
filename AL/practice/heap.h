#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct heap_node {

    int data;
   
};

typedef struct heap_node H_Node;

struct heap {

    H_Node* arr;
    int capacity;
    int size;
};

typedef struct heap Heap;

void swap(H_Node* A, H_Node* B) {

    H_Node tmp = *A;
    *A = *B;
    *B = tmp;
    
}

H_Node create_heap_node(int data) {

    H_Node node;
    node.data = data;

    return node;
}

Heap* init_heap(int capacity) {

    Heap* heap = (Heap*) malloc(sizeof(Heap));
    heap->arr = (H_Node*) malloc(sizeof(H_Node*) * capacity);

    heap->capacity = capacity;
    heap->size = 0;

    return heap;
}

int left(int index) {
    return 2 * index + 1;
}

int right(int index) {
    return 2 * index + 1;
}

int parent(int index) {
    return (index - 1) / 2;
}

void insert(Heap* heap, int key) {

    if(heap->size == heap->capacity) {
        return;
    }

    heap->size++;

    H_Node node = create_heap_node(key);
    int insert_index = heap->size - 1;
    heap->arr[insert_index] = node;
    
    while(insert_index != 0 && heap->arr[parent(insert_index)].data > heap->arr[insert_index].data) {
        swap(&heap->arr[parent(insert_index)], &heap->arr[insert_index]);
        insert_index = parent(insert_index);
    }

    printf("%d ", node.data);

}

void heapify(Heap* heap, int index) {

    if(heap) {

        int smallest = index; 
        
        if(left(index) < heap->size && heap->arr[left(index)].data < heap->arr[smallest].data) 
            smallest = left(index);
        
        if(right(index) < heap->size && heap->arr[right(index)].data < heap->arr[smallest].data)
            smallest = left(index);
        
        if(smallest != index) {
            swap(&heap->arr[smallest], &heap->arr[index]);
            heapify(heap, smallest);
        }
    
    } else {
        printf("Heapify Error: Heap empty\n");
    }
}

H_Node extract_min(Heap* heap) {

    if(heap->size == 1) {
        H_Node node = heap->arr[0];
        heap->size--;

        return node;

    } else {

        H_Node node = heap->arr[0];
        heap->arr[0] = heap->arr[heap->size - 1];
        heap->size--;

        heapify(heap, 0);

        return node;
    }
}

void decrease_key(Heap* heap, int index, int value) {

    if(heap) {

        heap->arr[index] = create_heap_node(value);
        
        while(index != 0 && heap->arr[parent(index)].data > heap->arr[index].data) {
            swap(&heap->arr[parent(index)], &heap->arr[index]);
            index = parent(index);
        }
    }
}

void delete_key(Heap* heap, int index) {

    decrease_key(heap, index, INT_MIN);
    extract_min(heap);

}

//Utilities
void print_heap(Heap* heap) {

    if(heap) {

        if(heap->arr) {

            for(int i = 0; i < heap->size; i++) 
                printf("%d ", heap->arr[i].data);
                
            printf("\n");

        } else {
            printf("HEAP ARR ERROR: Empty");
        }

    } else {
        printf("HEAP ERROR: NOT FOUND");
    }
}



#endif