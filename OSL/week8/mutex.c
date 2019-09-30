#include <pthread.h>
#include <stdio.h>

volatile int counter = 0;
pthread_mutex_t mutex;

void* count(void* args) {

    for(int i = 0; i < 100; i++) {
        pthread_mutex_lock(&mutex);
        counter++;
        printf("Count is %d\n", counter);
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char** argv) {

    pthread_t thread1, thread2;

    pthread_mutex_init(&mutex, 0);

    pthread_create(&thread1, 0, &count, 0);
    pthread_create(&thread2, 0, &count, 0);

    pthread_join(thread1, 0); pthread_join(thread2, 0);

    pthread_mutex_destroy(&mutex);

    return 0;
}