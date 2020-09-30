//Implementation of a search binary tree with Breadth first search and depth level search
//Includes the use of queues via the implementation of linked lists for BFS

#include <stdio.h>
#include <stdlib.h>
#include "binary_s_tree.h"


int main () {
	struct treeNode *root = create_node(10);
	insert_node(root, 5);
	insert_node(root, 20);
	insert_node(root, 23);
	insert_node(root, 7);
	insert_node(root, 0);
	
	deletion_treeNode(root, 5);
	deletion_treeNode(root, 20);
	deletion_treeNode(root, 10);
	
	BFS(root);
	
	printf("\nThe height of the tree is: %d\n", tree_height(root));
	leveltraverse(root);
	print_level_newLine(root);
	/*
	printf("\n");
	inorder_trav(root);
	*/
	
	printf("Is the tree balanced? %d \n", BalancedTreeCheck(root) );
	
	printf("\n");
	deletion_treeNode(root, 5);
	printf("\n");
	
	leveltraverse(root);
	
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

