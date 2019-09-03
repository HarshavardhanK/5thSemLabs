#include "graph.h"
#include <string.h>

void print_node_char(void* value) {
    printf("%s-> ", value);
}

void print_list_lsit(void* value) {

    print_list(value, print_node_char);
    
}

int str_cmp(const void* s1, const void* s2) {
    return strcmp((char*)s1, (char*)s2) == 0;
}

void test_nodes() {

    char* value = "hello";
    char* v2 = "how";
    char* v3 = "what";

    NODE* node = create_node((void*)value);
    push_back(node, v2);
    push_back(node, v3);

    print_list(node, print_node_char);

    if(search(node, "hello", str_cmp)) {
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

    print_list(master, print_list_lsit);

    
}

void test_graph() {

    GRAPH* graph = init_graph(3, str_cmp);
    
    add_edge(graph, "hello", "to");
    add_edge(graph, "hello", "where");
}

int main(int argc, char** argv) {

    //test_graph();
    list_list();

    return 0;
}