#include "heap.h"

int main() {

    Heap* heap = init_heap(15);

    for(int i = 10; i > 0; i--) {
        make_min_heap(heap, i);
    }

    print_heap_arr(heap);
    heap_sort(heap);
    print_heap_arr(heap);

    return 0;
}