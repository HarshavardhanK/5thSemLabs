#ifndef LINKEDLIST_h
#define LINKEDLIST_h

#include <stdio.h>
#include <stdlib.h>

struct LLNODE_int {

	struct LLNODE_int* next;
	int data;
};

struct LLNODE_obj {
	struct LLNODE_obj* next;
	struct LLNODE_int* data; 
};

typedef struct LLNODE_int DataNode;
typedef struct LLNODE_obj ListNode;

DataNode* create_data_node(int data) {

	DataNode* node = (DataNode*) malloc(sizeof(DataNode));
	node->data = data;
	node->next = NULL;

	return node;

}

void print_data_node(DataNode* node) {

	if(node == NULL) {
		printf("Empty node\n");

	} else {
		printf("%d ", node->data);
	}
}

void print_list_node(ListNode* node) {

	if(node == NULL) {
		printf("Empty node\n");

	} else {
		print_data_node(node->data);
	}
}

ListNode* create_list_node(DataNode* node) {

	DataNode* data_node = create_data_node(node->data);

	ListNode* list_node = (ListNode*) malloc(sizeof(ListNode));
	list_node->data = data_node;
	list_node->next = NULL;

	return list_node;
}

void insert_list_node(ListNode* root, DataNode* data) {

	if(root == NULL) {
		printf("(Root empty)\n");
		return;
	}

	ListNode* iter = root;
	ListNode* child = create_list_node(data);

	while(iter->next != NULL) {
		iter = iter->next;
	}

	iter->next = child;

}

DataNode* get_neighbors(ListNode* root, int data) {

	if(root == NULL) {
		return NULL;
	}

	ListNode* iter = root;

	while(iter != NULL) {

		if(iter->data->data == data) {
			return iter->data;
		}

		iter = iter->next;
	}

	return NULL;
}

void insert_data_node(DataNode* root, int data) {

	if(root == NULL) {
		printf("Root empty\n");
		return;
	}

	DataNode* iter = root;

	DataNode* child = create_data_node(data);

	while(iter->next != NULL) {

		if(iter->data == data) {
			printf("Already exists\n");
			return;
		}

		iter = iter->next;
	}

	iter->next = child;
}

void print_nodes(ListNode* root) {

	if(root) {

		ListNode* iter = root;

		while(iter != NULL) {
			print_list_node(iter);
			iter = iter->next;
		}

	} else {
		printf("Root empty\n");
	}
}

void print_adjacent_nodes(DataNode* node) {

	if(node) {

		DataNode* iter = node;

		while(iter != NULL) {
			print_data_node(iter);
			printf("-> ");
			iter = iter->next;
		}

		printf("NULL");

	} else {
		printf("Root empty\n");
	}
}

void add_edge_adjacency(ListNode* root, int from, int to) {

	 DataNode* from_neigh = get_neighbors(root, from);
	 DataNode* to_neigh = get_neighbors(root, to);

	 if(from_neigh == NULL) {

	 	DataNode* from_node = create_data_node(from);
	 	insert_list_node(root, from_node);

	 	insert_data_node(from_node, to);

	 } else {
	 	insert_data_node(from_neigh, to);
	 }

	 if(to_neigh == NULL) {

	 	DataNode* to_node = create_data_node(to);
	 	insert_list_node(root, to_node);

	 	insert_data_node(to_node, from);

	 } else {
	 	insert_data_node(to_neigh, from);
	 }

	 printf("Inserted %d to %d edge\n", from, to);

}

void print_graph(ListNode* root) {

	if(root == NULL) {
		return;
	}

	ListNode* iter = root;

	while(iter != NULL) {

		//print_list_node(iter);
		//printf("->");
		print_adjacent_nodes(iter->data);
		printf("\n");

		iter = iter->next;
	}
}

void test() {

	DataNode* node = create_data_node(10);
	//DataNode* node = create_data_node(11);
	//print_data_node(node);

	for(int i = 0; i < 10; i++) {
		insert_data_node(node, i);
	}

	//print_adjacent_nodes(node);

	ListNode* list_node = create_list_node(node);
	//print_list_node(list_node);
	add_edge_adjacency(list_node, 20, 10);
	add_edge_adjacency(list_node, 25, 30);
	add_edge_adjacency(list_node, 25, 22);
	print_graph(list_node);

}

// MATRIX
#define VERTICES 10

int matrix[VERTICES][VERTICES];

void init_matrix() {

	for(int i = 0; i < VERTICES; i++) {
		for(int j = 0; j < VERTICES; j++) {
			matrix[i][j] = 0;
		}
	}
}

void add_edge_matrix(int from, int to) {

	matrix[from][to] = 1;
	matrix[to][from] = 1;
}

void print_graph_matrix() {

	for(int i = 0; i < VERTICES; i++) {

		for (int j = 0; j < VERTICES; j++) {
			
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void test_matrix() {

	add_edge_matrix(1, 2);
	add_edge_matrix(3, 4);
	add_edge_matrix(5, 3);
	add_edge_matrix(3, 2);

	print_graph_matrix();
}

#endif