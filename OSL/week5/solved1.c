#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *run(void * params) {
    printf(" Start Thread %i\n", (int) params);
    return params;
}

void create() {

    pthread_t thread;
    pthread_create(&thread, 0, &run, 0);

    sleep(0.6);

    printf("Main thread\n");
}

void join() {

    pthread_t thread;
    pthread_create(&thread, 0, &run, 0);

    printf("Main\n");

    pthread_join(thread, 0);
}

void pass() {

    pthread_t thread[10];
    
    int return_values[10];

    for(int i = 0; i < 10; i++) {
        pthread_create(&thread[i], 0, &run, (void*) i);
    }

    for(int i = 0; i < 10; i++) {
        pthread_join(thread[i], (void**) &return_values[i]);
        printf("End thread %i\n", return_values[i]);
    }
}

int main() {

    pass();
}