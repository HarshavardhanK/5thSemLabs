#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <stdio.h>

struct node {

    int element;
    struct node* next;
};

typedef struct node Node;

Node* create_node(int element) {

    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->element = element;
    new_node->next = NULL;

    return new_node;
}

void insert_node(Node* root, int element) {

    if(!root) {
        root = create_node(element);
        return;
    }

    Node* iter = root;

    while(iter->next != NULL) {
        iter = iter->next;
    }

    iter->next = create_node(element);

}

struct GRAPH {

    Node* adj_list;
    int vertices;
};

typedef struct GRAPH Graph;

Graph* init_graph(unsigned short int vertices) {

    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->vertices = vertices;

    graph->adj_list = (Node*) malloc(sizeof(Node) * graph->vertices);

    return graph;
}

void add_edge(int from, int to) {
    
}

#endif