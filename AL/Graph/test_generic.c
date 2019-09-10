#include "graph.h"
#include "generic-queue.h"

void test_nodes() {

    char* value = "hello";
    char* v2 = "how";
    char* v3 = "what";

    NODE* node = create_node((void*)value);
    push_back(node, v2);
    push_back(node, v3);

    print_list(node, print_node_char);

    int (*compare)(const void*, const void* ) = &str_cmp;

    if(search(node, "hello", compare) != NULL) {
        printf("FOUND\n");
    } else {
        printf("NOT FOUND\n");
    }

}

void list_list() {

    char* value = "hello";
    char* v2 = "how";
    char* v3 = "what";

    NODE* node = create_node((void*)value);
    push_back(node, v2);
    push_back(node, v3);

    NODE* n2 = create_node(v3);
    push_back(n2, v2); push_back(n2, value);

    NODE* master = create_node(node);
    push_back(master, n2);

    print_list(master, print_list_list);

    if(search(master, create_node("hello"), str_node_compare) != NULL) {
        printf("FOUND HELLO\n");
    } else {
        printf("NOT FOUND\n");
    }

    
}


void test_graph() {

    GRAPH* graph = init_graph("hello", str_node_compare);

    if(graph) {
        add_edge(graph, "hello", "to");
        add_edge(graph, "hello", "where");
        add_edge(graph, "where", "what");
    }

    printf("Printing graph\n");

    print_list(graph->ADJ, print_list_list);
    breadth_first_search(graph, "hello");

}

void test_queue() {

    char* value = "hello";
    char* v2 = "how";
    char* v3 = "what";

    QUEUE* queue = create_queue(value);
    push_back(queue->head, v2);
    push_back(queue->head, v3);

    printf("%s\n", front(queue)->data);
    printf("%s\n", front(queue)->data);
    printf("%s\n", front(queue)->data);

    printf("%s\n", front(queue)->data);
    

}

int main(int argc, char** argv) {

    //test_queue();
    test_graph();

    return 0;
}