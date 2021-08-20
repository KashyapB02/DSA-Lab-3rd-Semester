/*
    Write a program to implement binary search.
*/

/* Header files */

#include <stdio.h>
#include <stdlib.h>

/* Function declarations */

int Binary_Search(int *, int, int); //Function declaration to perform binary search
void Sacn_Array(int *, int);        //Fuction declaration to take user input into the array
void Print_Array(int *, int);       //Function declaration to display array to the user

/* Starting of main() */

int main()
{
    system("cls");
    system("color 06");

    int size;

    /* Asking user for size of array */

    printf("Input size of the array --> ");
    scanf("%d", &size);

    int *ptr = (int *)calloc(size, sizeof(int)); //Allocating memory for 'size' number of array elements

    if (ptr == NULL) //If memory is not allocate, calloc will return a NULL to the 'ptr'
    {
        printf("\nError in memory allocation... Returning...");
        printf("\n");
        return 0;
    }
    else //If memory allocation is successful
    {
        printf("Memory initialized for %d number of elements...", size);
        printf("\n");
    }

    /* Asking user for input in the array */

    printf("\n");
    printf("Input %d integers in \"Ascending Order\" -->\n", size); //Binary search can be appllied only for sorted arrays
    printf("\n");

    Sacn_Array(ptr, size); //Function calling for user input in the array

    printf("\n");
    printf("Entered array is -->\n");
    printf("\n");

    Print_Array(ptr, size); //Function calling to display entered array to the user

    printf("\n");
    printf("Ready for Searching... ");
    system("pause");

    int search;

    /* Asking user for the value to be searched */

    printf("\n");
    printf("Input value to be searched --> ");
    scanf("%d", &search);
    printf("\n");

    int index = Binary_Search(ptr, size, search); //Function calling for binary search in the array

    if (index == -1) //If value not found then Binary_Search will return -1, Search fails
    {
        printf("\n");
        printf("Value not found in the array... Search failed...\n");
        printf("Returning...");

        printf("\n");
        return 0;
    }
    else //If value found in array, Search successful
    {
        printf("\n");
        printf("Search Successful...\n");
        printf("Value found at index %d, position %d in the array...", index, (index + 1));

        printf("\n");
        return 0;
    }

    /* End of program */

    printf("\n");
    return 0;
}

/* Function definitions */

/* Definition of function to perform binray search */

int Binary_Search(int *p, int size, int value)
{
    int start = 0, end = (size - 1), mid;

    for (int i = 0; i < size; i++)
    {
        mid = ((start + end) / 2);

        if (*(p + mid) == value)
        {
            return mid;
        }
        else if (*(p + mid) > value)
        {
            end = (mid - 1);
        }
        else
        {
            start = (mid + 1);
        }
    }

    return -1;
}

/* Definition of function to take user input into the array */

void Sacn_Array(int *p, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Element [%d] --> ", i);
        scanf("%d", (p + i));
    }
}

/* Definition of function to display array entered by the user */

void Print_Array(int *p, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Element [%d] --> %d\n", i, *(p + i));
    }
}