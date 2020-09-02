//A program that explores the implementation of a graph data structure via
//adjacency lists


#include <stdio.h>
#include <stdlib.h>


//Store the linked list in an array for the graph.
//Also known as an adjacency list

typedef struct node {
	int data;
	int multipleEdge;
	struct node *next;
} node;

typedef struct array {
	node *head;
} array;

typedef struct graph {
	int vertices;
	array *array;
} graph;



//A function that creates an adjacency node
node *create_adjNode(int dest) {
	//allocate memory for the adjNode
	node *adjNode = (node *) malloc(sizeof(node));
	adjNode->next = NULL;
	adjNode->data = dest;
	adjNode->multipleEdge = 1;
	
	return adjNode;
}

//A function that creates a graph of V vertices

graph *create_graph(int size) {
	//CHECK THIS syntax
	//Create a graph
	graph *newGraph = (graph *) malloc(sizeof(graph));
	newGraph->vertices = size;
	
	//Create the array of the adjacency list
	newGraph->array = (array *) malloc(sizeof(array) * size);
	
	//Declare each entry in the array, and then point each entry to null
	for (int i = 0; i < size; i++) {
		newGraph->array[i].head = NULL;
	}
	
	return newGraph;
}

//Adds an edge to the graph
void add_edge(graph *myGraph, int source, int dest) {
	//Check if a node does not exist in the graph
	node *nodeCheck = myGraph->array[source].head;
	while (nodeCheck != NULL && nodeCheck->data != dest) {
		nodeCheck = nodeCheck->next;
	}
	if (nodeCheck == NULL) {
		//then create a node and attach it to the beginning of the source entry
		node *newNode = create_adjNode(dest);
		newNode->next = myGraph->array[source].head;
		myGraph->array[source].head = newNode;
		
		//As the graph is undirected
		//then add an edge to the destination to source.
		newNode = create_adjNode(source);
		newNode->next = myGraph->array[dest].head;
		myGraph->array[dest].head = newNode;
	}
	//A current edge exists
	else {
		nodeCheck->multipleEdge++;
		//Add the corresponding multiple edge to dest to source;
		nodeCheck = myGraph->array[dest].head;
		while (nodeCheck != NULL && nodeCheck->data != source) {
			nodeCheck = nodeCheck->next;
		}
		nodeCheck->multipleEdge++;
	}
}

//A function that prints out the adjacency list 

void print_graph(graph *Graph) {
	
	if (Graph->array == NULL) {
		printf("You have the empty graph\n");
	}
	else {
		node *loopNode = NULL;
		//Loop through the array in the graph
		for (int i = 0; i < Graph->vertices; i++) {
			printf("[%d]->", i);
			//Loop through the linked list in each entry of the array	
			loopNode = Graph->array[i].head;
			while (loopNode != NULL) {
				printf("%dM%d->", loopNode->data, loopNode->multipleEdge);
				loopNode = loopNode->next;
			}
			printf("\n");
		}
	}
	
}
//Need to account if nothing is being deleted

//A function that deletes edges in a graph
void remove_edge(graph *Graph, int source, int dest) {
	//Loop through the array in the graph
	node *nodeCurr = Graph->array[source].head;
	node *nodePrev = nodeCurr;
	node *rmNode = NULL;
	
	//Loop through linked list in the entry of the array
	//Check if the first entry has the destination
	if (nodeCurr->data == dest) {
		Graph->array[source].head = nodeCurr->next;
		rmNode = nodeCurr;
		free(rmNode);
	}
	else {
		while (nodeCurr != NULL) {
			if (nodeCurr->data == dest) {
				nodePrev->next = nodeCurr->next;
				rmNode = nodeCurr;
				nodeCurr = NULL;
				free(rmNode);
				break;
			}
			nodePrev = nodeCurr;
			nodeCurr = nodeCurr->next;
		}
	}
	
	//Apply to dest to source
	nodeCurr = Graph->array[dest].head;
	nodePrev = nodeCurr;
	rmNode = NULL;
	
	//Check if the first entry in the linked list needs to be removed.
	if (nodeCurr->data == source) {
		Graph->array[dest].head = nodeCurr->next;
		rmNode = nodeCurr;
		free(rmNode);
	}
	else {
		while (nodeCurr != NULL) {
			if (nodeCurr->data == source) {
				nodePrev->next = nodeCurr->next;
				rmNode = nodeCurr;
				nodeCurr = NULL;
				free(rmNode);	
			}
			nodePrev = nodeCurr;
			nodeCurr = nodeCurr->next;
		}
	}	
}










































































































