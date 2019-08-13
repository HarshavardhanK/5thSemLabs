
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
  
int selectionSort(int arr[], int n) 
{ 
    printf("sorting\n");
    int i, j, min_idx; 

    for (i = 0; i < n-1; i++) 
    { 
         
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        swap(&arr[min_idx], &arr[i]); 
    } 

    print_array(arr, n);

    return 1;
} 

int main(int argc, char** argv) {

    create_server("127.0.0.1", 3000, 10, selectionSort);

    return 0;
}