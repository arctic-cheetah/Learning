typedef struct queueInternals *Queue;
typedef struct treeNode treeNode;
//Function declarations:
struct treeNode *create_node(int data);
struct treeNode *insert_node(struct treeNode *root, int data);

//Implementation of DFS
void inorder_trav(struct treeNode *treeNode);
void preorder_trav(struct treeNode *treeNode);
void postorder_trav(struct treeNode *treeNode);

//Implementation of a queue
struct queueInternals *create_queue();
void enqueue(Queue q, struct treeNode *treeNode);
struct treeNode *front_queue(Queue q);
struct treeNode *rear_queue(Queue q);
struct treeNode *dequeue(Queue q);
int queueSize(Queue q);

//Implementation of BFS
void BFS(struct treeNode *treeNode);
//Print a given level without the use of queues
void print_level(struct treeNode *node, int level);
int tree_height(struct treeNode *node);
void leveltraverse(struct treeNode *node);
//Print an entire level
void print_level_newLine(struct treeNode *node);

//Check the type of binary tree
int isFullBinaryTree(struct treeNode *node);

int height_perfect_tree(struct treeNode *node);
int isPerfectTree(struct treeNode *node, int height, int level);
int PerfectTreeCheck(struct treeNode *node);

int count_nodes(struct treeNode *node);
int isCompleteTree(struct treeNode *node, int index, int nodeCount);
int CompleteTreeCheck(struct treeNode *node);

int isBalancedTree(struct treeNode *node, int *height);
int BalancedTreeCheck(struct treeNode *node);
//Search for a data in the tree
int search_tree (struct treeNode *root, int data);
//Deletion of a node in a BST
treeNode *deletion_treeNode(treeNode *root, int data);
treeNode *inorder_travNP (treeNode *root);








































