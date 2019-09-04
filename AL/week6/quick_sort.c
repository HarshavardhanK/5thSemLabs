#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include <time.h>

double time_taken(void (*function) (int), int size) {

    clock_t timer;
    timer = clock();

    function(size);

    timer = clock() - timer;

    return ((double) timer) / CLOCKS_PER_SEC;
}

void print_list(int* list, int size) {

    for(int i = 0; i < size; i++)
        printf("%d ", list[i]);
    
    printf("\n");
}

void generate_array(int* array, int size, int begin, int end) {

    for(int i = 0; i < size; i++) {
        array[i] = rand() % (end - begin) + begin; 
    }
}

void swap(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high) {

    int pivot = arr[rand() % high]; 
    int i = (low - 1);  
  
    for (int j = low; j <= high - 1; j++)  {  
        
        if (arr[j] < pivot)  {  
            i++;  
            swap(&arr[i], &arr[j]);  
        }  
    }

    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}

void quick_sort(int arr[], int low, int high) {  

    if (low < high){  
        
        int pi = partition(arr, low, high);  
  
        quick_sort(arr, low, pi - 1);  
        quick_sort(arr, pi + 1, high); 

    }  
}

void test_(int size) {

    int array[size];

    generate_array(array, size, -100, 500);

    quick_sort(array, 0, size - 1);
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void test(int size) {

    int array[size];
    generate_array(array, size, -100, 100);
    qsort(array, size, sizeof(int), cmpfunc);
}

int main(int argc, char** argv) {

    FILE* res = fopen("mergesortres.csv", "w");

    for(int i = 50000; i <= 1000000; i += 50000) {
        double time = time_taken(test, i);
        fprintf(res, "%d, %f\n", i, time);
    }

    fclose(res);
    return 0;

}