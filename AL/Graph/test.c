#include "graph.h"

void test_list() {

    LIST* head = create_node(0);

    for(int i = 0; i < 5; i++) {
        push_back(head, i);
    }

    print_list(head);

    printf("%d\n", front(&head)->data);

    print_list(head);

}

void test_graph() {

    GRAPH* graph = create_graph(4);

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 3);
    add_edge(graph, 6, 7);

    print_graph(graph);
}

int main(int argc, char** argv) {

    test_graph();

    return 0;
}