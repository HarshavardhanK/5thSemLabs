#include <stdio.h>
#include <stdlib.h>


void print_arr(int* arr, int size) {
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}


int count = 0;

void heap_permutations(int* arr, int size, int n) {

    if(size == 1) {
        count++;
        print_arr(arr, n);
        return;

    }

    for(int i = 0; i < size; i++) {
        heap_permutations(arr, size - 1, n);

        //if size is odd swap 1st and last element
        if(size % 2) {
            swap(&arr[0], &arr[size - 1]);

        } else {
            swap(&arr[i], &arr[size - 1]);
        }
    }
}

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    heap_permutations(arr, 15, 15);

    printf("Times: %d\n", count);

    return 0;
}