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

void merge(int *array, int low, int mid, int high) {

    int size_1 = mid - low + 1;
    int size_2 = high - mid;

    int right[size_1];
    int left[size_2];

    for(int i = 0; i < size_1; i++)
        left[i] = array[low + i];
    
    for(int i = 0; i <size_2; i++)
        right[i] = array[mid + 1 + i];
    
    int k = low;
    int i = 0; int j = 0;

    while(i < size_1 && j < size_2) {

        if(left[i] < right[j]) {
            array[k++] = left[i++];

        } else {
            array[k++] = right[j++];
        }
    }

    while (i < size_1) {
        array[k++] = left[i++];
    }

    while(j < size_2)
        array[k++] = right[j++];
    
} 

void merge_sort(int* array, int low, int high) {

    if(low >= high) {
        return;
    }

    int mid = low + (high - low) / 2;

    merge_sort(array, low, mid);
    merge_sort(array, mid + 1, high);

    merge(array, low, mid, high);

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

void test(int size) {

    int array[size];

    generate_array(array, size, -100, 500);

     merge_sort(array, 0, size - 1);
}


int main(int argc, char** argv) {

    FILE* res = fopen("res.csv", "w");

    for(int i = 50000; i <= 1000000; i += 50000) {
        double time = time_taken(test, i);
        fprintf(res, "%d, %f\n", i, time);
    }

    fclose(res);

    
    return 0;

}