//A program that uses graphs as its data structure.

#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"




int main() {
	printf("Hello Obstinate! \n");
	
	graph *myGraph = create_graph(5);
	//print_graph(myGraph);
	add_edge(myGraph, 0, 1);
	add_edge(myGraph, 0, 2);
	add_edge(myGraph, 0, 3);
	add_edge(myGraph, 0, 4);
	add_edge(myGraph, 0, 4);
	print_graph(myGraph);
	
	printf("\n");
	
	remove_edge(myGraph, 0, 4);
	print_graph(myGraph);
	
	exit(0);
}













