//Implementation of a search binary tree with Breadth first search and depth level search
//Includes the use of queues via the implementation of linked lists for BFS
#include <stdio.h>
#include <stdlib.h>
#include "binary_s_tree.h"

#define MAX_LENGTH 1024

typedef struct queueInternals *Queue;

typedef struct treeNode {
	treeNode *left;
	treeNode *right;
	int data;
	int height;
} treeNode;

struct queueNode {
	struct queueNode *next;
	//Store the binary tree treeNode in a queueNode
	treeNode *data;
};

struct queueInternals {
	struct queueNode *head;
	struct queueNode *tail;
	int size;
};

//-------------------------------------------------------------------------------
//Function declarations:
treeNode *create_node(int data);
treeNode *insert_node(treeNode *root, int data);

//Implementation of DFS
void inorder_trav(treeNode *treeNode);
void preorder_trav(treeNode *treeNode);
void postorder_trav(treeNode *treeNode);

//Implementation of a queue
struct queueInternals *create_queue();
void enqueue(Queue q, treeNode *treeNode);
treeNode *front_queue(Queue q);
treeNode *rear_queue(Queue q);
treeNode *dequeue(Queue q);
int queueSize(Queue q);

//Implementation of BFS
void BFS(treeNode *treeNode);
//Print a given level without the use of queues
void print_level(treeNode *node, int level);
int tree_height(treeNode *node);
void leveltraverse(treeNode *node);
//Print an entire level
void print_level_newLine(treeNode *node);

//These check the type of binary tree
int isFullBinaryTree(treeNode *node);

int height_perfect_tree(treeNode *node);
int isPerfectTree(treeNode *node, int height, int level);
int PerfectTreeCheck(treeNode *node);

int count_nodes(treeNode *node);
int isCompleteTree(treeNode *node, int index, int nodeCount);
int CompleteTreeCheck(treeNode *node);

int isBalancedTree(treeNode *node, int *height);
int BalancedTreeCheck(treeNode *node);
//Check for a data in the tree
int search_tree (treeNode *root, int data);
//Deletion of a node in a BST
treeNode *deletion_treeNode(treeNode *root, int data);
treeNode *inorder_travNP (treeNode *root);

//Add a treeNode
treeNode *create_node (int data) {
	treeNode *newNode = (treeNode*) malloc(sizeof(treeNode));
	//Initialise the treeNode with data
	newNode->data = data;
	//Set the children nodes to NULL
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->height = 1;
	return newNode;
}  

//Traverse the binary tree by inorder, preorder or postorder
void inorder_trav (treeNode *treeNode) {
	if (treeNode != NULL) {
		inorder_trav(treeNode->left);
		printf("%d ", treeNode->data);
		inorder_trav(treeNode->right);
	}
}
void preorder_trav (treeNode *treeNode) {
	if (treeNode != NULL) {
		printf("%d ", treeNode->data);
		preorder_trav(treeNode->left);
		preorder_trav(treeNode->right);
	}
}

void postorder_trav (treeNode *treeNode) {
	if (treeNode != NULL) {
		postorder_trav(treeNode->left);
		postorder_trav(treeNode->right);
		printf("%d ", treeNode->data);
	}
}

//Insert a treeNode in such a way that the tree is "organised"
treeNode *insert_node(treeNode *root, int data) {
	//Add a treeNode if the root is empty
	if (root == NULL) {
		return create_node(data);
	}
	//Insert to the right if the data is greater than the treeNode
	if (data > root->data) {
		root->right = insert_node(root->right, data);
	}
	//Insert to the left if the data is less than the treeNode
	else if (data < root->data) {
		root->left = insert_node(root->left, data);
	}
	//If all these conditions fail, change nothing
	return root;
}

//--------------------------------------------------------------------
//Queue implementation and BFS

Queue create_queue() {
	struct queueInternals *newQueue	
	= (struct queueInternals*) malloc(sizeof (struct queueInternals) );
	newQueue->tail = newQueue->head = NULL;
	newQueue->size = 0;
	return newQueue;
}

