/*
    --> Program to traverse an array
*/

/* Header files */

#include<stdio.h>
#include<stdlib.h>

/* Function declaration for Writing and Reading to the array */

void Traverse (int*, int);  //Declaration of function for traversing the array

/* Starting of main */

int main()
{
    system("cls");
    system("color 06");

    int size;

    /* Asking user for total size of array */
    
    printf("Enter size of array to be initialised --> ");
    scanf("%d", &size);

    int *p = (int*) calloc (size, sizeof(int)); //Memory allocation for 'size' elements of array

    if(p == NULL)   //To check if memory is allocated or not. in case memmory is not alloacated, p is NULL
    {
        printf("\nError in creating Memory.. ! Returning... !");
        return 0;
    }
    else
    {
        printf("Memory initialised for %d elements...\n", size);
        printf("\n");
    }

    /* Taking inputs from the user (writing to the array) */

    printf("\n");
    printf("Input %d elements:\n", size);
    printf("\n-->\t");

    for(int i = 0; i < size; i++)
    {
        scanf("%d", (p + i));
    }

    /* Displaying array entered by the user (Reading from the array) */

    printf("\n");
    printf("Traversing the array:\n");
    printf("\n");

    Traverse (p, size); //Function call to Traverse(int*, int)
    printf("\n");

    printf("\n");
    return 0;
}

/* Function declaration for Writing and Reading to the array */

void Traverse (int *p, int size)    //Definition of Traverse(int*, int) function for traversing the array
{
    for (int i = 0; i < size; i++)
    {
        printf("Element %d --> %d\n", (i + 1), *(p + i));
    }
}