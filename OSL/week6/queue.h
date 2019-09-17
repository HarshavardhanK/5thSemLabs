#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdio.h>

#include "process.h"

struct queue {

    int size;
    PROC** arr;

    int front;
    int rear;

    int time;
};

typedef struct queue QUEUE;

QUEUE* create_queue(int size, int time) {

    QUEUE* queue = (QUEUE*) malloc(sizeof(QUEUE));

    queue->arr = (PROC**) malloc(sizeof(PROC*) * size);

    queue->size = size;
    queue->front = -1;
    queue->rear = -1;

    queue->time = time;

    return queue;
}

PROC* front(QUEUE* queue) {

    if(queue->front != -1) {
        return queue->arr[queue->front];
    }

    return NULL;
}

int is_empty(QUEUE* queue) {

    if(queue->front == queue->rear)
        return 1;
    
    return 0;
}

void enqueue(QUEUE* queue, PROC* process) {

    if(queue->front == -1) 
        queue->front = 0;

    if(queue->rear == queue->size) {
        printf("Queue full\n");
        return;
    }
    queue->rear = queue->rear + 1 % queue->size;
    queue->arr[queue->rear] = process;
    queue->rear = queue->rear % queue->size;

    printf("Enqueued ");
    print_process(process);
}

PROC* dequeue(QUEUE* queue) {

    if(queue->front == queue->rear) {
        printf("Queue is empty\n");
        return NULL;
    }

    queue->front = queue->front + 1 % queue->size;
    return queue->arr[queue->front];

}

void print_queue(QUEUE* queue) {

    if(queue) {

        for(int i = queue->front; i != queue->rear + 1; i++) {
            print_process(queue->arr[i]);
        }
    }
}

#endif