//Implementation of a search binary tree with Breadth first search and depth level search
//Includes the use of queues via the implementation of linked lists for BFS

#include <stdio.h>
#include <stdlib.h>
#include "AVL_T.h"



int main () {
	
	int array[] = {2, 5, 6, 9, 10, 11, 18, 23, 27, 31, 33, 39};
	struct treeNode *root = create_node(array[0]);
	for (int i = 1; i < 12; i +=1) {
		root = insert_node_AVL(root, array[i]);
	}
	
	postorder_trav(root);
	printf("\n");
	
	return 0;
}