//Add a treeNode to the queue
void enqueue(Queue q, treeNode *treeNode) {
	struct queueNode *newNode = (struct queueNode*) malloc(sizeof (struct queueNode) );
	newNode->next = NULL;
	newNode->data = treeNode;
	//Consider case when q head is null
	if (q->head == NULL) {
		q->head = newNode;
	} 
	else {	
		q->tail->next = newNode; 
	}
	q->tail = newNode;
	q->size++;
}

treeNode *dequeue(Queue q) {
	if (q->head == NULL) {
		printf("Attempted to remove from an empty queue!");
	} 
	else {
		struct queueNode *remNode = q->head;
		treeNode *dataNode = q->head->data;
		q->head = q->head->next;
		//Check if removing the last treeNode in the queue;
		if (q->head == NULL) {
			q->tail == NULL;
		}
		free(remNode);
		q->size--;
		
		return dataNode;
	}
	
}
//This returns the size of the queue
int queueSize(Queue q) {
	return q->size;
}

treeNode *front_queue(Queue q) {
	return q->head->data;
}
treeNode *rear_queue(Queue q) {
	return q->tail->data;
}


//This performs a Level first search
void BFS(treeNode *root) {
	if (root != NULL) {
		Queue q = create_queue();
		enqueue(q, root);
		while (q->head != NULL) {
			treeNode *curr = dequeue(q);
			printf("%d ", curr->data);
			
			if (curr->left != NULL) {
				enqueue(q, curr->left);
			}
			if (curr->right != NULL) {
				enqueue(q, curr->right);
			}
		}		
	}
}
//------------------------------------------------------------------
//Implementation of level-specific printing of a binary tree

//Find the height of the tree
int tree_height(treeNode *node) {
	if (node == NULL) {
		return 0;
	}
	else {
		//Use recursion to find the height of each sub stree
		int l_height = tree_height (node->left);
		int r_height = tree_height (node->right);
		
		//Return the level of that sub stree
		if (l_height > r_height) {
			return l_height + 1;
		}
		else {
			return r_height + 1;
		}
	}

}
//This prints a node at the desired level
void print_level(treeNode *node, int level) {
	if (node == NULL) {
		return;
	}
	//Consider if printing a at level 1
	if (level == 1) {
		printf("%d ", node->data);
	}
	//Consider if printing an nth level
	else if (level > 1) {
		print_level(node->left, level - 1);
		print_level(node->right, level - 1);	
	}
	
	
}

//Function to traverse the entire tree by each level
void leveltraverse(treeNode *node) {
	int h = tree_height(node);
	for (int i = 1; i <= h; i++) {
		print_level(node, i);
		printf("\n");
	}
	printf("\n");
}

//----------------------------------------------------------
//Improved O(n) implementation of printing levels by line

void print_level_newLine(treeNode *node) {
	//BEWARE IF TREE IS NULL
	if (node == NULL) {
		return;
	}
	
	//Create queue for empty traversal
	Queue q = create_queue();
	//Add the root to the queue
	enqueue(q, node);
	
	//Stop when the queue size is zero
	//This means that the loop has reached the deepest parts of the tree
	while (queueSize(q) != 0) {
		int nodeCount = queueSize(q);
		
		//Iterate through each level
		while (nodeCount > 0) {
			treeNode *currNode = front_queue(q);
			printf("%d ", currNode->data);
			dequeue(q);
			if (currNode->left != NULL) {
				enqueue(q, currNode->left);
			}
			if (currNode->right != NULL) {
				enqueue(q, currNode->right);
			}
			nodeCount--;
		}
		printf("\n");
	}
	
}

//-----------------------------------------------------------------------
//This checks if the binary tree is full
int isFullBinaryTree(treeNode *node) {
	//Check if the root is NULL
	if (node == NULL) {
		return 1;
	}
	//Check if either the left or right nodes are NULL
	if (node->left == NULL && node->right == NULL) {
		return 1;
	}
	//Check that both the the left and right nodes are present
	if (node->left != NULL && node->right != NULL) {
		return (isFullBinaryTree(node->left) && isFullBinaryTree(node->right));
	}
	
	return 0;
	
}

