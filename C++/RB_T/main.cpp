//Implementation of a search binary tree with Breadth first search and depth level search
//Includes the use of queues via the implementation of linked lists for BFS

#include <stdio.h>
#include <stdlib.h>
#include "RB_T.h"


int main () {
	struct treeNode *root = insert(NULL ,15);
	root = insert(root, 5);
	root = insert(root, 29);
	root = insert(root, 41);
	root = insert(root, 43);
	root = insert(root, 45);
	root = insert(root, 48);
	root = insert(root, 50);
	BFS(root);
	
	printf("\nThe height of the tree is: %d\n", tree_height(root));
	leveltraverse(root);
	print_level_newLine(root);
	
	printf("\n");
	inorder_trav(root);
	/*
	printf("\n");
	inorder_trav(root);
	*/
	
	/*
	if (isFullBinaryTree(root)) {
		printf("The binary tree is a full tree!\n");
	}
	else {
		printf("The binary tree is not a full tree!\n");
	}
	
	if (PerfectTreeCheck(root)) {
		printf("The binary tree is a perfect tree!\n");
	}
	else {
		printf("The binary tree is an imperfect tree!\n");
	}
	
	if (CompleteTreeCheck(root)) {
		printf("The binary tree is a complete tree!\n");
	}
	else {
		printf("The binary tree is an incomplete tree!\n");
	}
	
	if (BalancedTreeCheck(root)) {
		printf("The binary tree is a balanced tree!\n");
	}
	else {
		printf("The binary tree is an unbalanced tree!\n");
	}
	*/
	
	
	
	
	return 0;
}

