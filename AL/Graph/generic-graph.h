#ifndef GRAPH_H
#define GRAPH_H

#include "generic-list.h"
#include "generic-queue.h"

struct graph {

    int (*equal)(const void*, const void*);
    NODE* ADJ;
};

typedef struct graph GRAPH;

GRAPH* init_graph(void* source, int (*equal_)(const void*, const void*)) {

    GRAPH* graph = (GRAPH*) malloc(sizeof(GRAPH));
    graph->equal = equal_;

    NODE* node_source = create_node(source);
    graph->ADJ = create_node(node_source);

    return graph;
}

void add_edge(GRAPH* graph, void* from, void* to) {

    printf("ADDING EDGE\n");

    NODE* from_node = search(graph->ADJ, create_node(from), graph->equal);
    NODE* to_node = search(graph->ADJ, create_node(to), graph->equal);

    if(from_node != NULL) {

        printf("FROM NODE present\n");
        push_back(from_node, to);

    } else {
        printf("NODE not present\n");
        from_node = create_node(from);

        push_back(from_node, to);
        push_back(graph->ADJ, from_node);

    }

    if(to_node != NULL) {

        printf("TO NODE present\n");
        push_back(to_node, from);
    
    } else {

         printf("TO NODE not present\n");
         to_node = create_node(to);

         push_back(to_node, from);
         push_back(graph->ADJ, to_node);

    }

    printf("Added edges\n");
}

void breadth_first_search(GRAPH* graph, void* value) {

    if(!graph) {
        printf("Empty graph\n");
        return;
    }

    NODE* source = create_node(value);

    NODE* source_graph = search(graph->ADJ, source, graph->equal);

    if(!source_graph) {
        printf("Source node does not exist\n");
        return;

    } else {
        printf("Source node exists\n");
    }

    QUEUE* queue = create_queue(value);

    while(!empty(queue)) {

        //NODE* current_adj = front(queue);
        NODE* current_adj = search(graph->ADJ, front(queue), graph->equal);

        if(current_adj) {

            while(current_adj != NULL) {

                print_node(current_adj);
                current_adj = current_adj->next;
                push_back(queue->head, current_adj);

            }

        }

        
    }



}


#endif