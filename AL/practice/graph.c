#include "graph.h"


void test_dijsktra() {

    Graph* graph = normal_graph();

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

}

void test_bfs() {

    Graph* graph = normal_graph();

    print_graph(graph);

    Queue* bfs_queue = bfs(graph, 0);

    if(bfs_queue) {
        printf("BFS\n");
        print_queue(bfs_queue);
    }
        
    else
        printf("BFS QUEUE ERROR\n");

}

void test_dfs() {

    Graph* graph = normal_graph();
    print_graph(graph);
    Queue* dfs_queue = dfs(graph, 0);

    if(dfs_queue) {

        printf("DFS\n");
        print_queue(dfs_queue);

    } else {
        printf("No dfs stack found\n");
    }


}

void test_bipartite() {

    Graph* graph = bipartite_graph();

    if(is_bipartite(graph)) {
        printf("Graph bipartite\n");

    } else {
        printf("Not bipartite\n");
    }

    EGraph* egraph = graph_to_edge_graph(graph);
    print_edge_list(egraph);
}

int main() {

   test_dfs();

    return 0;
}