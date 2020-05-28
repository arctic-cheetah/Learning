//Implementation of a search binary tree with Breadth first search and depth level search
//Includes the use of queues via the implementation of linked lists for BFS

#include <stdio.h>
#include <stdlib.h>
#include "AVL_T.h"


int main () {
	//REMEMBER TO UPDATE THE ROOTS IF THEY RE-BALANCED!
	struct treeNode *root = create_node(10);
	root = insert_node_AVL(root, 5);
	root = insert_node_AVL(root, 20);
	root = insert_node_AVL(root, 1);
	root = insert_node_AVL(root, 6);
	root = insert_node_AVL(root, 21);
	inorder_trav(root);
	
	printf("\nThe height of the tree is: %d\n", tree_height(root));
	leveltraverse(root);
	printf("\n");
	
	//delete_node_AVL(root, 1);
	root = delete_node_AVL(root, 10);
	print_level_newLine(root);
	printf("\n");
	inorder_trav(root);
	printf("\n");
	
	/*
	printf("\n");
	inorder_trav(root);
	
	printf("\n");
	search_tree(root, 19);
	printf("\n");
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

