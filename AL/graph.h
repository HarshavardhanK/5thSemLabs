#ifndef GRAPH_H
#define GRAPH_H

#include "graph_node.h"

struct graph {

    int (*equal)(const void*, const void*);
    NODE* ADJ;
};

typedef struct graph GRAPH;

GRAPH* init_graph(void* source, int (*equal_)(const void*, const void*)) {

    GRAPH* graph = (GRAPH*) malloc(sizeof(GRAPH));
    graph->equal = equal_;

    NODE* node_source = create_node(source);
    graph->ADJ = create_node(node_source);

    return graph;
}

void add_edge(GRAPH* graph, void* from, void* to) {

    printf("ADDING EDGE\n");

    NODE* from_node = search(graph->ADJ, create_node(from), graph->equal);
    NODE* to_node = search(graph->ADJ, create_node(to), graph->equal);

    if(from_node != NULL) {

        printf("FROM NODE present\n");
        push_back(from_node, to);

    } else {

        printf("NODE not present\n");
        from_node = create_node(from);
        push_back(graph->ADJ, from_node);
    }

    if(to_node != NULL) {

        printf("FROM NODE present\n");
        from_node = create_node(from);
        push_back(to_node, from);

    } else {

         printf("TO NODE not present\n");
         to_node = create_node(from);
         push_back(to_node, from);
         push_back(graph->ADJ, to_node);
    }

    print_list(from_node, print_node_char);

    printf("Added edges\n");
}
#endif