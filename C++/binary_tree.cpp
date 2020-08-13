//Implementation of a binary tree
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

struct node {
	struct node *left;
	struct node *right;
	int data;
};


int main () {
	Queue BFSqueue = create_queue();
	struct node *root = create_node(10);
	insert_node(root, 5);
	insert_node(root, 7);
	insert_node(root, 0);
	insert_node(root, 3);
	root = insert_node(root, 15);
	
	BFS(root, BFSqueue);

	inorder_trav(root);
	printf("\n");
	return 0;
}

//Add a node
struct node *create_node (int data) {
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	//Initialise the node with data
	newNode->data = data;
	//Set the children nodes to NULL
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
}  

//Traverse the binary tree by inorder, preorder or postorder
void inorder_trav (struct node *node) {
	if (node != NULL) {
		inorder_trav(node->left);
		printf("%d ", node->data);
		inorder_trav(node->right);
	}
}
void preorder_trav (struct node *node) {
	if (node != NULL) {
		printf("%d ", node->data);
		preorder_trav(node->left);
		preorder_trav(node->right);
	}
}

void postorder_trav (struct node *node) {
	if (node != NULL) {
		postorder_trav(node->left);
		postorder_trav(node->right);
		printf("%d ", node->data);
	}
}

//Insert a node in such a way that the tree is "organised"
struct node *insert_node(struct node *root, int data) {
	struct node *curr = root;
	//Add a node if the root is empty
	if (curr == NULL) {
		return create_node(data);
	}
	//Insert to the right if the data is greater than the node
	if (data > root->data) {
		curr->right = insert_node(curr->right, data);
	}
	//Insert to the left if the data is less than the node
	else if (data < curr->data) {
		curr->left = insert_node(curr->left, data);
	}
	//If all these conditions fail, change nothing
	return curr;
}

//Print a certain level






































