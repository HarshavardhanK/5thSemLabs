#include "graph.h"

void test_list() {

    LIST* head = create_node(0);

   // push_back(head, 0);

    print_list(head);

    printf("%d\n", front(&head)->data);

    print_list(head);

    push_back(&head, 2);

    print_list(head);

   // front(&head); 

    push_back(&head, 6);

    print_list(head);

}

void test_graph() {

    GRAPH* graph = create_graph(4);

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);

    print_graph(graph);

    int* arr, *vis;
    breadth_first_search(graph, 0);

    

}

int main(int argc, char** argv) {

    test_graph();
    //test_list();

    return 0;
}