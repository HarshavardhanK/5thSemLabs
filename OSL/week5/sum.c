#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct argument {
    int size;
    int* arr;
};

typedef struct argument ARG;

void *run(void * arg) {

    printf("Running child thread\n");

    ARG* _arg_ = (ARG*) arg;

    if(_arg_->arr) {

        int sum = 0;

        for(int i = 0; i < _arg_->size; i++) {
            printf(". ");

            if(_arg_->arr[i] > 0)
                sum += _arg_->arr[i];
         }

         printf("\n");

         return (void *) sum;

    } else {

        printf("Array is empty\n");
    }

}

int main(int argc, char** argv) {

    if(argc < 2) {
        return 1;
    }

    ARG* arg = (ARG*) malloc(sizeof(ARG));
    arg->size = atoi(argv[1]);
    arg->arr = (int*) malloc(sizeof(int) * arg->size);

    for(int i = 0; i < atoi(argv[1]); i++)
        scanf("%d", &arg->arr[i]);

    pthread_t thread;
    pthread_create(&thread, 0, &run, (void*) arg);

    int sum = 0;

    pthread_join(thread, (void**) &sum);

    printf("Running main thread\n");

    printf("Sum is %d\n", sum);
}