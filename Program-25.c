/*
    --> Program to creat a dummy Stack using array and traverse it.

        :Create a dummy stack of 10 integers and find out the total occurance of an integer entered by
         user in the stack along with the distances of occurance from the top of the stack.
*/

/* Header files */

#include <stdio.h>
#include <stdlib.h> // For 'calloc()' function
#include <ctype.h>  // For 'toupper()' function
#include <time.h>

/* Global declaration */

int top = -1;              // Variable that store 'top' of the stack
static int occurances = 0; // Static variable to count the total occurance of integer entered by user
const int size = 20;       // constant that stores total size of stack

/* Function declaration */

void create_stack(int *);        // Function to create a dummy stack containing '20' elements
void display(int[]);             // Function to display elements of stack
int *search_element(int[], int); // Function to find out the total occurance of the entered integer

/* Starting of main */

int main()
{
    system("cls");

    int *stack = (int *)calloc(size, sizeof(int)); // Memory allocation for stack

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

    int item; // Variable to store the value entered by the user

    printf("\nInput value to be searched --> "); // Asking user for item to be searched
    scanf("%d", &item);

    int *distances = search_element(stack, item); // Function call to perform searching

    printf("\nTotal occurance of %d --> %d", item, occurances);
    printf("\n");

    printf("\n");
    for (int i = 0; i < occurances; i++) // Loop to display all occurances of entered item
    {
        printf("Occurance %d\t--> Position %d from the top of stack", (i + 1), *(distances + i));
        printf("\n");
    }

    printf("\n");
    return 0;

    /* End of program */
}

/* Function definitions */

/* Function definition to find out the total occurance of the entered integer */

int *search_element(int *S, int item)
{
    int *distances = (int *)calloc(size, sizeof(int)); // Array to store distance of occurances of entered item

    int index = top, i = 0; // Copy 'top' to another variable so that 'top' remains undisturbed

    for (; index >= 0; index--) // Loop to search all occurances of item entered by user
    {
        if (*(S + index) == item)
        {
            occurances++;
            *(distances + i) = ((top - index) + 1);
            i++;
        }
    }

    return distances; // Returning array that stores distances of all occurances, if any
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

    for (; top < size; top++) // Loop to push 20 items to dummy stack
    {
        *(S + top) = ((rand() % 25) + 10); // 'rand()' function is used to generate random numbers
    }

    top--; // Set the 'top' to topmost element of stack
}