//Data type declarations
typedef struct node node;
typedef struct array array;
typedef struct graph graph;

//Function declarations
node *create_adjNode(int dest);
graph *create_graph(int size);
void add_edge(graph *myGraph, int source, int dest);
void print_graph(graph *Graph);
void remove_edge(graph *Graph, int source, int dest);






















































