/*
    --> Program to sort the elements of an array using Quick sort.
*/

/* Header Files */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>     // Header file for 'INT_MAX'

/* Global Declaration */

int size; // Variable to store size of array

/* Function Declarations */

void ScanArray(int *Array);                    // Function to input array
int Partition(int *Array, int high, int low);  // Function to perform partitioning of array for sorting
void QuickSort(int *Array, int high, int low); // Function to perform Quick sort
void PrintArray(int *Array);                   // Function to print array

/* Start of main() */

int main()
{
    system("cls");

    printf("Input size of array --> ");
    scanf("%d", &size);

    /* Memory allocation for array */
    /* Allocate memory for 1 extra element that will store 'INT_MAX' */

    int *Array = (int *)calloc((size + 1), sizeof(int));

    if (!Array) // Condition to check if memory is allocated or not
    {
        printf("\nError in memory allocation... Returning...");
        printf("\n");

        return 0; // If memory is not allocated, terminate the program
    }

    printf("\nInput %d elements:\n", size);
    printf("\n");

    ScanArray(Array); // Function call to input elements of array

    printf("\n");
    printf("Original array is:\n");

    PrintArray(Array); // Function call to print original input array
    printf("\n");

    printf("\n");
    printf("\nSorting array using Quick sort...");
    system("pause");

    printf("\n");
    QuickSort(Array, size, 0); // Function call to sort array elements using quick sort

    printf("\n");
    printf("\nThe sorted array is as shown below:\n");

    PrintArray(Array); // Function call to print final sorted array
    printf("\n");

    return 0;
}

void ScanArray(int *Array) // Function to input array
{
    // Loop to input elements of array
    for (int i = 0; i < size; i++)
    {
        printf("Element %d\t--> ", (i + 1));
        scanf("%d", (Array + i));
    }

    /* Last element of the array will store the maximum possible value ('INT_MAX') */
    Array[size] = INT_MAX;

    printf("\n");
    return;
}

/* Function to perform partitioning of array for sorting */

/* This function consider lowest index element as pivot, place the pivot at its exact sorted position, and place smaller elements to left of pivot and greater elements to right of pivot*/

int Partition(int *Array, int high, int low)
{
    int pivot = Array[low]; // Select lowest index as pivot element
    int i = low, j = high, swap;

    /* Loop to find sorted position of pivot */
    do
    {

        /* Loop to increment 'i' untill it finds element greater then pivot element */
        do
        {
            i++;
        } while (Array[i] <= pivot);

        /* Loop to decrement 'j' untill it finds element smaller then pivot element */
        do
        {
            j--;
        } while (Array[j] > pivot);

        // Swapping of smaller and larger element
        if (i < j)
        {
            swap = Array[i];
            Array[i] = Array[j];
            Array[j] = swap;
        }
    } while (i < j);

    // Place pivot to it's sorted position by swapping
    swap = Array[low];
    Array[low] = Array[j];
    Array[j] = swap;

    return j; // Return current partitioning index
}

/* Function to perform Quick sort */

void QuickSort(int *Array, int high, int low)
{
    int j;
    static int round = 0; // Static variable to count total round of sorting

    if (low < high)
    {
        j = Partition(Array, high, low); // 'j' is the partitioning index

        /* Printing array after each round of sorting */
        printf("Array after %d round of sorting\t--> ", (++round));
        PrintArray(Array);

        fflush(stdin);
        getchar();

        // Perform quick sort on the left sub-array of partitioning index
        QuickSort(Array, j, low);

        // Perform quick sort on the right sub-array of partitioning index
        QuickSort(Array, high, (j + 1));
    }

    return;
}

void PrintArray(int *Array) // Function to print array
{
    printf("%d", Array[0]);

    // Loop to print elements of array
    for (int i = 1; i < size; i++)
    {
        printf(",  %d", Array[i]);
    }

    return;
}