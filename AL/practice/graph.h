#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "queue.h"

#define INFINITY 999

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
    int weight;
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

ADJ_node* create_adj_node(int dest, int weight) {

    ADJ_node* node = (ADJ_node*) malloc(sizeof(ADJ_node));
    node->dest = dest;
    node->weight = weight;
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

//Conversions

void print_graph_mat(int** mat, int size) {

    printf("adjacency matrix\n");

    for(int i = 0; i < size; i++) {

        for(int j = 0; j < size; j++) {

            if(mat[i][j] != INFINITY)
                printf("%d\t", mat[i][j]);

            else
                printf("INF\t");
        }

        printf("\n");
    }
}

void adj_to_mat(Graph* graph, int** mat, int non_connect) {

    printf("Converting list to matrix..\n");

    for(int i = 0; i < graph->vertices; i++) {

        for(int j = 0; j < graph->vertices; j++) {
            mat[i][j] = non_connect;
        }

        mat[i][i] = 0;
    }

    for(int i = 0; i < graph->vertices; i++) {

        ADJ_node* iter = graph->array[i].head;

        while(iter) {
            mat[i][iter->dest] = iter->weight;
            iter = iter->next;
        }
    }

    //print_graph_mat(mat, graph->vertices);
}

void add_edge(Graph* graph, int src, int dest, int weight) {

    ADJ_node* node = create_adj_node(dest, weight);

    node->next = graph->array[src].head;
    graph->array[src].head = node;

    ADJ_node* dest_node = create_adj_node(src, weight);

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

//DIJSKTRA

int min(int a, int b) {
    return a < b ? a : b;
}

int min_dist(int* dist, int vertices, int* visited) {

    int min = INT_MAX;
    int min_index = INT_MAX;

    for(int i = 0; i < vertices; i++) {
        if(dist[i] < min && !visited[i]) {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

void disjkstra(Graph* graph, int source, int *result) {

    if(source > graph->vertices || source < 0) {
        printf("Invalid source\n");
        return;
    }

    printf("Running Dijkstra's algorithm\n");

    int** mat = (int**) malloc(sizeof(int*) * graph->vertices);

    for(int i = 0; i < graph->vertices; i++)
        mat[i] = (int*) malloc(sizeof(int) * graph->vertices);

    adj_to_mat(graph, mat, INFINITY);

    int *dist = (int*) malloc(sizeof(int) * graph->vertices);

    for(int i = 0; i < graph->vertices; i++)
        dist[i] = mat[source][i];

    int *visited = (int*) malloc(sizeof(int) * graph->vertices);

    for(int i = 0; i < graph->vertices; i++)
        visited[i] = 0;

    visited[source] = 1;

    for(int i = 0; i < graph->vertices - 2; i++) {

        int u = min_dist(dist, graph->vertices, visited);
        visited[u] = 1;

        for(int v = 0; v < graph->vertices; v++) {

            if(!visited[v]) {

                if(dist[v] > dist[u] + mat[u][v]) {
                    dist[v] = dist[u] + mat[u][v];
                }
            }
        }

    }

    for(int i = 0; i < graph->vertices; i++)
        result[i] = dist[i];
}

//BIPARTITE


int is_bipartite(Graph* graph) {

    int color[graph->vertices];
    memset(color, -1, sizeof(color));

    int max_edges = graph->vertices * graph->vertices;

    //Assume source to be the 0th vertice
    int source = 0;

    color[source] = 1;

    Queue* queue = init_queue(max_edges);
    enqueue(queue, source);

    int **mat = (int**) malloc(sizeof(int*) * graph->vertices);

    for(int i = 0; i < graph->vertices; i++)
        mat[i] = (int*) malloc(sizeof(int) * graph->vertices);

    adj_to_mat(graph, mat, 0);

    while(!is_empty(queue)) {

        int u = dequeue(queue);

        for(int v = 0; v < graph->vertices; v++) {

            if(mat[u][v] && color[v] == -1) {
                //not colored
                color[v] = 1 - color[u];
                enqueue(queue, v);

            } else if(mat[u][v] && color[u] == color[v]) {
                return 0;
            }

        }
    }

    return 1;
}

//Generate graph
Graph* bipartite_graph() {

    Graph* graph = create_graph(7);

    add_edge(graph, 0, 1, 3); 
    add_edge(graph, 0, 3, 11); 
    add_edge(graph, 0, 5, 4); 
    add_edge(graph, 0, 7, 1); 
    add_edge(graph, 1, 2, 5); 
    add_edge(graph, 1, 4, 6); 
    add_edge(graph, 1, 6, 9);
    add_edge(graph, 2, 5, 8);
    add_edge(graph, 2, 7, 3);
    add_edge(graph, 4, 5, 5); 
    add_edge(graph, 6, 7, 6); 
    add_edge(graph, 3, 4, 9);
    add_edge(graph, 3, 6, 8);
    

    return graph;

}



#endif