#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>

struct Param {
    int start;
    int end;
};

struct OutputParam {
    int size;
    int *arr;
};

typedef struct OutputParam OUTPUT;
typedef struct Param PARAM;

void *run(void *arg) {

    PARAM* param = (PARAM*) arg;

    int* arr = (int*) malloc(sizeof(int) * (param->end - param->start + 1));
    int k = 0;
   
    for(int j = param->start; j < param->end; j++) {

        int is_prime = 1;

         double root = sqrt(j);

        for(int i = 2; i <= root; i++) {

            if(j % i == 0) {
                is_prime = 0;
            }

        }

        if(is_prime == 1) {
            arr[k++] = j;
        }

    } 

    /*for(int i = 0; i < k; i++)
        printf("%d ", arr[i]);*/
    
    OUTPUT* output = (OUTPUT*) malloc(sizeof(OUTPUT));
    output->arr = arr;
    output->size = k;

    return (void*) output;

}

int main(int argc, char** argv) {

    if(argc < 3) {
        return 1;
    }

    int start = atoi(argv[1]); int end = atoi(argv[2]);

    PARAM* param = (PARAM*) malloc(sizeof(PARAM));
    param->start = start;
    param->end = end;

    pthread_t thread;
    pthread_create(&thread, 0, &run, param);

    int *arr = (int*) malloc(sizeof(int) * (end - start + 1));

    OUTPUT* output = (OUTPUT*) malloc(sizeof(OUTPUT));

    pthread_join(thread, &output);

    for(int i = 0; i < output->size; i++)
        printf("%d ", output->arr[i]);

    return 0;
}