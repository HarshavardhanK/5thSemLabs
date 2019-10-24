#include "graph.h"

int compare(const void* edgeA, const void* edgeB) {
    return ((EDGE*)(edgeA))->weight > ((EDGE*) edgeB)->weight;
}

void minimum_spanning_tree(GRAPH* graph) {

    EDGE spanning_tree[graph->vertices];

    int iter_result = 0;
    int iter_sorted_edges = 0;

    qsort(graph->edge, graph->edges, sizeof(graph->edge[0]), compare);

    SUBSET subsets[graph->vertices];

    for(int i = 0; i < graph->vertices; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    while(iter_result < graph->vertices - 1 && iter_sorted_edges < graph->edges) {

        EDGE next_edge = graph->edge[iter_sorted_edges++];

        int x_set = find(subsets, next_edge.src);
        int y_set = find(subsets, next_edge.dest);

        if(x_set != y_set) {
            spanning_tree[iter_result++] = next_edge;
            union_(subsets, x_set, y_set);
        }

    }

    printf("Following are the edges in the constructed MST\n"); 
    for (int i = 0; i < iter_result; ++i) 
        printf("%d -- %d == %d\n", spanning_tree[i].src, spanning_tree[i].dest, 
                                                 spanning_tree[i].weight); 

    
}

int main() { 
    /* Let us create following weighted graph 
             10 
        0--------1 
        |  \     | 
       6|   5\   |15 
        |      \ | 
        2--------3 
            40       */
    int V = 4;  // Number of vertices in graph 
    int E = 5;  // Number of edges in graph 

    GRAPH* graph = create_graph(V, E); 
  
  
    // add edge 0-1 
    graph->edge[0].src = 0; 
    graph->edge[0].dest = 1; 
    graph->edge[0].weight = 10; 
  
    // add edge 0-2 
    graph->edge[1].src = 0; 
    graph->edge[1].dest = 2; 
    graph->edge[1].weight = 6; 
  
    // add edge 0-3 
    graph->edge[2].src = 0; 
    graph->edge[2].dest = 3; 
    graph->edge[2].weight = 5; 
  
    // add edge 1-3 
    graph->edge[3].src = 1; 
    graph->edge[3].dest = 3; 
    graph->edge[3].weight = 15; 
  
    // add edge 2-3 
    graph->edge[4].src = 2; 
    graph->edge[4].dest = 3; 
    graph->edge[4].weight = 40; 
  
    minimum_spanning_tree(graph); 

    return 0; 
} 