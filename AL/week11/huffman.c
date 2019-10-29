#include "heap.h"

HEAP* create_build(char data[], int frequency[], int size) {

    HEAP* heap = init_heap(size);

    for(int i = 0; i < size; i++) {
        heap->array[i] = init_heap_node(data[i], frequency[i]);
    }

    heap->size = size;

    build_heap(heap);
}

HEAP_NODE* build_huffman(char data[], int frequency[], int size) {

    HEAP_NODE* left;
    HEAP_NODE* right;
    HEAP_NODE* top;

    HEAP* heap = create_build(data, frequency, size);

    while(heap->size != 1) {

        left = extract_min(heap);
        right = extract_min(heap);

        top = init_heap_node('$', left->frequency + right->frequency);

        top->left = left;
        top->right = right;

        insert(heap, top);
    }

    return extract_min(heap); 
}