#include "graph.h"

void test() {

    Graph* graph = create_graph(7);
    add_edge(graph, 0, 1, 3); 
    add_edge(graph, 0, 4, 11); 
    add_edge(graph, 1, 2, 4); 
    add_edge(graph, 1, 3, 1); 
    add_edge(graph, 1, 4, 5); 
    add_edge(graph, 2, 3, 6); 
    add_edge(graph, 3, 4, 9);
    add_edge(graph, 4, 5, 8);
    add_edge(graph, 5, 6, 3);

    print_graph(graph);

    Queue* bfs_queue = bfs(graph, 0);

    if(bfs_queue) {
        printf("BFS\n");
        print_queue(bfs_queue);
    }
        
    else
        printf("BFS QUEUE ERROR\n");

    int** mat = (int**) malloc(sizeof(int*) * graph->vertices);

    for(int i = 0; i < graph->vertices; i++)
        mat[i] = (int*) malloc(sizeof(int) * graph->vertices);

    
    adj_to_mat(graph, mat, 0);
    print_graph_mat(mat, graph->vertices);

    printf("DIJSKTRA\n");
    int* result = (int*) malloc(sizeof(int) * graph->vertices);
    disjkstra(graph, 0, result);

    printf("Single source shortest path\n");
    print_arr(result, graph->vertices);

    if(is_bipartite(graph)) {
        printf("Graph bipartite\n");

    } else {
        printf("Not bipartite\n");
    }

}

void test_bipartite() {

    Graph* graph = bipartite_graph();

    if(is_bipartite(graph)) {
        printf("Graph bipartite\n");

    } else {
        printf("Not bipartite\n");
    }
}

int main() {
    test();
    //test_bipartite();

    return 0;
}