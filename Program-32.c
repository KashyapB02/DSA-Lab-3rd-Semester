/*
    --> Program to sort the elements of an array using Selection sort.
*/

/* Header Files */

#include <stdio.h>
#include <stdlib.h>

/* Function Declarations */

void SelectionSort(int *, int); // Function to perform selction Sort
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
    SelectionSort(Array, size); // Function call to sort array elements using selction sort

    printf("\n");
    printf("The sorted array is as shown below:\n");

    PrintArray(Array, size); // Function call to print final sorted array

    printf("\n");
    return 0;

    /* End of program */
}

/* Function definitions */

void SelectionSort(int *Array, int size) // Function to perform selction sort
{
    int small, position, swap;

    // Outer loop to iterate all elements of array
    for (int i = 0; i < (size - 1); i++)
    {
        small = Array[i]; // Assuming current element as smallest element
        position = i;     // Storing position of current smallest element

        // Inner loop to iterate all the elements & compare with current smallest element.
        for (int j = (i + 1); j < size; j++)
        {
            // Comparing current element with smallest element
            if (Array[j] < small)
            {
                small = Array[j]; // If current element is smaller, assign current element to 'small'
                position = j;     // Storing position of current smallest element
            }
        }

        // Swapping current element with the smallest element in unsorted array
        swap = Array[i];
        Array[i] = Array[position];
        Array[position] = swap;

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