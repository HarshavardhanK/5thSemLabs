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

void push_back(LIST** head, int value) {

    if(*head) {

        printf("adding %d..", value);

        LIST* iter = *head;

        while(iter->next != NULL) {
            iter = iter->next;
        }

        iter->next = create_node(value);

    } else {

        printf("adding head null %d..", value);

        *head = create_node(value);
    }
}

LIST* front(LIST** head) {

    if(head) {

        printf("removing %d ..", (*head)->data);

        LIST* res = *head;
        *head = (*head)->next;

        return res;

    } else {
        printf("Empty list\n");
        return NULL;
    }
}

int is_empty(LIST* list) {

    if(list == NULL)
        return 1;
    
    return 0;
}

void print_list(LIST* head) {

    if(head) {

        LIST* iter = head;

        while(iter != NULL) {
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

        graph->adj_list[from] = create_node(to);
        //push_back(&graph->adj_list[from], to);

    } else {

        push_back(&graph->adj_list[from], to);
    }

    if(graph->adj_list[to] == NULL) {

        graph->adj_list[to] = create_node(from);
        //push_back(&graph->adj_list[to], from);

    } else {
        
        push_back(&graph->adj_list[to], from);
    }

    printf("Added edge\n");


}

void breadth_first_search(GRAPH* graph, int source) {

    if(!graph) {
        return;
    }

    int *visited = (int*) malloc(sizeof(int) * graph->size);

    for(int i = 0; i < graph->size; i++) {
        visited[i] = 0;
    }

    int arr[graph->size];// = (int*) malloc(sizeof(int) * graph->size);
    int k = 0;

    printf("Printing source adj_list\n");

    LIST* queue = create_node(source);

    while(!is_empty(queue)) {
       
        LIST* adj_node = front(&queue);
        LIST* adj = graph->adj_list[adj_node->data];

        print_list(adj);

        while(adj != NULL && visited[adj->data] == 0) {

            arr[k++] = adj->data;
            
            printf("%d  ", adj->data);
            push_back(&queue, adj->data);

            visited[adj->data] = 1;
            
            adj = adj->next;

        }

    }

    for(int i = 0; i < graph->size; i++)
        printf("%d ", arr[i]);

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