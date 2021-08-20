/*
    --> Program to pass array to a function.
*/

/* Header files */

#include<stdio.h>
#include<stdlib.h>

/* Function declaration for Writing and Reading to the array */

void Read (int*, int);  //Declaration of function for reading from the array
void Write (int*, int); //Declaration of the function for writing to the array

/* Starting of main() */

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

    Write(p, size); //Function call to Write(int*, int)

    /* Displaying array entered by the user (Reading from the array) */

    printf("\n");
    printf("Input array is:\n");
    printf("\n-->\t");

    Read (p, size); //Function call to Read(int*, int)

    /* End of program */

    printf("\n");
    return 0;
}

/* Function definition for Writing and Reading to the array */

void Read (int *p, int size)    //Definition of Read(int*, int) function for reading from the array
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", *(p + i));
    }
}

void Write (int *p, int size)   //Definition of Write(int*, int) funcion for writing to the array
{
    for(int i = 0; i < size; i++)
    {
        scanf("%d", (p + i));
    }
}