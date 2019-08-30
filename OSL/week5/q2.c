#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct Array {
    int size;
    int* arr;
};

typedef struct Array ARRAY;

void* run(void *arg) {

    int sum = 0;

    ARRAY* arr = (ARRAY*) arg;

    for(int i = 0; i < arr->size; i++) {

        if(arr->arr[i] > 0) {
            sum += arr->arr[i];
        }
    }

    printf("Sum: %d\n", sum);

    return (void*) sum;

}

int main(int argc, char** argv) {

    if(argc < 2) {
        return 1;
    }

    int size = atoi(argv[1]);

    ARRAY *arr = (ARRAY*) malloc(sizeof(ARRAY));
    arr->size = size;
    arr->arr = (int*) malloc(sizeof(int) * size);

    for(int i = 0; i < size; i++) {
        printf("Element: "); scanf("%d", &arr->arr[i]);
    }

    pthread_t thread;
    pthread_create(&thread, 0, &run, arr);

    int sum;

    pthread_join(thread, &sum);

    printf("Sum is %d\n", sum);

    return 0;
}