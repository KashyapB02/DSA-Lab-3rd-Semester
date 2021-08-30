/*
    --> Program for creating a new Node and inserting at the beginning of a Singly Linked List.
*/

/* Header files */

#include <stdio.h>
#include <stdlib.h> // Headerfile for 'malloc()' function

/* Structure declaration for Nodes of singly linked list */

struct NODE
{
    int info;          // Variable to store information for the node
    struct NODE *Next; // Pointer variable for pointing to the next node
};

/* Starting of main() */

int main()
{
    system("cls");

    struct NODE *start, *new_node, *previous_node, *display; // Variables declaration to perform creation of a new node and insertion operation at the begining of singly linked list

    start = NULL; // Initialize the start pointer with NULL.

    int total_node; // Variable to store total number of nodes to be inserted to the singly linked list

    printf("Input total number of nodes --> ");
    scanf("%d", &(total_node));

    if (!total_node)
    {
        printf("\nNo node created... No insertion to the list...\n");
        printf("\nDisplaying final list... ");
        system("pause");

        printf("\n");

        if (!start) // If start is NULL, no node exists. List is empty
        {
            printf("List is empty.. Nothing to display...\n");
            printf("Returning...\n");

            printf("\n");
            return 0;
        }

        display = start; // Assign start to display for displaying the list

        while (display) // Loop to display list
        {
            printf("%d --> ", display->info); // Display the current node
            display = display->Next;          // Make display point to next node
        }

        printf("!\n"); // '!' symbol shows end of the list
    }

    printf("\nInitial List -->\n");

    display = start; // Assign start to display for displaying the list

    while (display) // Loop to display initial list
    {
        printf("%d --> ", display->info); // Display current node
        display = display->Next;          // Make display point to next node
    }
    printf("!\n"); // '!' symbol shows end of the list

    printf("\nInput informations for each node:\n");
    printf("\n");

    int information; // Variable to store information input from the user

    for (int i = 1; i <= total_node; i++) // Loop for creating and inserting new nodes in the list
    {
        new_node = (struct NODE *)malloc(sizeof(struct NODE)); // Creating a new node for inserting into list

        if (new_node) // Condition to check if node is created successfully
        {
            printf("NODE %d --> ", i);
            scanf("%d", &(information));

            new_node->info = information; // Putting information in new node
            new_node->Next = NULL;        // Initializing 'Next' pointer with nULL

            if (!(start)) // Condition to check if list is empty or not. If list is empty, start is NULL
            {
                start = new_node; // If list is empty, new_node is starting node
            }
            else // If start is not NULL, list is not empty
            {
                previous_node = start;          // Save previous value of start
                start = new_node;               // Assign new node to start
                new_node->Next = previous_node; // Make new node point to previous start
            }

            printf("\nUpdated list is:\n");

            display = start; // Assign start to display for displaying the list

            while (display) // Loop to display updated list after each insertion
            {
                printf("%d --> ", display->info); // Display current node
                display = display->Next;          // Make display point to next node
            }
            printf("!\n"); // '!' symbol shows end of the list

            printf("\n");
        }
        else
        {
            printf("\nNode cannot be created... Returning... !");
            printf("\n");
            return 0;
        }
    }

    printf("All nodes successfully inserted to list... ");
    system("pause");

    printf("\nDisplaying final list... ");
    system("pause");

    printf("\n");

    if (!start) // If start is NULL, no node exists. List is empty
    {
        printf("List is empty.. Nothing to display...\n");
        printf("Returning...\n");

        printf("\n");
        return 0;
    }

    display = start; // Assign start to display for displaying the list

    while (display) // Loop to display list
    {
        printf("%d --> ", display->info); // Display the current node
        display = display->Next;          // Make display point to next node
    }

    printf("!\n"); // '!' symbol shows end of the list

    printf("\n");
    return 0;
}