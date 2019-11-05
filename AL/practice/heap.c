#include "heap.h"

void test() {

    int size = 10;

    Heap* heap = init_heap(size);

    for(int i = 0; i < size; i++) {
        int data = rand() % 13 + 1;
        insert(heap, data);

    }

    printf("Heap size: %d\n", heap->size);
        
    
    heapify(heap, 0);
    //printf("%d\n", heap->arr[0]->data);
    print_heap(heap);

    H_Node min = extract_min(heap);
    printf("Min node: %d\n", min.data);

    delete_key(heap, 3);
    print_heap(heap);
    
}

int main() {
    test();

    return 0;
}