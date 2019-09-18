#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *run(void * arg) {

    //params hold the
    int *fib = (int*) malloc(sizeof(int) * (int) arg);

    fib[0] = 1; fib[1] = 1;

    for(int i = 2; i< (int) arg; i++) {

        fib[i] = fib[i - 1] + fib[i - 2];
       
    }

    return (void*) fib;

}

int main(int argc, char** argv) {

    if(argc < 2) {
        printf("invalid arguments\n");
        return 1;
    }

    int num = atoi(argv[1]);
    int *fib = (int*) malloc(sizeof(int) * num);

    pthread_t fibonacci;
    pthread_create(&fibonacci, 0, &run, (void*) num);

    pthread_join(fibonacci, &fib);

    for(int i = 0; i < num; i++)
        printf("%d ", fib[i]);
    
    printf("\n");

    return 0;
}