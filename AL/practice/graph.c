#include "graph.h"

void test() {

    Graph* graph = create_graph(7);
    add_edge(graph, 0, 1); 
    add_edge(graph, 0, 4); 
    add_edge(graph, 1, 2); 
    add_edge(graph, 1, 3); 
    add_edge(graph, 1, 4); 
    add_edge(graph, 2, 3); 
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 5);
    add_edge(graph, 5, 6);

    print_graph(graph);

    Queue* bfs_queue = bfs(graph, 0);

    if(bfs_queue) {
        printf("BFS\n");
        print_queue(bfs_queue);
    }
        
    else
        printf("BFS QUEUE ERROR\n");

}

int main() {
    test();

    return 0;
}