#include "graph.h"

int compare(const void* edgeA, const void* edgeB) {
    return ((EDGE*)(edgeA))->weight > ((EDGE*) edgeB)->weight;
}

EDGE* minimum_spanning_tree(GRAPH* graph) {

    EDGE spanning_tree[graph->vertices];

    int iter_result = 0;
    int iter_sorted_edges = 0;

    qsort(graph->edge, graph->edges, sizeof(graph->edge[0]), compare);

    SUBSET subsets[graph->vertices];

    for(int i = 0; i < graph->vertices; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    EDGE next_edge = graph->edge[iter_sorted_edges++];

    int x_set = find(subsets, next_edge.src);
    int y_set = find(subsets, next_edge.dest);

    if(x_set != y_set) {
        spanning_tree[iter_result++] = next_edge;
        union_(subsets, x_set, y_set);
    }

    return spanning_tree;
}