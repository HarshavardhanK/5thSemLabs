
#ifndef GENERIC_QUEUE_H
#define GENERIC_QUEUE_H

#include "generic-list.h"

struct queue {
    NODE* head;
    
};

typedef struct queue QUEUE;

QUEUE* create_queue(void *value) {

    QUEUE* queue = (QUEUE*) malloc(sizeof(QUEUE));
    queue->head = create_node(value);

    return queue;
}

int empty(QUEUE* queue) {

    if(queue->head == NULL) {
        return 1;
    }

    return 0;
}

NODE* front(QUEUE* queue) {

    if(empty(queue)) {
        printf("Queue empty\n");
        return NULL;
    }

    NODE* res = queue->head;
    
    if(queue->head->next != NULL) {
        queue->head = queue->head->next;

    } else {
        queue->head = NULL;
    }

    return res;

}

#endif