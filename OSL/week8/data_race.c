#include <stdio.h>
#include <pthread.h>

int counter = 0;

void* count(void* c) {
    counter++;
} 

int main() {

    pthread_t t1, t2;
    pthread_create(&t1, 0, count, 0);
    pthread_create(&t2, 0, count, 0);

    pthread_join(t1, 0);
    pthread_join(t2, 0);

    return 0;
}