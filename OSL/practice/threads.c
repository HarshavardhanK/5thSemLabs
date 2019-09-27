#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct arr {

    int size;
    int* arr;

    int beg;
    int end;

} ARR;

void* run(void* args) {

    ARR *arr = (ARR*) args;
    int sum = 0;

    for(int i = arr->beg; i < arr->end; i++) {
        printf("%d ", arr->arr[i]);
        sum += arr->arr[i];
    }

    printf("thread sum %d\n", sum);

    return (void*) sum;
}

int main(int argc, char** argv) {

    pthread_t thread1, thread2;

    ARR* arr = (ARR*)malloc(sizeof(ARR));
    arr->arr = (int*) malloc(sizeof(int) * 10);
    arr->size = 10;

    for(int i = 0; i < 10; i++) 
        scanf("%d", &arr->arr[i]);

    arr->beg = 0;
    arr->end = 5;

    int sum1;
    pthread_create(&thread1, 0, &run, (void*) arr);
    pthread_join(thread1, (void*) &sum1);

    arr->beg = 5;
    arr->end = 10;

    int sum2;
    pthread_create(&thread2, 0, &run, (void*) arr);
    pthread_join(thread2, (void*) &sum2);

    printf("SUM %d\n", sum1);
    printf("Sum is %d\n", sum1 + sum2);

    return 0;
}