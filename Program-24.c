/*
    --> Program to creat a dummy Stack using array and perform Pop operation to it.
*/

/* Header files */

#include <stdio.h>
#include <stdlib.h> // For 'calloc()' function
#include <ctype.h>  // For 'toupper()' function
#include <time.h>

/* Global declaration */

int top = -1; // Variable that store 'top' of the stack

/* Function declaration */

void pop(int *);          // Function to perform pop operation from the stack
void display(int[]);      // Function to display elements of stack
void create_stack(int *); // Function to create a dummy stack containing '20' elements

/* Starting of main */

int main()
{
    system("cls");

    int *stack = (int *)calloc(20, sizeof(int)); // Memory allocation for stack

    if (!stack) // Condition to check whether memory is successfully allocated for stack or not
    {
        printf("Error in stack creation... Returning...");
        printf("\n");

        printf("\n");
        return 0; // If memory is not allocated, terminate the program
    }

    create_stack(stack); // Function call to create the dummy stack

    printf("Stack created successfully... !\n");
    printf("\n");

    display(stack); // Function call to display the dummy stack created

    char choice = 'Y';

    while (choice == 'Y') // Loop to pop item one by one from the stack
    {
        printf("\n");
        printf("Want to pop element from stack? (Y / N) --> "); // Asking user for his choice for popping
        scanf(" %c", &choice);

        choice = toupper(choice);

        if (choice == 'Y') // Condition to check user's choice
        {
            if (top == -1) // If stack is empty, no further pop can be performed
            {
                printf("\nStack UNDERFLOW ! Returning !");
                printf("\n");

                printf("\n");
                return 0; // If stack is empty, terminate the program
            }

            pop(stack); // Function call to perform pop operation

            printf("\nOne item popped from stack !\n");
            ;
            printf("\n");

            printf("Now, the stack is:\n");
            printf("\n");

            display(stack); // Function call to display stack after each pop
        }
        else
        {
            printf("\nFinal stack is:\n");
            printf("\n");

            display(stack); // Function call to display final stack
            printf("\n");

            printf("\n");
            return 0;
        }
    }

    /* End of program */
}

/* Function definitions */

void pop(int *S) // Function definition to perform pop operation to stack
{
    top--;
}

void display(int S[]) // Function definition to display elements of stack
{
    if (top == -1) // If stack is underflow, show nothing and return
    {
        return;
    }

    int index = top; // Copy 'top' to another variable so that 'top' remains undisturbed

    printf("%d\t<--", S[index]); // Displaying topmost element in the stack
    printf("\n");

    index--;

    for (; index >= 0; index--) // Loop to display rest elements in the stack
    {
        printf("%d\n", S[index]);
    }
}

void create_stack(int *S) // Function definition to create the dummy stack
{
    top++;          // Update 'top' by 1
    srand(time(0)); // Function to set seed for 'rand()' function

    for (; top < 20; top++) // Loop to push 20 items to dummy stack
    {
        *(S + top) = ((rand() % 90) + 10); // 'rand()' function is used to generate random numbers
    }

    top--; // Set the 'top' to topmost element of stack
}