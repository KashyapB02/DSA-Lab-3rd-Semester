/*
    Write a program to implement linear search.
*/

/* Header files */

#include<stdio.h>
#include<stdlib.h>

/* Function declaration */

int Linear_Search (int*, int, int);    //Function to implement linear search
void Scan_Array (int*, int);    //Function to take user input to the array
void Print_Array (int*, int);   //Function to display array to the user

/* Starting of main() function */

int main()
{
    system("cls");
    system("color 06");

    int size;

    /* Asking user for size of array to be initialized in memory */

    printf("Input size of array to be initialized --> ");
    scanf("%d", &size);

    int *ptr = (int*) calloc (size, sizeof(int));   //Memeory allocation for size elements of array

    if(ptr == NULL) //To check if memory is allocated or not. in case memmory is not alloacated, 'ptr' is NULL
    {
        printf("\n");
        printf("Error in memory initialization... Returning...\n");

        printf("\n");
        return 0;
    }
    else
    {
        printf("\nMemory initialised for %d elements...", size);
        printf("\n");
    }

    /* Taking inputs from the user (writing to the array) */

    printf("\n");
    printf("Input %d elements:\n", size);
    printf("\n");

    Scan_Array(ptr, size); //Function call to Write(int*, int)

    /* Displaying array entered by the user (Reading from the array) */

    printf("\n");
    printf("Input array is:\n");
    printf("\n");

    Print_Array (ptr, size); //Function call to Read(int*, int)

    printf("\nReady for searching... ");
    system("pause");

    int search;

    /* Asking user for value to be searched */

    printf("\n");
    printf("Input the value to be searched -- > ");
    scanf("%d", &search);

    int index = Linear_Search(ptr, size, search); //Function call to Linear_Search(int*, int, int)

    if(index == -1)  //If input value not found in the array
    {
        printf("\n");
        printf("Value not found in array... Search failed...");
        printf("\nReturning...");

        printf("\n");
        return 0;
    }
    else    //If search is successfull
    {
        printf("\n");
        printf("Search Successfull...\n");
        printf("Element found at index %d, position %d in the array...", index, (index + 1));
        printf("\n");
    }

    /* End of program */

    printf("\n");
    return 0;
}

/* Function declaration for Writing and Reading to the array */

/* Definition of Scan_Array(int, int) funcion to take user input to the array */

void Scan_Array(int *p, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Element [%d] --> ", i);
        scanf("%d", (p + i));
    }
}

/* Definition of Print_Array(int*, int) function to display array to the user */

void Print_Array(int *p, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Element [%d] --> %d\n", i, *(p + i));
    }
}

/* Definition of Linear_Search(int*, int, int) funcion to perform linear search */

int Linear_Search(int *p, int size, int value)
{
    for(int i = 0; i < size; i++)
    {
        if(*(p + i) == value)
        {
            return i;
        }
    }

    return -1;
}