/*
    --> Program for creating a new Node and inserting at the end of a Singly Linked List.
*/

/* Header files */

#include <stdio.h>
#include <stdlib.h>     // Header file for 'malloc()' function
#include<ctype.h>		// Header file for 'toupper()' function

/* Structure declaration for Nodes of singly linked list */

struct NODE
{
    int info;               // Variable to store information for the node
    struct NODE *Next;      // Pointer variable for pointing to the next node
}*start, *end;

/* Function declarations */

struct NODE* create_node();         // Function declaration to create and return new node
void add_node(struct NODE*);        // Function declaration to add new node to the list
void display_list();                // Function declaration to display list

/* Starting of main() */

int main()
{
    system("cls");

    start = end = NULL;       // Initialize the 'start' & 'end' pointer with NULL.

    printf("Initial list:\n");
	display_list();			// Function calling to display list

	printf("\n");
	printf("Creating list... ");
	system("pause");

	char choice;

    /* Loop for creating and adding new node in the list */

    do
	{
		printf("\nCreate node:\n");
		printf("\n");

		add_node(create_node());		// Function callings to create & add new node in the list
		printf("\n");

		printf("The list is now:\n");
		display_list();					// Function calling to display list

		printf("\n");
		printf("\nWant to add more node to the list? (Y/N) --> ");
		scanf(" %c", &choice);

		choice = toupper(choice);
		printf("\n");

	} while (choice == 'Y');	// Checking choice of user
	
	printf("\n");
	printf("\nDisplaying final list:\n");

	display_list();		// Function calling to display final list

	printf("\n");
	return 0;

	/* End of program */
}

/* Function definitions */

struct NODE* create_node()      // Function definition to create and return new node
{
    // Creating a new node to add into the list	
	struct NODE *new_node = (struct NODE*)malloc(sizeof(struct NODE));
	
	printf("Input data for the item --> ");
	scanf("%d", &(new_node->info));		// Data input for new node

	new_node->Next = NULL;				// Initializing 'Next' pointer with NULL

	return new_node;		// Returning new node
}

void add_node(struct NODE* new_node)        // Function definition to add new node to the list
{
    if(!start)		// Condition to check if list is empty or not. If list is empty, start is NULL
	{
		start = end = new_node;		// If list is empty, new node is starting node
		
		printf("\n");
		return;
	}

	/* If start is not NULL, list is not empty */

	end->Next = new_node;     // Make last node point to new node
	end = new_node;           // Assign new node to end

	printf("\n");	
	return;
}

void display_list()
{
    if(!start)			// If start is NULL, no node exists. List is empty
	{
		printf("!");	// '!' symbol shows NULL

		printf("\n");
		return;
	}
	
	struct NODE *temp = start;
	
	while(temp)			// Loop to display list
	{
		printf("%d --> ", (temp->info));		// Display the current node
		temp = temp->Next;		// Move to next node
	}

	printf("!");		// '!' symbol shows NULL

	printf("\n");
	return;
}