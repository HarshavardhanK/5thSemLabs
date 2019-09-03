#ifndef GRAPH_H
#define GRAPH_H

#include "graph_node.h"

struct graph {

    int (*equal)(const void*, const void*);
    NODE* ADJ;
};

typedef struct graph GRAPH;

GRAPH* init_graph(int size, int (*equal_)(const void*, const void*)) {

    GRAPH* graph = (GRAPH*) malloc(sizeof(GRAPH));
    graph->equal = equal_;
    graph->ADJ = (NODE*) malloc(sizeof(NODE));

    return graph;
}

void add_edge(GRAPH* graph, void* from, void* to) {

    NODE* from_node = search(graph->ADJ, from, graph->equal);
    NODE* to_node = search(graph->ADJ, to, graph->equal);

    if(from_node != NULL) {
        printf("NODE present\n");

    } else {
        printf("NODE not present");
        NODE* from_node = create_node(from);
    }

    if(to_node != NULL) {

    }
}
#endif