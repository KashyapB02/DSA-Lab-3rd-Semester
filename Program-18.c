/*
    --> Program to understand Saprse Array. Program includes:

        --> Creating a sparse array.
        --> Displaying a sparse array.
        --> Adding two sparse matrices.
        --> Subtracting two sparse matrices.
*/

/* Header files */

#include <stdio.h>
#include <stdlib.h>  // Header file for calloc() function
#include <windows.h> // Header file for function system("cls")

/* Structure declaration for storing non-zero elements of a sparse matrix */

struct Element
{
    int i; // Variable to store row number of non-zero element
    int j; // Variable to store column number of non-zero element
    int x; // Variable to store non-zero element itself
};

/* Structure declaration for sparse matrix */

struct Sparse
{
    int m;        // Variable to store total row of sparse matrix
    int n;        // Vriable to store total column of sparse matrix
    int non_zero; // Variable to store total number of non-zero elements in the sparse matrix

    struct Element *E; // Pointer varibale of structure Element to store all the non-zero elemets of the sparse matrixs
};

/* Function declarations */

void Create(struct Sparse *);                             // Function to create a new sparse array
void Display(struct Sparse);                              // Function to display a sparse array
struct Sparse *Addition(struct Sparse, struct Sparse);    // Function to add two sparse matrices
struct Sparse *Subtraction(struct Sparse, struct Sparse); // Function to subtract two sparse matrices

/* Starting of main() */

int main()
{
    system("cls");

    struct Sparse *S; // Pointer variable of structure Sparse to dynamically create objects to store sparse matrices.

    S = (struct Sparse *)calloc(2, sizeof(struct Sparse)); // Allocation of memory dynamically for two objects of structure Sparse to store two matrices

    if (!S) // If object cannot created, then S == NULL
    {
        printf("Error in creating object... Returning...\n");
        printf("\n");
        return 0; // If objcet cannot created, terminate the program
    }

    printf("!-----> SPARSE MATRIX 1 <-----!\n");
    printf("\n");

    Create(S); // Function call to create sparse matrix 1
    printf("\n");

    printf("!-----> SPARSE MATRIX 2 <-----!\n");
    printf("\n");

    Create((S + 1)); // Function call to create sparse matrix 2
    printf("\n");

    system("cls");

    printf("!-----> SPARSE MATRIX 1 <-----!\n");
    printf("\n");

    Display(*(S)); // Function call to display sparse matrix 1, Sending matrix 1 by value by dereferencing pointer object S[0]

    printf("\n");

    printf("!-----> SPARSE MATRIX 2 <-----!\n");
    printf("\n");

    Display(*(S + 1)); // Function call to display sparse matrix 2, Sending matrix 2 by value by dereferencing pointer object S[1]

    printf("\n");

    struct Sparse *Sum, *Difference; // Pointer variable of structure Sparse to store resulting matrix after addition and subtraction respectively of sparse matrices

    Sum = Addition(*(S), *(S + 1)); // Function call to performe addition of two sparse matrices. Resulting matrix is stored by pointer variable, Sum

    Difference = Subtraction(*(S), *(S + 1)); // Function call to performe subtraction of two sparse matrices. Resulting matrix is stored by pointer variable, Difference

    if (!Sum) // If addition cannot be performed, then Sum == NULL
    {
        printf("Dimension of matrices are not same... Addition cannot be performed...\n");
        printf("Returning...\n");

        printf("\n");
        return 0; // If addition cannot be performed, terminate the program
    }

    /* (If addition cannot be performed, then subtraction can also not be performed. SO no need to check condition for Difference == NULL) */

    printf("!-----> ADDITION OF SPARSE MATRICES <-----!\n");
    printf("\n");

    Display(*Sum); // Function call to display the resulting matrix after addition. Sending resulting matrix stored by pointer variable Sum by value by dereferencing pointer object Sum

    printf("\n");

    printf("!-----> SUBTRACTION OF SPARSE MATRICES <-----!\n");
    printf("\n");

    Display(*Difference); // Function call to display the resulting matrix after subtraction. Sending resulting matrix stored by pointer variable Difference by value by dereferencing pointer object Difference

    printf("\n");

    /* End of Program */

    printf("\n");
    return 0;
}

/* Function definitions */

void Create(struct Sparse *S)   // Function definition to create a new sparse array
{
    printf("Input dimensions of matrix:\n");
    printf("\n");

    printf("--> ");
    scanf("%d", &(S->m));
    printf("--> ");
    scanf("%d", &(S->n));

    printf("\n");
    printf("Input total non-zero elements --> ");
    scanf("%d", &(S->non_zero));

    S->E = (struct Element *)calloc((S->non_zero), sizeof(struct Element)); // Allocation of memeory for non-zero elements of sparse matrix

    printf("\n");
    printf("Input non-zero elements:\n");
    printf("\n");

    for (int i = 0; i < (S->non_zero); i++) // Loop to input non-zero elements of sparse array
    {
        printf("Non-zero element %d:\n", (i + 1));
        printf("\n");

        printf("Row --> ");
        scanf("%d", &(S->E[i].i));
        printf("Col --> ");
        scanf("%d", &(S->E[i].j));
        printf("Ele --> ");
        scanf("%d", &(S->E[i].x));

        printf("\n");
    }

    printf("Matrix entered successfully !\n");

    return;
}

