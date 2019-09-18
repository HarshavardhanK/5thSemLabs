#include "heap.h"

int main() {

    Heap* heap = init_heap(5);

    for(int i = 1; i < 6; i++) {
        make_min_heap(heap, rand() % (i * 3 + 7));
    }

    return 0;
}