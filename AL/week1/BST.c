#include "BST.h"

void tree_ops() {

	BSTNode* root = create_node(12);
	insert(root, 14);
	insert(root, 10);
	inorder(root);
	printf("\n");

	if(search(root, 10) == 1) {
		printf("key found\n");
	} else {
		insert(root, 10);
	}
}

int main() {

	//test();
	tree_ops();
	printf("\n");

	return 0;
}