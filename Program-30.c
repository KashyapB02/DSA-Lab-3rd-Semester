/*
    --> Program to sort the elements of an array using Insertion sort.
*/

/* Header Files */

#include <stdio.h>
#include <stdlib.h>

/* Function Declarations */

void InsertionSort(int *, int); // Function to perform Insertion Sort
void PrintArray(int *, int);    // Function to print array
void ScanArray(int *, int);     // Function to input array

/* Start of main() */

int main()
{
    system("cls");

    int size; // Variable to store size of array

    printf("Input size of array --> ");
    scanf("%d", &size);

    int *Array = (int *)calloc(size, sizeof(int)); // Memory allocation for array
    printf("\n");

    if (!Array) // Condition to check if memory is allocated or not
    {
        printf("Error in memory allocation... Returning...");
        printf("\n");

        return 0; // If memory is not allocated, terminate the program
    }

    printf("Input %d elements:\n", size);
    printf("\n");

    ScanArray(Array, size); // Function call to input elements of array
    printf("\n");

    printf("Sorting array in ascending order...");
    system("pause");

    printf("\n");
    InsertionSort(Array, size); // Function call to sort array elements using insertion sort

    printf("\n");
    printf("The sorted array is as shown below:\n");

    PrintArray(Array, size); // Function call to print final sorted array

    printf("\n");
    return 0;

    /* End of program */
}

/* Function definitions */

void InsertionSort(int *Array, int size) // Function to perform insertion sort
{
    int Key, j;

    // Outer loop to iterate all elements of array
    for (int i = 0; i < size; i++)
    {
        Key = Array[i]; // Assigning current element to key
        j = (i - 1);

        // Loop to iterate through previosly sorted subarray & find proper index for insertion of current key
        while ((Key < Array[j]) && (j >= 0))
        {
            Array[j + 1] = Array[j]; // Moves current element forward
            j--;
        }

        Array[j + 1] = Key; // Inserting the current key at it's proper position

        /* Printing array after each iteration of comparision */

        printf("After iteration %d, array is\t--> ", (i + 1));
        PrintArray(Array, size); // Function call to print array

        fflush(stdin);
        getchar();
    }

    return;
}

void PrintArray(int *Array, int size) // Function to print array
{
    printf("%d", Array[0]);

    //Loop to print elements of array
    for (int i = 1; i < size; i++)
    {
        printf(",  %d", Array[i]);
    }

    return;
}

void ScanArray(int *Array, int size) // Function to input array
{
    //Loop to input elements of array
    for (int i = 0; i < size; i++)
    {
        printf("Element %d\t--> ", (i + 1));
        scanf("%d", (Array + i));
    }

    printf("\n");
    return;
}