//Check if the tree is perfect and return that value to the helper function
int isPerfectTree(treeNode *node, int height, int level) {
	//Check if the tree is null
	if (node == NULL) {
		return 1;
	}
	//Check for the presence of the left and right node if they are null
	//and compare them to the height of the tree
	if (node->left == NULL && node->right == NULL) {
		return (height == level + 1);
	}
	//CHeck if any node has a single child
	if (node->left == NULL || node->right == NULL) {
		return 0;
	}
	return (isPerfectTree(node->left, height, level + 1) 
	&& isPerfectTree(node->right, height, level + 1));
}

//Assuming the tree is perfect, find the number of levels and its height
int height_perfect_tree(treeNode *node) {
	int height = 0;
	while (node != NULL) {
		height++;
		node = node->left;
	}
	return height;
}
//This helper function returns a boolean value of whether the tree is perfect
//or imperfect
int PerfectTreeCheck(treeNode *node) {
	int height = height_perfect_tree(node);
	return isPerfectTree(node, height, 0);
}

//Count the number of nodes in the binary tree
int count_nodes(treeNode *node) {
	if (node == NULL) {
		return 0;
	}
	else {
		return (count_nodes(node->left) + count_nodes(node->right) + 1);
	}
}
//Checks whether a binary tree is complete or incomplete
int isCompleteTree(treeNode *node, int index, int nodeCount) {
	if (node == NULL) {
		return 1;
	}
	if (index >= nodeCount) {
		return 0;
	}
	
	return (isCompleteTree(node->left, 2*index + 1, nodeCount) 
	&& isCompleteTree(node->right, 2*index + 2, nodeCount));
	
}
//A helper function to return a boolean value whether the tree is complete or incomplete
int CompleteTreeCheck(treeNode *node) {
	int node_count = count_nodes(node);
	return isCompleteTree(node, 0, node_count);
}

//Checks if the tree is balanced or unbalanced and gets the height of the tree
int isBalancedTree(treeNode *node, int *height) {
	int leftHeight = 0;
	int rightHeight = 0;
	int l = 0;
	int r = 0;
	
	if (node == NULL) {
		*height = 0;
		return 1;
	}
	
	l = isBalancedTree(node->left, &leftHeight);
	r = isBalancedTree(node->right, &rightHeight);
	
	if (leftHeight > rightHeight) {
		*height = leftHeight + 1;
	} else {
		*height = rightHeight + 1;
	}
	
	
	if (leftHeight - rightHeight >= 2 || rightHeight - leftHeight >= 2) {
		return 0;
	}
	else {
		return l && r;
	}
}
//A helper function to return a boolean value if the the tree is balanced or not
int BalancedTreeCheck(treeNode *node) {
	int height = 0;
	return isBalancedTree(node, &height);
}

//-------------------------------------------------------
int search_tree (treeNode *root, int data) {
	
	if (root == NULL) {
		printf("The data was not found!\n");
		return 0;
	}
	if (data == root->data) {
		printf("The data was found! It is: %d", root->data);
		return root->data;
	}
	//Check to go left or right
	if (data > root->data) {
		return search_tree(root->right, data);
	}
	else if (data < root->data) {
		return search_tree(root->left, data);
	}
}
//-------------------------------------------------------

treeNode *deletion_treeNode(treeNode *root, int data) {
	
	//Traverse through the tree recursively
	if (root == NULL) {
		return root;
	}
	if (data > root->data) {
		root->right = deletion_treeNode(root->right, data);
	}
	else if (data < root->data) {
		root->left = deletion_treeNode(root->left, data);
	}
	else {
	//Consider three cases for deletion
	//1)Deletion of a leaf
	//2)Deletion of a node with ONLY one child
		if (root->left == NULL) {
			treeNode *temp = root->right;
			free(root);
			return temp;
		} 
		else if(root->right == NULL) {
			treeNode *temp = root->left;
			free(root);
			return temp;
		}
		//3)Deletion of a node with two children
		treeNode *temp = inorder_travNP(root->right);
		root->data = temp->data;
		//Delete the inorder successor
		root->right = deletion_treeNode(root->right, temp->data);
	}
	return root;
}

treeNode *inorder_travNP(treeNode *root) {
	treeNode *curr = root;
	//Loop to find the left most node
	while (curr->left != NULL) {
		curr = curr->left;
	}
	return curr;
}














