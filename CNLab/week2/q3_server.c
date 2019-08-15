
#include "server.h"

void print_array(int arr[], int size) {

    printf("\n");

    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
int selectionSort(int* arr, int n) { 

    printf("this is server task\n");
    printf("n is %d\n", n);
    print_buffer((void*)&arr, n, INT);

    for (int i = 0; i < n-1; i++) { 
         
        int min_idx = i; 
        printf("h: ");
        printf("%d ", ((int*)arr)[i]);

        for (int j = i + 1; j < n; j++) 

          if (((int*)arr)[j] < ((int*)arr)[min_idx]) 
            min_idx = j; 
  
        swap(&((int*)arr)[min_idx], &((int*)arr)[i]); 
    } 

    printf("\nSorted array\n");

    print_array(arr, n);

    return 1;
} 

int main(int argc, char** argv) {

    create_server("127.0.0.1", 3000, 10, INT, selectionSort);

    return 0;
}