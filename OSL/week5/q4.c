#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct Array {
    int size;
    int* arr;
};

typedef struct Array ARRAY;

void *odd(void * arg) {
    int sum = 0;

    ARRAY* param = (ARRAY*) arg;

    for(int i = 0; i < param->size; i++)
        if(param->arr[i] % 2 == 1)
            sum += param->arr[i];

    
    printf("%d\n", sum);
    
    return (void*) sum;
}

void* even(void* arg) {

    int sum = 0;

    ARRAY* param = (ARRAY*) arg;

    for(int i = 0; i < param->size; i++) 
        if(param->arr[i] % 2 == 0)
            sum += param->arr[i];

    printf("%d\n", sum);
    
    return (void*) sum;
}

int main(int argc, char** argv) {

    if(argc < 2) {
        return 1;
    }

    int size = atoi(argv[1]);

    ARRAY* array = (ARRAY*) malloc(sizeof(ARRAY));

    array->size = size;
    array->arr = (int*) malloc(sizeof(int) * size);

    for(int i = 0; i < size; i++) {
        scanf("%d", &array->arr[i]);
    }

    pthread_t even_thread;
    pthread_t odd_thread;

    pthread_create(&even_thread, 0, &even, array);
    pthread_create(&odd_thread, 0, &odd, array);

    int even_sum;
    int odd_sum;

    pthread_join(even_thread, &even_sum);
    pthread_join(odd_thread, &odd_sum);

    printf("Even sum: %d\n", even_sum);
    printf("Odd sum: %d\n", even_sum);

    return 0;
}