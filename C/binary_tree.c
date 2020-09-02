//Implementation of a binary tree
#include <stdio.h>
#include <stdlib.h>

struct node {
	int *left;
	int *right;
	int data;
};

struct node *create_node(int data);
struct node *insert_node(struct node *root, int data);

int main () {
	struct node *root = create_node(10);
	insert_node(root, 5);
	insert_node(root, 15);
	/*
	int num;
	while (scanf("%d", &num) != EOF) {
		
		
	}*/
	
	printf("%d", root->data);
	return 0;
}


struct node *create_node (int data) {
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	//Initialise the node with data
	newNode->data = data;
	//Set the children nodes to NULL
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
}  

struct node *insert_node(struct node *root, int data) {
	struct node *curr_node = root;
	//Add a node if the root is empty
	if (curr_node == NULL) {
		return create_node(data);
	}
	//Insert to the right if the data is greater than the node
	if (data > curr_node->data) {
		curr_node->right = insert_node(curr_node->right, data);
	}
	//Insert to the left if the data is
	else if (data < curr_node->data) {
		curr_node->left = insert_node(curr_node->left, data);
	}
	//If all these conditions fail, change nothing
	return curr_node;
}








































