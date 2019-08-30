#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

struct queue {

    int size;
    int* arr;

    int front;
};

typedef struct queue QUEUE;

QUEUE* create_queue(int size) {

    QUEUE* queue = (QUEUE*) malloc(sizeof(QUEUE));
}

#endif