/*
    --> Program to implement the merge sort.
*/

/* Header files */

#include <stdio.h>
#include <malloc.h>

/* Global variables */

int size;				// Variable to store size of actually array input by user
int *reserveArray;		// Pointer variable to store array while merging

/* Function declarations */

void scanArray (int *, int);				// Function to input array
void printArray (int *, int);				// Function to print array

void mergeArray (int *, int, int, int);		// Function to merge two sorted arrays
void mergeSort (int *, int, int);			// Function to perform merge sort

/* Start of main() */

int main () {

	system ("cls");

	/* Asking user to input size of array */
	printf("Input size of array --> ");
	scanf("%d", &size);

	/* Memory allocation for actual array and reserve array */
	int *Array = (int *)malloc(size * sizeof(int));
	reserveArray = (int *)malloc(size * sizeof(int));

	/* Elements input for the array by the user */
	printf("\nInput %d elements:\n", size);
	printf("\n");

	scanArray (Array, size);	// Function call to input elements of array
	printf("\n");

	/* Display array before sorting */
	printf("Array before sorting -->  ");
	printArray (Array, size);				// Function call to print original array

	printf("\n");
	printf("\nCalling merge sort... ");
	system("pause");

	/* Variables to track lowest and highest index of the array */
	int low = 0, high = (size - 1);
	mergeSort (Array, low, high);	// Function call to sort array elements using merge sort

	printf("\n");
	printf("Array after sorting  -->  ");

	printArray (Array, size);	// Function call to print final sorted array
	printf("\n");

	printf("\n");
	return 0;
}

/* End of main() */

/* Function definitions */

// Function to input array
void scanArray (int *Array, int size) {

	// Loop to input array elemets
	for(int i = 0; i < size; i++) {

		printf("Element %d --> ", (i + 1));
		scanf("%d", &Array[i]);
	}
}

// Function to print array
void printArray (int *Array, int size) {

	// Loop to print all array elements
	for(int i = 0; i < size; i++) {

		printf("%d  ", Array[i]);
	}
}

// Function to merge two sorted arrays
void mergeArray (int *Array, int low, int mid, int high) {

	int i = low, j = (mid + 1), k = low;

	// Merge arrays untill one of the arrays get exhausted
	while ((i <= mid) && (j <= high)) {

		if (Array[i] <= Array[j]) {

			reserveArray[k++] = Array[i++];
		} else {

			reserveArray[k++] = Array[j++];
		}
	}

	// Append elements of unexahusted array at the last of merged array

	while (i <= mid) {

		reserveArray[k++] = Array[i++];
	}

	while (j <= high) {

		reserveArray[k++] = Array[j++];
	}

	// Store sorted array into reserve array
	for(k = low; k <= high; k++) {

		Array[k] = reserveArray[k];
	}
}

// Funtion to perform merge sort
void mergeSort (int *Array, int low, int high) {

	int mid = ((low + high) / 2);	// Calculate mid of the array

	// Section to implement merge sort
	if (low < high) {

		mergeSort (Array, low, mid);			// Sort first half of the array
		mergeSort (Array, (mid + 1), high);		// Sort second half of the array

		mergeArray (Array, low, mid, high);		// Merge both sorted array
	}
}