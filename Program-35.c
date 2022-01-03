/*
    --> Program to implement undirected graph traversal Depth First Search (DFS) Algorithm.
*/

/* Header Files */

#include <stdio.h>
#include <malloc.h>         // Header file for 'malloc()' function
#include <stdbool.h>        // Header file for 'bool' data type

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
void DFS (Node *, Node *, bool *);          // Function to implement DFS algorithm

/* Starting of 'main()' */

int main ()
{
	system("cls");

	int n;      // Variable to store total number of nodes
	
	printf("Input number of nodes in the graph --> ");
    scanf("%d", &n);

	Node *Graph = (Node *)malloc(n * sizeof(Node));     // Memory allocation for nodes of the graph
    bool *Visited = (bool *)malloc(n * sizeof(bool));   // Memory allocation for array to keep track of visited nodes during DFS traversal

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

	printf("Ready for DFS... ");
	system("pause");

	printf("\n");

    /* Loop to perform DFS traversal */

	for(int i = 0; i < n; i++)
	{
		if(*(Visited + i) == false)
		{
			DFS((Graph + i), Graph, Visited);
		}
	}

	printf("\b\b\b\b\b\b      ");
	printf("\n\n");
	system("pause");

	printf("\n");
	return 0;
}

void InitialiseGraph (Node *Graph, int n)
{
	for(int i = 0; i < n; i++)
	{
		(Graph + i)->Data = (i + 1);
		(Graph + i)->Next = NULL;
	}

	return;
}

void InsertEdge (Node *Graph, int u, int v)
{
	Node *NewData = (Node *)malloc(sizeof(Node));
	
	NewData->Data = (v + 1);
	NewData->Next = NULL;

	if(!(Graph + u)->Next)
	{
		(Graph + u)->Next = NewData;
		return;
	}

	Node *HeadNode = (Graph + u);

	do
	{
		HeadNode = HeadNode->Next;
	}while(HeadNode->Next != NULL);

	HeadNode->Next = NewData;
	
	return;
}

void DisplayGraph (Node *Graph, int n)
{
	Node *HeadNode;

	for(int i = 0; i < n; i++)
	{
		HeadNode = (Graph + i);
		HeadNode = HeadNode->Next;

		while(HeadNode)
		{
            printf("%d --> %d\n", (Graph + i)->Data, HeadNode->Data);
			HeadNode = HeadNode->Next;
		}

		printf("\n");
	}
	
	return;
}

void DFS (Node *HeadNode, Node *Graph, bool *Visited)
{
	printf("%d ----> ", HeadNode->Data);

	int Index = HeadNode->Data;	
	*(Visited + (Index - 1)) = true;
	
	while(HeadNode)
	{
        Index = HeadNode->Data;

		if(*(Visited + (Index - 1)) == false)
		{
			DFS((Graph + (Index - 1)), Graph, Visited);
		}
        
		HeadNode = HeadNode->Next;
	}
}