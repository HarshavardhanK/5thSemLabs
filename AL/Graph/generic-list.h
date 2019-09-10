#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

        printf("SEARCHING..\n");

        NODE* iter = node;

        while(iter != NULL) {

            if(equal(iter->data, value)) {
                printf("FOUND..\n");
                return iter->data;
            }

            iter = iter->next;
        }
    }

    printf("Value not found\n");

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

void print_node_int(void* value) {
    printf("%d->", (int)value);
}


void print_node_char(void* value) {
    printf("%s-> ", value);
}

void print_node(void* value) {
    printf("%s ", ((NODE*)value)->data);
}

void print_list_list(void* value) {
    print_list(value, print_node_char);
}

void print_graph_adj(void* value) {

    NODE* iter = (NODE*) value;

    while(iter != NULL) {
        print_node_char(iter);
        iter = iter->next;
    }

    printf("END\n");
}

int str_cmp(const void* s1, const void* s2) {
    return strcmp((char*)s1, (char*)s2) == 0;
}

int node_cmp(const void* n1, const void* n2, int (*compare)(const void*, const void*)) {
    return compare(n1, n2);
}

int str_node_compare(const void* n1, const void* n2) {
    return node_cmp(((NODE*)n1)->data, ((NODE*)n2)->data, str_cmp);
}


#endif