#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>

int buffer[5];

int front = -1;
int rear = -1;

sem_t mutex, full, empty;

void* produce(void* arg) {

    for(int i = 0; i < 10; i++) {

        sem_wait(&empty);
        sem_wait(&mutex);

        printf("Produced item is %d\n", i);

        buffer[(++rear) % 5] = i;

        sleep(1);

        sem_post(&mutex);
        sem_wait(&full);

        printf("full %u\n", full);
    }
}

void *consume(void* arg) {

    for(int i = 0; i < 10; i++) {

        sem_wait(&full);
        printf("full %u\n", full);

        sem_wait(&mutex);

        int item = buffer[(++front) % 5];

        printf("Consumed item is %d\n", item);

        sleep(1);

        sem_post(&mutex);
        sem_post(&empty);

        int val;

        sem_getvalue(&wt)
    }
}
