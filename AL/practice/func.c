#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int comp (const void* a, const void* b) {
   return ( *(int*)a - *(int*)b );
   return a > b;
}

void print_arr(int* arr, int size) {
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

struct node {
    int data;
};

typedef struct node Node;

int comp_node(const void *a, const void *b) {
    return ((Node*)a)->data > ((Node*)b)->data;
}

void test_node() {

    Node n1 = {23}; Node n2 = {3}; Node n3 = {22}; Node n4 = {20}; Node n5 = {0};
    Node arr[4] = {n1, n2, n3, n4}
}

int main() {

    const int size = 4;

    int *arr = (int*) malloc(sizeof(int) * size);

    for(int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    

    qsort(arr, size, sizeof(arr[0]), comp);

    print_arr(arr, size);

    return 0;


    
}