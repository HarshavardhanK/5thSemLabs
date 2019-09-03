#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include <stdlib.h>
#include <stdio.h>

struct node {

    void* data;
    struct node* next;
};

typedef struct node NODE;

NODE* create_node(void* value) {

    NODE* node = (NODE*) malloc(sizeof(NODE));
    node->data = value;
    node->next = NULL;

    return node;
}

void push_back(NODE* head, void* value) {

    if(head == NULL) {
        head = create_node(value);

    } else {

        NODE* iter = head;

        while(iter->next != NULL) {
            iter = iter->next;
        }

        iter->next = create_node(value);
    }
}

NODE* search(NODE* node, void* value, int (*equal)(const void*, const void*)) {

    if(node != NULL) {

        NODE* iter = node;

        while(iter != NULL) {

            if(equal(iter->data, value)) {
                return iter;
            }
        }
    }

    return NULL;
}
void print_list(NODE* head, void (*print)(void*)) {

    if(head) {

        NODE* iter = head;

        while(iter != NULL) {
            print(iter->data);
            iter = iter->next;
        }

        printf("END\n");

    } else {
        printf("ERROR ENOLIST Empty list\n");
    }
}


#endif