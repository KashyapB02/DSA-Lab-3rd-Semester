/*
    --> Program to find number of node & leaves in the tree.
*/

/* Header files */

#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>          // Header file for 'malloc()' function
#include<ctype.h>           // Header file for 'toupper()' function

/* Structure definition for 'Tree' */

typedef struct Tree
{
	int data;               // Variable to store data of the node
	struct Tree *left;      // Pointer variable to point to left child of a node
	struct Tree *right;     // Pointer variable to point to left child of a node
}Tree;

/* Global variable */

Tree *root = NULL;          // Variable to store 'root' node of the tree

/* Function declarations */

Tree* create_node(int);             // Function to create and return a new node for the tree
void insert_node(Tree *);           // Function to insert a new node to the tree
int nodes(Tree *);                  // Function to count total number of nodes of the tree
int leaves(Tree *);                 // Function to count total number of leaves of the tree

/* Starting of 'main()' */

int main()
{
	system("cls");

    printf("Creating Tree... ");
    system("pause");

    printf("\n");

	int data;           // Variable to store user input of the data for a node
	char choice;

	/* Loop to create the tree */
    
    do
	{
		printf("Input data --> ");          // Asking user to input data for a node
		scanf("%d", &data);

		// Function calling to create and insert a node to the tree
        insert_node(create_node(data));
		printf("\n");

		printf("Input more data? (Y/N) --> ");

        fflush(stdin);
		choice = getchar();

		choice = toupper(choice);
		printf("\n");
		
	} while (choice == 'Y');

	printf("\n");

    // Counting and printing total number of nodes of the tree using 'nodes()' function
	printf("Total number of nodes in the tree is --> %d\n", nodes(root));

	printf("\n");

    // Counting and printing total number of leaves of the tree using 'leaves()' function
	printf("Total number of leaves in the tree is --> %d\n", leaves(root));

	printf("\n");
	return 0;

    /* End of 'main()' */
}

/* Function definitions */

Tree* create_node(int data)         // Function to create and return a new node for the tree
{
    Tree *node = (Tree *)malloc(sizeof(Tree));      // Memory allocation for new node

	node->data  = data;         // Assigning data to the node
	node->left  = NULL;         // Initialising 'left' pointer with NULL
	node->right = NULL;         // Initialising 'right' pointer with NULL

    return node;        // Returning the new node
}

void insert_node(Tree *node)        // Function to insert a new node to the tree
{
    if(!root)       // Condition to check if 'root' is NULL
    {
        root = node;        // If root is NULL, current node will be root node
        return;
    }

    Tree *current = root, *parent = NULL;           // Current point to root node of the tree  

    while(true)
    {
        parent = current;           // Parent keep track of the parent node of current node.

        // If data is less than current node's data, node will be inserted to the left of tree  
        if((node->data) < (current->data))
        {
            // Shift position of current node to the left of the current node
            current = current->left;

            if(!current)        // If current position is NULL, insert new node here
            {
                parent->left = node;        // Inserting node
				return;
            }
        }
		// If data is greater than or equal current node's data, node will be inserted to the left of tree 
        else
		{
			// Shift position of current node to the right of the current node
            current = current->right;

			if(!current)        // If current position is NULL, insert new node here
			{
				parent->right = node;       // Inserting node
				return;
			}
		}
    }
}

int nodes(Tree *root)               // Function to count total number of nodes of the tree
{
	static int node = 0;            // Static variable to count the number of node
	
	if(!root)       // If root is NULL, There will be no more node
	{
		return node;        // Return total number of nodes
	}
	
	// If both left and right child of a node is NULL, it's a leaf
    if((root->left == NULL) && (root->right == NULL))
	{
		return node;
	}

    // If none of the above condition is true, it's a node
	node++;                 // Increment node by 1

	nodes(root->left);      // Traverse left subtree
	nodes(root->right);     // Traverse right subtree

    return node;        // Return total number of nodes
}

int leaves(Tree *root)              // Function to count total number of leaves of the tree
{
	static int leaf = 0;            // Static variable to count the number of leaf
	
	if(!root)        // If root is NULL, There will be no more node
	{
		return leaf;        // Return total number of leaves
	}
	
    // If both left and right child of a node is NULL, it's a leaf
	if((root->left == NULL) && (root->right == NULL))
	{
		leaf++;             // Increment leaf by 1
		return leaf;
	}

    // If none of the above condition is true, it's a node

	leaves(root->left);     // Traverse left subtree
	leaves(root->right);    // Traverse right subtree

    return leaf;            // Return total number of leaves
}

/*





*/