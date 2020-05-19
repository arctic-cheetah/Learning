//Implementation of a binary tree with Breadth first search and depth level search
//Includes the use of queues via the implementation of linked lists for BFS
#include <stdio.h>
#include <stdlib.h>
#include "binary_tree_queue.h"

#define MAX_LENGTH 1024

typedef struct queueInternals *Queue;

struct treeNode {
	struct treeNode *left;
	struct treeNode *right;
	int data;
};

struct queueNode {
	struct queueNode *next;
	//Store the binary tree treeNode in a queueNode
	struct treeNode *data;
};

struct queueInternals {
	struct queueNode *head;
	struct queueNode *tail;
	int size;
};

//-------------------------------------------------------------------------------
//Function declarations:
struct treeNode *create_node(int data);
struct treeNode *insert_node(struct treeNode *root, int data);

//Implementation of DFS
void inorder_trav(struct treeNode *treeNode);
void preorder_trav(struct treeNode *treeNode);
void postorder_trav(struct treeNode *treeNode);
//Implementation of BFS
struct queueInternals *create_queue();
void enqueue(Queue q, struct treeNode *treeNode);
struct treeNode *dequeue(Queue q);
void BFS(struct treeNode *treeNode);


//Add a treeNode
struct treeNode *create_node (int data) {
	struct treeNode *newNode = (struct treeNode*) malloc(sizeof(struct treeNode));
	//Initialise the treeNode with data
	newNode->data = data;
	//Set the children nodes to NULL
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
}  

//Traverse the binary tree by inorder, preorder or postorder
void inorder_trav (struct treeNode *treeNode) {
	if (treeNode != NULL) {
		inorder_trav(treeNode->left);
		printf("%d ", treeNode->data);
		inorder_trav(treeNode->right);
	}
}
void preorder_trav (struct treeNode *treeNode) {
	if (treeNode != NULL) {
		printf("%d ", treeNode->data);
		preorder_trav(treeNode->left);
		preorder_trav(treeNode->right);
	}
}

void postorder_trav (struct treeNode *treeNode) {
	if (treeNode != NULL) {
		postorder_trav(treeNode->left);
		postorder_trav(treeNode->right);
		printf("%d ", treeNode->data);
	}
}

//Insert a treeNode in such a way that the tree is "organised"
struct treeNode *insert_node(struct treeNode *root, int data) {
	struct treeNode *curr = root;
	//Add a treeNode if the root is empty
	if (curr == NULL) {
		return create_node(data);
	}
	//Insert to the right if the data is greater than the treeNode
	if (data > root->data) {
		curr->right = insert_node(curr->right, data);
	}
	//Insert to the left if the data is less than the treeNode
	else if (data < curr->data) {
		curr->left = insert_node(curr->left, data);
	}
	//If all these conditions fail, change nothing
	return curr;
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
void enqueue(Queue q, struct treeNode *treeNode) {
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

struct treeNode *dequeue(Queue q) {
	if (q->head == NULL) {
		printf("Attempted to remove from an empty queue!");
	} 
	else {
		struct queueNode *remNode = q->head;
		struct treeNode *dataNode = q->head->data;
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

//This performs a Level first search
void BFS(struct treeNode *treeNode) {
	
	if (treeNode != NULL) {
		Queue q = create_queue();
		enqueue(q, treeNode);
		while (q->head != NULL) {
			struct treeNode *curr = dequeue(q);
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






































