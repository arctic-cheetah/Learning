#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "binary_tree_queue.h"


int main () {
	struct treeNode *root = create_node(10);
	insert_node(root, 5);
	insert_node(root, 20);
	insert_node(root, 23);
	//insert_node(root, 25);
	//insert_node(root, 7);
	//insert_node(root, 0);
	//insert_node(root, 3);
	root = insert_node(root, 35);

	
	BFS(root);
	
	printf("\nThe height of the tree is: %d\n", tree_height(root));
	leveltraverse(root);
	print_level_newLine(root);
/*
	inorder_trav(root);
	printf("\n");
	
*/
	printf("\n");
	
	
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
	
	
	
	
	
	return 0;
}

