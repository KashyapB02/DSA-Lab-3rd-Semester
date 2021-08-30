/*
    --> Program to creat a Singly Linked List and perform deletion from the beginning of the list.
*/

/* Header files */

#include <stdio.h>
#include <stdlib.h> // Headerfile for 'malloc()' function
#include <ctype.h>  // Headerfile for 'toupper()' function

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

    struct NODE *start, *rear, *new_node, *previous_node, *display; // Variables declaration to perform creation of a new node and deletion operation at the beginning of singly linked list

    start = rear = NULL; // Initialize the start and rear pointer with NULL as list is initially empty.

    int total_node; // Variable to store total number of nodes to be inserted to the singly linked list
    char choice;

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

        printf("\nReady for deletion from the beginning of the list... ");
        system("pause");

        if (!start) // If start is NULL, list is empty
        {
            printf("List is empty.. Nothing to delete...\n");
            printf("Returning...\n");

            printf("\n");
            return 0;
        }
        else if (!(start->Next)) // If start points to NULL, only one element in list exists
        {
            printf("Only node in the list is deleted successfully...\n");
            printf("\nList is empty now... Nothing to display...\n");

            printf("\n");
            return 0;
        }

        do // Loop to perform deletioin of nodes from the beginning of the list
        {
            if (!start) // If start is NULL, List is empty
            {
                printf("\nList is empty.. Nothing to delete...\n");
                printf("Returning...\n");

                printf("\n");
                return 0;
            }

            previous_node = start;        // Assign the beginning node from list to Temp
            start = start->Next; // Make start point to the next node from the beginning of the list

            free(previous_node); // Delete Temp, This will delete the node currently at the beginning as Temp stores the node currently at the beginning of the list

            printf("\n1 Node deleted from beginning... \n");
            printf("The list now is:\n");
            printf("\n");

            display = start; // Assign start to display for displaying the list

            while (display) // Loop to display list
            {
                printf("%d --> ", display->info); // Display the current node
                display = display->Next;          // Make display point to next node
            }
            printf("!\n"); // '!' symbol shows end of the list

            printf("\nWant to delete mode node (Y/N):\n"); // Asking user for more deletion
            printf("--> ");
            scanf(" %c", &(choice));

            choice = toupper(choice);
        } while ((choice == 'Y')); // If user's choice is 'Yes', loop will execute one more time

        printf("\nDisplaying final list... ");
        system("pause");

        printf("\n");

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
                start = rear = new_node; // If list is empty, new_node is starting and ending node
            }
            else // If start is not NULL, list is not empty
            {
                rear->Next = new_node; // Make last node point to the new node
                rear = new_node;       // Make new node as rear
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

    printf("\nReady for deletion from the beginning of the list... ");
    system("pause");

    if (!start) // If start is NULL, List is empty
    {
        printf("\nList is empty.. Nothing to delete...\n");
        printf("Returning...\n");

        printf("\n");
        return 0;
    }
    else if (!(start->Next)) // If start points to NULL, only one element in the list exists
    {
        printf("\nOnly node in the list is deleted successfully...\n");
        printf("\nList is empty now... Nothing to display...\n");

        printf("\n");
        return 0;
    }

    do // Loop to perform deletioin of nodes from the beginning of the list
    {
        if (!start) // If start is NULL, List is empty
        {
            printf("\nList is empty.. Nothing to delete...\n");
            printf("Returning...\n");

            printf("\n");
            return 0;
        }

        previous_node = start;        // Assign the beginning node from list to Temp
        start = start->Next; // Make start point to the next node from the beginning of the list

        free(previous_node); // Delete Temp, This will delete the node currently at the beginning as Temp stores the node currently at the beginning of the list

        printf("\n1 Node deleted from beginning... \n");
        printf("The list now is:\n");
        printf("\n");

        display = start; // Assign start to display for displaying the list

        while (display) // Loop to display list
        {
            printf("%d --> ", display->info); // Display the current node
            display = display->Next;          // Make display point to next node
        }
        printf("!\n"); // '!' symbol shows end of the list

        printf("\nWant to delete mode node (Y/N):\n"); // Asking user for more deletion
        printf("--> ");
        scanf(" %c", &(choice));

        choice = toupper(choice);
    } while ((choice == 'Y')); // If user's choice is 'Yes', loop will execute one more time

    printf("\nDisplaying final list... ");
    system("pause");

    printf("\n");

    display = start; // Assign start to display for displaying the list

    if (!start) // If start is NULL, no node exists. List is empty
    {
        printf("List is empty.. Nothing to display...\n");
        printf("Returning...\n");

        printf("\n");
        return 0;
    }

    while (display) // Loop to display list
    {
        printf("%d --> ", display->info); // Display the current node
        display = display->Next;          // Make display point to next node
    }

    printf("!\n"); // '!' symbol shows end of the list

    printf("\n");
    return 0;
}