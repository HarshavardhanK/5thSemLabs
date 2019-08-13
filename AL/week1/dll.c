#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node* NODEPTR;

NODEPTR createNode(int val) {
	NODEPTR temp = (NODEPTR) malloc(sizeof(struct node));
	temp -> data = val;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;
}

void createList(NODEPTR *head, int val) {
	if (*head) {
		printf("\nList already created.\n");
		return;
	}
	*head = createNode(val);
}

void insertNode(NODEPTR *head, int new_val, int next_val) {
	if (!*head) {
		printf("\nNo list exists\n");
		return;
	}
	NODEPTR temp = *head;
	while (temp && temp -> data != next_val) {
		temp = temp -> right;
	}
	if (temp) {
		NODEPTR new_node = createNode(new_val);
		if (temp -> left) {
			new_node -> left = temp -> left;
			new_node -> right = temp;
			temp -> left -> right = new_node;
			temp -> left = new_node;
		}
		else {
			new_node -> right = temp;
			temp -> left = new_node;
			*head = new_node;
		}
	} else {
		printf("\nNext value not found.\n");
	}
	return;
}

void displayList(NODEPTR *head) {
	NODEPTR temp = *head;
	if(!temp) {
		printf("\nNo list created\n");
		return;
	}
	while (temp) {
		printf("%d ", temp -> data);
		temp = temp -> right;
	}
	printf("\n");
	return;
}

void deleteNodes(NODEPTR * head, int val) {
	NODEPTR temp = *head;
	if (!temp) {
		printf("\nNo list\n");
		return;
	}
	while (temp) {
		if (temp -> data == val) {
			NODEPTR temp_copy = temp;
			if (temp -> left && temp -> right) {
				temp -> right -> left = temp -> left;
				temp -> left -> right = temp -> right;
			}
			else if (temp -> left) {
				temp -> left -> right = NULL;
			} 
			else if (temp -> right) {
				temp -> right -> left = NULL;
				*head = temp -> right;
			}
			else {
				*head = NULL;
			}
			free(temp_copy);
		}
		temp = temp -> right;
	}
	return;
}

void searchKey(NODEPTR * head, int key) {
	NODEPTR temp = *head;
	if (!temp) {
		printf("\nEmpty list\n");
		return;
	}
	while(temp) {
		if (temp -> data == key) {
			printf("\nKey found\n");
			return;
		}
		temp = temp -> right;
	}
	printf("\nKey not found\n");
	return;
}

int main(int argc, char const *argv[])
{
	NODEPTR head = NULL;
	printf("1. Create list \n2. Insert node \n3. Delete node\n");
	printf("4. Search node \n5. Display list");
	int choice;
	while (1) {
		printf("\nEnter choice: \n");
		scanf("%d", &choice);
		int val, new_val, next_val;
		switch (choice) {
			case 1:
				printf("Enter value of head node: ");
				scanf("%d", &val);
				createList(&head, val);
				break;
			case 2:
				printf("\nEnter the value to be inserted: ");
				scanf("%d", &new_val);
				printf("\nEnter the value of the right node: ");
				scanf("%d", &next_val);
				insertNode(&head, new_val, next_val);
				break;
			case 3:
				printf("\nEnter value to be deleted: ");
				scanf("%d", &val);
				deleteNodes(&head, val);	
				break;
			case 4:
				printf("\nEnter search key value: ");
				scanf("%d", &val);
				searchKey(&head, val);
				break;	
			case 5:
				displayList(&head);
				break;
		}
		char c;
		getchar();
		printf("Do you want to continue? (y/n): \n");
		scanf("%c", &c);
		if (c == 'n')
			break;
	}
	return 0;
}