/*
    --> Program to creat a Singly Linked List and perform deletion from the end of the list.
*/

/* Header files */

#include <stdio.h>
#include <stdlib.h>     // Header file for 'malloc()' function
#include<ctype.h>		// Header file for 'toupper()' function
#include<time.h>

/* Structure declaration for Nodes of singly linked list */

struct NODE
{
    int info;               // Variable to store information for the node
    struct NODE *Next;      // Pointer variable for pointing to the next node
}*start;

/* Function declarations */

void create_dummy_list();           // Function declaration to create a dummy list

struct NODE* create_node();         // Function declaration to create and return new node
void add_node(struct NODE*);        // Function declaration to add new node to the list

void delete_node();                 // Function declaration to delete node from the list
void display_list();                // Function declaration to display list

/* Starting of main() */

int main()
{
    system("cls");

    start = NULL;           // Initialize the start pointer with NULL.
    create_dummy_list();    // Function callings to create the dummy list

    printf("Initial list:\n");
	display_list();			// Function calling to display list

	printf("\n");
	system("pause");

	char choice;
    printf("\n");

    /* Loop for deleting nodes from the list */

    do
	{
		printf("\nPress any key to delete a node from end...");

        fflush(stdin);
        getchar();

        if(!start)      // If start is NULL, List is empty
        {
            printf("\n");
            
            printf("\nList is empty ! No node available for deletion !");
            printf("\nreturning !");

            printf("\n");
            return 0;       // If list is empty, no further deletion. Return
        }

        delete_node();      // Function calling to delete a node from end of the list
        printf("\n");

		printf("The list is now:\n");
		display_list();					// Function calling to display list

		printf("\n");
		printf("\nWant to delete more node from the list? (Y/N) --> ");
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

void create_dummy_list()      // Function definition to create dummy list
{
    srand(time(0));

    /* Loop to create and add 10 dummy nodes to the list */
    for(int i = 0; i < 10; i++)
    {
        add_node(create_node());		// Function callings to create & add new node in the list
    }

    return;
}

struct NODE* create_node()      // Function definition to create and return new node
{
    // Creating a new node to add into the list	
	struct NODE *new_node = (struct NODE*)malloc(sizeof(struct NODE));
    
    new_node->info = ((rand() % 100) + 1);		// Assigning random data for new node
	new_node->Next = NULL;				// Initializing 'Next' pointer with NULL

	return new_node;		// Returning new node
}

void add_node(struct NODE* new_node)        // Function definition to add new node to the list
{
    if(!start)		// Condition to check if list is empty or not. If list is empty, start is NULL
	{
		start = new_node;		// If list is empty, new node is starting node
		return;
	}

	/* If start is not NULL, list is not empty */

	new_node->Next = start;     // Make new node point to previous start
	start = new_node;           // Assign new node to start

	return;
}

void delete_node()        // Function definition to delete node from end of the list
{
	struct NODE *current, *temp;

    if(!start->Next)        // If start is pointing to NULL, There is only one node left
    {
        temp = start;       // Assign start to temp
        start = NULL;       // Make start NULL. This means list is empty now

        free(temp);         // Delete current node

        printf("\n1 node deleted from the end... !");
        printf("\n");

        return;
    }

    current = start;               // Assign the beginning node from list to current
    
    // Loop through the list till the second last element such that current->next is pointing to end    
    while(current->Next->Next) 
    {
        current = current->Next;    // Move to next node
    }

    temp = current->Next;       // Assign end node to temp
    current->Next = NULL;       // Make second last node pointing to NULL. This means second last node is ending node now.

    free(temp);         // Delete last node

    printf("\n1 node deleted from the end... !");
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