/*
    --> Program to implement graph traversal Breath First Search Algorithm.
*/

/* Header files */

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

/* Structure declarations */

/* Structure declaratin for graph */
typedef struct graph {

    int nodeNumber;
    struct graph *connection;
} graph;

/* Structure declaratin for queue */
typedef struct queue {

    int nodeNumber;
    struct queue *nextNode;
} queue;

/* Global variables */

queue *front = NULL, *rear = NULL;      // Pointer variables to store front & rear node of the queue
bool *isAdded;                          // Pointer variable to create array to keep track of added nodes during BFS traversal

/* Function declarations */

void initializeGraph (graph *, int );       // Function declaration to initialize the adjecency list of the nodes of the graph
void initializeisAdded (int);               // Function declaration to initialize the isAdded array
void createEdge (graph *, int, int);        // Function declaration to create an edge between two nodes of the graph
void displayGraph (graph *, int);           // Function declaration to display the created graph

void addToQueue (int);      // Function declaration to add nodes to the queue
int removeFromQueue ();     // Function declaration to delete front node from the queue   
bool emptyQueue ();         // Function declaration to check wheather the queue is empty or not
void BFS (graph *, int);    // Function declaration to perform Breadth First Search (BFS)

/* Start of main() */
int main()
{
    system("cls");

    int n;      // Variable to store total number of nodes
	
	printf("Input number of nodes in the graph --> ");
    scanf("%d", &n);

	graph *nodeList = (graph *)malloc(n * sizeof(graph));       // Memory allocation for nodes of the graph
    isAdded = (bool *)malloc(n * sizeof(bool));               // Memory allocation for array to keep track of added nodes during BFS traversal

	initializeGraph (nodeList, n);      // Function calling to initialise all the nodes of the graph
    initializeisAdded (n);            // Function calling to initialise all the nodes of the graph

	int m;      // Variable to store total number of edges

	printf("Input number of edges in the graph --> ");
    scanf("%d", &m);

	int u, v;       // Variable to store starting and ending nodes for a edge
	printf("\n");

    /* Loop to insert all the edges of the graph */

	for(int i = 0; i < m; i++)
	{
        printf("Input edge %d:\n", (i + 1));
        printf("\n");

        printf("From node --> ");
		scanf("%d", &u);

        printf("To node   --> ");
        scanf("%d", &v);

		u--; v--;

		createEdge (nodeList, u, v);       // Function calling to insert an edge from 'u' to 'v'
		createEdge (nodeList, v, u);       // Function calling to insert an edge from 'u' to 'v'

        /* Since we are creating an undirected graph, therefore, every edge is bidirectional. Therefore, if there exist an edge from 'u' to 'v', then there will be automatically an edge from 'v' to 'u'. */

		printf("\nSuccess !\n");
		printf("\n");
	}

	printf("Graph is ready to display ! ");
	system("pause");

	printf("\n");
	displayGraph (nodeList, n);        // Function calling to display the graph created

    printf("Ready for BFS... ");
	system("pause");

    printf("\n");
    printf("BFS of created graph is: ");

    /* Loop to perform BFS traversal */
    for (int i = 0; i < n; i++) {

        if(*(isAdded + i) == false) { BFS (nodeList, (i + 1)); }    // Function call to perform BFS
    }

    printf ("\b\b\b\b\b\b      ");

    printf("\n");
    return 0;
}
/*End of main() */

/* Function definitions */

/* Function definition to initialize the adjecency list of the nodes of the graph */
void initializeGraph (graph *nodeList, int totalNode) {

    // Loop to initalize the adjecency list of the nodes of the graph
    for (int i = 0; i < totalNode; i++) {

        (nodeList + i)->nodeNumber = (i + 1) ;
        (nodeList + i)->connection = NULL;
    }
}

/* Function definition to initialize the isAdded array */
void initializeisAdded (int size) {

    // Loop to initalize the isAdded array
    for (int i = 0; i < size; i++) { *(isAdded + i) = false; }
}

/* Function definition to create an edge between two nodes of the graph */
void createEdge (graph *nodeList, int sourceNode, int destinationNode) {

    // Memory allocation for the new node
    graph *newNode = (graph *)malloc(sizeof(graph));

    // Initialization of the new node
    newNode->nodeNumber = (destinationNode + 1);
    newNode->connection = NULL;

    /* Adding the new node to the list of connected nodes with the source node */

    // If no node is connected with the source node, the new node will ve the first connected node
    if(!((nodeList + sourceNode)->connection)) {

        (nodeList + sourceNode)->connection = newNode;
        return;
    }

    /* If some nodes are already added to the list of connected nodes with the source node, new node will be added to the last of the list */

    graph *tempHeadNode = (nodeList + sourceNode);  // Temprory pointer variable to keep track of the head of the list

    // Loop to find the last connected node
    do
    {

        tempHeadNode = tempHeadNode->connection;
    }while((tempHeadNode->connection) != NULL);

    // Adding new node to the last of the list of connected nodes with the source node
    tempHeadNode->connection = newNode;
    
    return;
}