void Display(struct Sparse S)   // Function definition to display a sparse array
{
    int k = 0;

    for (int i = 0; i < (S.m); i++) // Loop to display sparse matrix
    {
        for (int j = 0; j < (S.n); j++)
        {
            if ((i == (S.E[k].i)) && (j == (S.E[k].j))) // Condition to check if the element present at index (i, j) in sparse matrix is non-zero or not. If the element is non non-zero, print the element, otherwise print '0'
            {
                if ((S.E[k].x) < 0)
                {
                    printf("\b%d\t", S.E[k++].x);   // Formatting output using escape sequence '\b'
                }
                else
                {
                    printf("%d\t", S.E[k++].x);
                }
            }
            else
            {
                printf("0\t");
            }
        }

        printf("\n");
    }

    return;
}

struct Sparse *Addition(struct Sparse S1, struct Sparse S2) // Function definition to add two sparse matrices
{
    if ((S1.m != S2.m) || (S1.n != S2.n))   // Checking if the dimension of sparse matrices are same or not. If the dimensions of sparse matrices are not same, matrices cannot be added
    {
        return NULL;
    }

    struct Sparse *Add; // Pointer variable of structure Sparse to store result of addition of sparse matrices

    Add = (struct Sparse *)calloc(1, sizeof(struct Sparse));    // Allocation of memory for the pointer variable of structure Sparse

    Add->E = (struct Element *)calloc((S1.non_zero + S2.non_zero), sizeof(struct Element)); // Allocation of memory to store the addition of non-zero elements

    int l = 0, m = 0, n = 0;

    while ((l < S1.non_zero) && (m < S2.non_zero))   // Loop to calculate sum of non-zero elements
    {        
        if ((S1.E[l].i) < (S2.E[m].i))
        {
            Add->E[n++] = S1.E[l++];
        }
        else if ((S1.E[l].i) > (S2.E[m].i))
        {
            Add->E[n++] = S2.E[m++];
        }
        else
        {
            if ((S1.E[l].j) < (S2.E[m].j))
            {
                Add->E[n++] = S1.E[l++];
            }
            else if ((S1.E[l].j) > (S2.E[m].j))
            {
                Add->E[n++] = S2.E[m++];
            }
            else
            {
                Add->E[n] = S1.E[l++];
                Add->E[n++].x += (S2.E[m++].x);
            }
        }
    }

    while (l < (S1.non_zero))   // If total non-zero elements of sparse matrix 1 is more then sparse matrix 2, the simply copy the elements to the resulting sparse matrix
    {
        Add->E[n++] = S1.E[l++];
    }

    while (m < (S2.non_zero))   // If total non-zero elements of sparse matrix 2 is more then sparse matrix 1, the simply copy the elements to the resulting sparse matrix
    {
        Add->E[n++] = S2.E[m++];
    }

    /* Allocating dimensions and total non-zero elements for the resulting sparse matrix after addition */

    Add->m = S1.m;
    Add->n = S1.n;
    Add->non_zero = n;

    return Add; // Returning resulting matrix after addition to the main()
}

struct Sparse *Subtraction(struct Sparse S1, struct Sparse S2)  // Function definition to subtract two sparse matrices
{
    if ((S1.m != S2.m) || (S1.n != S2.n))   // Checking if the dimension of sparse matrices are same or not. If the dimensions of sparse matrices are not same, matrices cannot be subtracted
    {
        return NULL;
    }

    struct Sparse *Subtract;    // Pointer variable of structure Sparse to store result of subtraction of sparse matrices

    Subtract = (struct Sparse *)calloc(1, sizeof(struct Sparse));   // Allocation of memory for the pointer variable of structure Sparse

    /* Allocation of memory to store the subtraction of non-zero elements */
    Subtract->E = (struct Element *)calloc((S1.non_zero + S2.non_zero), sizeof(struct Element));

    int l = 0, m = 0, n = 0;

    while ((l < S1.non_zero) && (m < S2.non_zero))  // Loop to calculate difference of non-zero elements
    {
        if ((S1.E[l].i) < (S2.E[m].i))
        {
            Subtract->E[n++] = S1.E[l++];
        }
        else if ((S1.E[l].i) > (S2.E[m].i))
        {
            Subtract->E[n] = S2.E[m++];
            Subtract->E[n++].x *= (-1);
        }
        else
        {
            if ((S1.E[l].j) < (S2.E[m].j))
            {
                Subtract->E[n++] = S1.E[l++];
            }
            else if ((S1.E[l].j) > (S2.E[m].j))
            {
                Subtract->E[n] = S2.E[m++];
                Subtract->E[n++].x *= (-1);
            }
            else
            {
                Subtract->E[n] = S1.E[l++];
                Subtract->E[n++].x -= (S2.E[m++].x);
            }
        }
    }

    while (l < (S1.non_zero))   // If total non-zero elements of sparse matrix 1 is more then sparse matrix 2, the simply copy the elements to the resulting sparse matrix
    {
        Subtract->E[n++] = S1.E[l++];
    }

    while (m < (S2.non_zero))   // If total non-zero elements of sparse matrix 2 is more then sparse matrix 1, the simply copy the elements to the resulting sparse matrix
    {
        Subtract->E[n] = S2.E[m++];
        Subtract->E[n++].x *= (-1);
    }

    /* Allocating dimensions and total non-zero elements for the resulting sparse matrix after subtraction */

    Subtract->m = S1.m;
    Subtract->n = S1.n;
    Subtract->non_zero = n;

    return Subtract;    // Returning resulting matrix after subtraction to the main()
}