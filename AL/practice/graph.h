#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "queue.h"

/*Three types of graph representation

    Undirected

    1. Adjacency list
    2. Edge list representation
    3. Adjacency matrix

    Directed
    1. Adjacency list
    2. Adjacency matrix

*/

//Adjacency list

struct adj_list_node {
    int dest;
    struct adj_list_node* next;
};

typedef struct adj_list_node ADJ_node;

struct adj_list {
    ADJ_node* head;
};

typedef struct adj_list ADJ_list;

struct graph_ {
    int vertices;
    ADJ_list* array;
};

typedef struct graph_ Graph;

ADJ_node* create_adj_node(int dest) {

    ADJ_node* node = (ADJ_node*) malloc(sizeof(ADJ_node));
    node->dest = dest;
    node->next = NULL;

    return node;
}

Graph* create_graph(int vertices) {

    Graph* graph = (Graph*) malloc(sizeof(graph));
    graph->vertices = vertices;
    graph->array = (ADJ_list*) malloc(sizeof(ADJ_list) * vertices);

    for(int i = 0; i < vertices; i++)
        graph->array[i].head = NULL;

    return graph;
}

void add_edge(Graph* graph, int src, int dest) {

    ADJ_node* node = create_adj_node(dest);

    node->next = graph->array[src].head;
    graph->array[src].head = node;

    ADJ_node* dest_node = create_adj_node(src);

    dest_node->next = graph->array[dest].head;
    graph->array[dest].head = dest_node;
}

void print_graph(Graph* graph) {

    for(int i = 0; i < graph->vertices; i++) {

        ADJ_node* iter = graph->array[i].head;

        printf("ADJ List of vertex %d\n Head", i);

        while(iter) {

            printf("-> %d", iter->dest);
            iter = iter->next;

        }

        printf("\n");
    }
}

Queue* bfs(Graph* graph, int start) {

    if(!graph) {
        printf("Graph error bfs\n");
        return NULL;
    }

    int max_edges = graph->vertices * graph->vertices;

    int visited[max_edges];

    memset(visited, 0, sizeof(visited));

    visited[start] = 1;

    Queue* queue = init_queue(max_edges);
    enqueue(queue, start);

    Queue* bfs_queue = init_queue(max_edges);
    enqueue(bfs_queue, start);

    while(!is_empty(queue)) {

        int dat = dequeue(queue);
        ADJ_node *node = graph->array[dat].head;

        while(node != NULL) {

            if(!visited[node->dest]) {
                enqueue(queue, node->dest);
                visited[node->dest] = 1;

                enqueue(bfs_queue, node->dest);

            }
                
            node = node->next;
        }

    }

    return bfs_queue;

    printf("\n");
}

#endif