/* Function definition to display the created graph */
void displayGraph (graph *nodeList, int totalNode) {

    // Loop to display the lists of all the connected nodes for each node of the adjacency list of the nodes
    for (int i = 0; i < totalNode; i++) {

        graph *tempHeadNode = (nodeList + i);       // Temprory pointer variable to keep track of the head of the list
        tempHeadNode = tempHeadNode->connection;

        // Loop to traverse and display each conncted nodes to the head node
        while(tempHeadNode) {

            printf("%d --> %d\n", (nodeList + i)->nodeNumber, tempHeadNode->nodeNumber);
			tempHeadNode = tempHeadNode->connection;    // Move pointer to the next connected node after displaying the current node
        }

        // Change line after displaying the list for each node of the adjacency list
        printf("\n");
    }

    return;
}

/* Function definition to add nodes to the queue */
void addToQueue (int nodeNumber) {

    // Memory allocation for a new node that to be inserted in the queue
    queue *newNode = (queue *)malloc(sizeof(queue));

    // Initialization of the new node
    newNode->nodeNumber = nodeNumber;
    newNode->nextNode = NULL;

    // Condition to check if the queue is empty or not. If queue is empty, front as well as rear is NULL
    if ((front == NULL) && (rear == NULL)) {

        // If queue is empty, new node is front as well as rear node
        front = rear = newNode;
        return;
    }

    /* If front as well as rear is not NULL, queue is not empty */

    rear->nextNode = newNode;       // Make last node point to new node
    rear = newNode;                 // Assign new node as rear node

    return;
}

/* Function definition to delete front node from the queue */
int removeFromQueue () {

    int nodeNumber;         // Variable to store node number of the front node
    queue *currentNode;     // Pointer variable to store the front node

    /* If front & rear is same node, there is only one node left in the queue */
    if (front == rear) {

        nodeNumber = front->nodeNumber;     // Store node number of the front node
        currentNode = front;                // Store the front node in pointer variable

        front = rear = NULL;        // Make front & rear NULL (this means there is no any node left in the queue)

        free (currentNode);     // Delete the front node
        return nodeNumber;      // Return node number of the deleted node
    }

    /* If front & rear node is not same, queue contains more than one node */

    nodeNumber = front->nodeNumber;     // Store node number of the front node
    currentNode = front;                // Store the front node in pointer variable

    front = front->nextNode;        // Move front to the next available node

    free (currentNode);     // Delete the front node
    return nodeNumber;      // Return node number of the deleted node
}   

/* Function definition to check wheather the queue is empty or not */
bool emptyQueue () { return ((front == NULL) && (rear == NULL)); }  // Returns true if queue is empty, otherwise return false

/* Function definition to perform Breadth First Search (BFS) */
void BFS (graph *nodeList, int nodeNumber) {

    addToQueue(nodeNumber);         // Add given node number to the queue

    int index = (nodeNumber - 1);
    *(isAdded + index) = true;      // Mark given node number as added in 'isAdded` array

    /* Loop to perform BFS traversal */
    while (!emptyQueue()) {

        int node = removeFromQueue ();      // Remov the front node from the queue 
        printf ("%d ----> ", node);

        index = (node - 1);

        graph *tempHeadNode = (nodeList + index);   // Temprory pointer variable to keep track of the head of the list of conncted nodes to the current node
        tempHeadNode = tempHeadNode->connection;

        // Loop to traverse and add each conncted nodes to the current node to te queue
        while(tempHeadNode) {

            int currentNodeNumber = (tempHeadNode->nodeNumber);
            int currentIndex = (currentNodeNumber - 1);

            // If the current connected node is not added to the queue, add it to the queue
            if(*(isAdded + currentIndex) == false) {
                
                addToQueue (currentNodeNumber);     // Add current conncted node to the queue
                *(isAdded + currentIndex) = true;   // Mark current conncted node as added in 'isAdded' array
            }

            tempHeadNode = tempHeadNode->connection;    // Move pointer to the next connected node after adding the current connected node
        }
    }
    
    return;
}