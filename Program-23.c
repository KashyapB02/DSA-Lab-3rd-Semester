/*
    --> Program to creat a Stack using array and perform Push operation to it.
*/

/* Header files */

#include <stdio.h>
#include <stdlib.h> // For 'calloc()' function
#include <ctype.h>  // For 'toupper()' function

/* Global declaration */

int top = -1; // Variable that store 'top' of the stack

/* Function declaration */

void push(int *, int); // Function to perform push operation to the stack
void display(int[]);   // Function to display elements of stack

/* Starting of main */

int main()
{
    system("cls");

    int size; // Variable to input max size of stack from the user

    printf("Input maximum size of stack --> ");
    scanf("%d", &size);

    int *stack = (int *)calloc(size, sizeof(int)); // Memory allocation for stack

    if (!stack) // Condition to check whether memory is successfully allocated for stack or not
    {
        printf("\nError in stack creation... Returning...");
        printf("\n");

        printf("\n");
        return 0; // If memory is not allocated, terminate the program
    }

    printf("\nStack created successfully... !");
    printf("\n");

    int item; // Variable to input item to be pushed from the user

    char choice;

    do // Loop to push items to the stack one by one
    {
        printf("\nInput item to be pushed --> ");
        scanf("%d", &item);

        if (top == (size - 1)) // Condition to check if stack is full
        {
            printf("\nStack OVERFLOW !"); // If stack is full, then no further item can be pushed
            printf("\n");

            printf("\nFinal stack is:\n");
            printf("\n");

            display(stack); // Displaying final stack by calling the function 'display()'
            printf("\n");

            printf("\n");
            return 0; // If stack is full, terminate the program
        }

        push(stack, item); // Function calling to push the item to stack

        printf("\nStack is now:\n");
        printf("\n");

        display(stack); // Displaying stack after each pushing by calling the function 'display()'
        printf("\n");

        printf("Want to push more item? (Y / N) --> "); // Asking user for further pushing
        scanf(" %c", &choice);

        choice = toupper(choice);
    } while ((choice == 'Y')); // Checking choice of user

    printf("\nFinal stack is:\n");
    printf("\n");

    display(stack); // Displaying final stack before termination of program
    printf("\n");

    printf("\n");
    return 0;

    /* End of program */
}

/* Function definitions */

void push(int *S, int value) // Function definition to perform push operation to stack
{
    top++;              // Update 'top' by 1
    *(S + top) = value; // Push value at the top of stack
}

void display(int S[]) // Function definition to display elements of stack
{
    int index = top; // Copy 'top' to another variable so that 'top' remains undisturbed

    printf("%d\t<--", S[index]); // Displaying topmost element in the stack
    printf("\n");

    index--;

    for (; index >= 0; index--) // Loop to display rest elements in the stack
    {
        printf("%d\n", S[index]);
    }
}