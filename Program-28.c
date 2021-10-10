/*
    --> Program to implement linear queue using array.
*/

/* Header files */

#include<stdio.h>
#include<stdlib.h>          // Header file for 'malloc()' function
#include<ctype.h>           // Header file for 'toupper()' function

/* Global declaration */

int front, last;            // Variable to store 'front' & 'last' position of the queue

/* Function declaration */

void Add_To_Queue(int, int *);      // Function to add item to the queue
void Delete_From_Queue(int *);      // Function to delete item from the queue
void Display_Queue(int *);          // Function to display queue

/* Starting of main */

int main()
{
    system("cls");

    front = last = -1;      // Initialisation of front & last of the queue

    int size;               // Variable to store size of queue

    printf("Input size of queue --> ");
    scanf("%d", &size);

    int *queue = (int *)malloc(size * sizeof(int));     // Memory allocation for queue

    if (!queue)         // Condition to check whether memory is successfully allocated for queue or not
    {
        printf("\nError in queue creation... Returning...");
        printf("\n");

        printf("\n");
        return 0;       // If memory is not allocated, terminate the program
    }

    printf("\nQueue created successfully... !");
    printf("\n");

    printf("\nInitial queue:\n");
    Display_Queue(queue);

    printf("\n");

    int item;           // Variables to input item to be added to the queue
    
    int ans;
    char choice;

    /* Loop to implement addition and deletion to the queue */

    do
    {
        printf("Queue Operations Available:\n");
        printf("\n");

        printf("1. Add to Queue\n");
        printf("2. Delete from Queue\n");
        printf("3. Display Queue\n");

        printf("\n--> ");
        scanf("%d", &ans);

        printf("\n");

        switch (ans)
        {
            case 1:
            {
                if(last == (size - 1))      // Condition to check if queue is full
                {
                    printf("\nQueue Overflow ! No Space for New Item\n");
                    
                    printf("\n");
                    break;
                }
                
                printf("Input data to be added --> ");
                scanf("%d", &item);

                printf("\n");
                Add_To_Queue(item, queue);      // Function calling to add item to queue

                printf("Now, the queue is:\n");
                
                printf("\n");
                Display_Queue(queue);           // Function calling to display queue

                break;
            }

            case 2:
            {
                if(front == -1)     // Condition to check if queue is empty
                {
                    printf("Queue Undeflow ! No Item Available for Deletion !\n");
        
                    printf("\n");
                    break;
                }
                
                Delete_From_Queue(queue);       // Function calling to delete item from queue

                printf("Now, the queue is:\n");

                Display_Queue(queue);       // Function calling to display queue
                break;
            }

            case 3:
            {
                printf("Queue is:\n");

                Display_Queue(queue);       // Function calling to display queue
                break;
            }
        
            default:
            {
                printf("\nInvalid Input !\n");
                
                printf("\n");
                break;
            }
        }

        // Asking user for further pushing

        printf("Want to perform more operations? (Y/N) --> ");
        scanf(" %c", &choice);

        choice = toupper(choice);
        printf("\n");

    } while (choice == 'Y');

    printf("\n");
    printf("Final Queue is:\n");

    Display_Queue(queue);       // Function calling to display final queue

    printf("\n");
    return 0;

    /* End of program */
}

/* Function definitions */

void Add_To_Queue(int item, int *queue)     // Function definition to add item to the queue
{
    if(front == -1)     // Condition to check if queue is empty
    {
        front = last = 0;
        queue[last] = item;     // If queue is empty, current item is both front and last

        return;
    }

    // If queue is not empty, current item is last item (Item is added to the last of the queue)
    queue[++last] = item;

    printf("\n");
    return;
}

void Delete_From_Queue(int *queue)          // Function definition to delete item from the queue
{
    if(front == last)   // Condition to check if there is only one element in queue
    {
        // If there is only one item, queue will be empty after deletion
        front = last = -1;

        printf("\n");
        return;
    }

    /* Loop to perform deletion from a non-empty queue */
    
    for(int i = front; i < last; i++)
    {
        queue[i] = queue[i + 1];
    }

    last--;     // Update position of last

    printf("\n");
    return;
}

void Display_Queue(int *queue)              // Function definition to display the queue
{
    if(front == -1)     // Condition to check if queue is empty
    {
        printf("-->\n");

        printf("\n");
        return;
    }

    printf("-->\t");

    /* Loop to print all items in the queue */

    for(int i = front; i <= last; i++)
    {
        printf("%d\n", queue[i]);
        printf("\t");
    }

    printf("\n");
    return;
}