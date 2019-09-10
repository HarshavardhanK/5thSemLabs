#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

struct list {
    struct list* next;
    int data;
};

typedef struct list LIST;

LIST* create_node(int value) {

    LIST* list = (LIST*) malloc(sizeof(LIST));
    list->data = value;
    list->next = NULL;

    return list;
} 

void push_back(LIST* head, int value) {

    if(head) {

        LIST* iter = head;

        while(iter->next != NULL) {
            iter = iter->next;
        }

        iter->next = create_node(value);

    } else {

        head = create_node(value);
    }
}

LIST* front(LIST** head) {

    if(head) {

        LIST* res = *head;
        *head = (*head)->next;

        return res;

    } else {
        printf("Empty list\n");
        return NULL;
    }
}

void print_list(LIST* head) {

    if(head) {

        LIST* iter = head;

        while(iter) {
            printf("%d->", iter->data);
            iter = iter->next;
        }

        printf("END\n");

    } else {
        printf("LIST empty\n");
    }
}

struct graph {

    LIST** adj_list;
    int size;

};

typedef struct graph GRAPH;

GRAPH* create_graph(int size) {

    GRAPH* graph = (GRAPH*) malloc(sizeof(GRAPH));
    graph->adj_list = (LIST**) malloc(sizeof(LIST*) * size);
    graph->size = size;

    for(int i = 0; i < size; i++) {
        graph->adj_list[i] = NULL;
    }

    return graph;
}

void add_edge(GRAPH* graph, int from, int to) {

    if(!graph) {
        return;
    }

    if(from > graph->size || to > graph->size)
        return;

    if(graph->adj_list[from] == NULL) {

        graph->adj_list[from] = create_node(from);
        push_back(graph->adj_list[from], to);

    } else {

        push_back(graph->adj_list[from], to);
    }

    if(graph->adj_list[to] == NULL) {

        graph->adj_list[to] = create_node(to);
        push_back(graph->adj_list[to], from);

    } else {
        
        push_back(graph->adj_list[to], from);
    }

    printf("Added edge\n");


}

void breadth_first_search(GRAPH* graph) {
    
}

void print_graph(GRAPH* graph) {

    if(graph) {

        for(int i = 0; i < graph->size; i++) {

            if(graph->adj_list[i]) {
                print_list(graph->adj_list[i]);
            }

        }

    }

}



#endif