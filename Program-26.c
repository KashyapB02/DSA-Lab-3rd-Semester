/*
    --> Program to create doubly linked list.
*/

/* Header files */

#include<stdio.h>
#include<stdlib.h>		// Header file for 'malloc()' function
#include<ctype.h>		// Header file for 'toupper()' function

/* Structure declaration for items of doubly linked list */

struct list_item
{
	int data;						// Variable to store data for the item
	struct list_item *next;			// Pointer variable for pointing to the next item
	struct list_item *previous;		// Pointer variable for pointing to the previous item
}*start, *end;

/* Function declarations */

struct list_item* create_item();			// Function declaration to create and return new list item
void create_list(struct list_item*);		// Function declaration to add new itme in the list
void display_list();						// Function declaration to display list

/* Starting of main() */

int main()
{
	system("cls");

	start = end = NULL;		// Initialize the start & end pointer with NULL.

	printf("Initial list:\n");
	display_list();			// Function calling to display list

	printf("\n");
	printf("Creating list... ");
	system("pause");

	char choice;

	/* Loop for creating and inserting new items in the list */
	
	do
	{
		printf("\nCreate node:\n");
		printf("\n");

		create_list(create_item());		// Function callings to create & add new itme in the list
		printf("\n");

		printf("The list is now:\n");
		display_list();					// Function calling to display list

		printf("\n");
		printf("\nWant to insert more item to the list? (Y/N) --> ");		// Asking user for creating more item
		scanf(" %c", &choice);

		choice = toupper(choice);
		printf("\n");

	} while (choice == 'Y');	// Checking choice of user
	
	printf("\n");
	printf("\nDisplaying final list:\n");

	display_list();		// Function calling to display list

	printf("\n");
	return 0;

	/* End of program */
}

/* Function definitions */

struct list_item* create_item()		// Function definition to create and return new list item
{
	// Creating a new item to add into list	
	struct list_item *item = (struct list_item*)malloc(sizeof(struct list_item));
	
	printf("Input data for the item --> ");
	scanf("%d", &(item->data));		// Data input for new item

	item->next = NULL;				// Initializing 'next' pointer with NULL
	item->previous = NULL;			// Initializing 'previous' pointer with NULL

	return item;		// Returning new item
}

void create_list(struct list_item* item)		// Function definition to add new item in the list
{
	if(!start)		// Condition to check if list is empty or not. If list is empty, start is NULL
	{
		start = end = item;		// If list is empty, new item is starting and ending item
		
		printf("\n");
		return;
	}

	/* If start is not NULL, list is not empty */

	end->next = item;		// Make last item point to new item
	item->previous = end;	// Make new item point to previous item (property of doubly linked list)
	end = item;				// Make new item as end item

	printf("\n");	
	return;
}

void display_list()		// Function definition to display list
{
	if(!start)			// If start is NULL, no item exists. List is empty
	{
		printf("!");	// '!' symbol shows NULL

		printf("\n");
		return;
	}
	
	struct list_item *temp = start;

	printf("! ");		// '!' symbol shows NULL
	
	while(temp)			// Loop to display list
	{
		printf("<-- %d -->", (temp->data));		// Display the current item
		temp = temp->next;		// Move to next item
	}

	printf(" !");		// '!' symbol shows NULL

	printf("\n");
	return;
}