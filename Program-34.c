/*
    --> Program to create an undirected graph using adjecency list.
*/

/* Header Files */

#include <stdio.h>
#include <malloc.h>         // Header file for 'malloc()' function

/* Structure definition for 'Node' of graph */

typedef struct Node
{
	int Data;
	struct Node *Next;
}Node;      // Defined 'struct Node' as 'Node' using 'typedef'

/* Function declarations */

void InitialiseGraph (Node *, int);         // Function to initialize all the nodes of the graph
void InsertEdge (Node *, int, int);         // Function to insert a new edge between two nodes
void DisplayGraph (Node *, int);            // Function to display the graph

/* Starting of 'main()' */

int main ()
{
	system("cls");

	int n;      // Variable to store total number of nodes
	
	printf("Input number of nodes in the graph --> ");
    scanf("%d", &n);

	Node *Graph = (Node *)malloc(n * sizeof(Node));     // Memory allocation for nodes of the graph
	InitialiseGraph (Graph, n);                         // Function calling to initialise all the nodes of the graph

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

		InsertEdge (Graph, u, v);       // Function calling to insert an edge from 'u' to 'v'
		InsertEdge (Graph, v, u);       // Function calling to insert an edge from 'u' to 'v'

        /* Since we are creating an undirected graph, therefore, every edge is bidirectional. Therefore, if there exist an edge from 'u' to 'v', then there will be automatically an edge from 'v' to 'u'. */

		printf("\nSuccess !\n");
		printf("\n");
	}

	printf("Graph is ready to display ! ");
	system("pause");

	printf("\n");
	DisplayGraph (Graph, n);        // Function calling to display the graph created
	system("pause");

	return 0;

    /* End of 'main()' */
}

/* Function definitions */

void InitialiseGraph (Node *Graph, int n)               // Function to initialize all the nodes of the graph
{
    /* Loop to initialize all he nodes of the graph */

	for(int i = 0; i < n; i++)
	{
		(Graph + i)->Data = (i + 1);        // Initializing data of a node as the node number

        /* Initializing next pointer of a node as 'NULL', since the node is not connected to another node initially */
		(Graph + i)->Next = NULL;
	}

	return;
}

void InsertEdge (Node *Graph, int u, int v)             // Function to insert a new edge between two nodes
{
	Node *NewData = (Node *)malloc(sizeof(Node));       // Allocating memory for new destination node
	
	NewData->Data = (v + 1);        // Initializing data of new destination node as the destination node number
	NewData->Next = NULL;           // Initializing next pointer of new destination node as 'NULL'

	if(!(Graph + u)->Next)      // Check if list for source node is empty or not. If list is empty, source node points to NULL
	{
		(Graph + u)->Next = NewData;        // If list for source node is empty, Source node will point to new destination node
		return;
	}

    /* If list for source node is not 'NULL', list is not empty */

	Node *HeadNode = (Graph + u);       // Make source node as head node

    /* Loop to add destination node at the last of the list */

	do
	{
		HeadNode = HeadNode->Next;      // Move head node to next node
	}while(HeadNode->Next != NULL);     // Move head node till the head node points to 'NULL' (It will be the last node in the list)

	HeadNode->Next = NewData;       // Append new destination node at the last of the list
	
	return;
}

void DisplayGraph (Node *Graph, int n)          // Function to display the graph
{
	Node *HeadNode;

    /* Loop to display the graph (Formate: Source node --> Destination node) */

	for(int i = 0; i < n; i++)      // Outer loop to traverse all the nodes
	{
		HeadNode = (Graph + i);     // Make current node as head node
		HeadNode = HeadNode->Next;

		while(HeadNode)         // Inner loop to traverse the list for a single node
		{
            printf("%d --> %d\n", (Graph + i)->Data, HeadNode->Data);       // Print data for current node & desination node
			HeadNode = HeadNode->Next;      // Move head node to next node
		}

		printf("\n");
	}
	
	return;
}