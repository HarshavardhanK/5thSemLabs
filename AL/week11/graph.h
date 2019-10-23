#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "union_find.h"

struct edge {
    int src;
    int dest;
    int weight;
};

typedef struct edge EDGE;

struct graph  {

    int vertices;
    int edges;

    EDGE* edge; // array of edges
};

typedef struct graph GRAPH;

GRAPH* create_graph(int vertices, int edges) {
    
    GRAPH* graph = (GRAPH*) malloc(sizeof(GRAPH));
    graph->vertices = vertices;
    graph->edges = edges;
    graph->edge = (EDGE*) malloc(sizeof(EDGE) * graph->edges);

    return graph;
}

int has_cycle(GRAPH* graph) {

    SUBSET subsets[graph->vertices];

    for(int i = 0; i < graph->vertices; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    
    //isn't having all -1 in array lead to all vertices being root?'

    for(int i = 0; i < graph->edges; ++i) {

        int set_x = find(subsets, graph->edge[i].src);
        int set_y = find(subsets, graph->edge[i].dest);

        if(set_x == set_y) {
            return 1;
        }
            
        
        union_(subsets, set_x, set_y);
    }

    return 0;
}

void test() {

    GRAPH* graph = create_graph(2, 2); 

    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
  
    if(has_cycle(graph)) {
        printf("Has cycle\n");

    } else {
        printf("No cycle\n");
    }

}

#endif