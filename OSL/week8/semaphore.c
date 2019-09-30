#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>

sem_t mutex;
volatile int c = 0;

void* func1(void* param) {
    printf("Thread 1\n");
    
    c++;
    printf("%d\n", c);

    sem_post(&mutex);
}

void *func2(void* param) {
    sem_wait(&mutex);
    c--;
    printf("%d\n", c);
    printf("Thread 2\n");
}

int main(int agrc, char** argv) {

    sem_init(&mutex, 0, 1);

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, &func1, NULL);
    pthread_create(&thread2, NULL, &func2, NULL);

    pthread_join(thread1, NULL); pthread_join(thread2, NULL);

    sem_destroy(&mutex);

    return 0;
}