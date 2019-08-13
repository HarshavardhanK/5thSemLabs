#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1
typedef int bool;

struct BSTNODE {

	struct BSTNODE* right;
	struct BSTNODE* left;

	int key;
};

typedef struct BSTNODE BSTNode;

BSTNode* create_node(int data) {
	BSTNode* node = (BSTNode*) malloc(sizeof(BSTNode));
	node->key = data;
	return node;
}

void print_node(BSTNode* node) {
	printf("%d ", node->key);
}

void test() {

	BSTNode* node = create_node(5);
	print_node(node);
}

// 	TREE OPERATIONS //

void insert(BSTNode* root, int data) {

	if(root == NULL) {
		printf("root is NULL.\n");

		
	} else {

		BSTNode* child = root;
		BSTNode* node = create_node(data);

		while(child->right != NULL && child->left != NULL) {

			if(data > child->key) {
				child = child->right;

			} else if(data < child->key) {
				child = child->left;
			}

		}

		if(data > child->key) {
			child->right = node;

		} else {
			child->left = node;
		}
	}

	printf("Inserted %d\n", data);

}

bool search(BSTNode* root, int key) {

	if(root == NULL) {
		return false;
	}

	if(key > root->key) {
		int right = search(root->right, key);

	} else if(key < root->key) {
		int left = search(root->left, key);

	} else {
		return true;
	}

}

void inorder(BSTNode* root) {

	if(root == NULL) {
		return;
	}

	inorder(root->left);
	print_node(root);
	inorder(root->right);
}

#endif