/*
    --> Program to determine symmetrical matrix.

        --> A matrix is said to be symmetrical if and only if matrix is equal to its transpose matrix.
        --> That is, if a is a symmetric matrix, then { A = A(transpose) }.
*/

/* Header files */

#include <stdio.h>
#include <stdlib.h> //Header file for calloc() function

/* Function declarations */

void GetSize(int *, int *);       //Function to get dimension of matrix from the user
int Valid(int, int);              //Function to check if input is square matrix or not
void GetMatrix(int *, int, int);  //Function to get matrix input from the user
void ShowMatrix(int *, int, int); //function to display matrix entered by the user
int IsSymmetric(int *, int, int);   //Function to check whether input matrix is symmetric or not

/* Starting of main() */

int main()
{
    system("cls");
    system("color 06");

    printf("!!...... Symmetric Matrix .....!!\n");
    printf("\n");

    int R, C; //Variables to store dimension of matrix

    printf("!!-----> Input dimension of matrix <-----!!\n");
    printf("\n");

    GetSize(&R, &C); //Function calling for user input of dimension of matrix

    printf("\n");
    if (!(Valid(R, C))) //Function calling to check of matrix is square or not
    {
        printf("\n");
        return 0; //If matrix is not a square matrix, terminate the program with return statement
    }

    int *Matrix = (int *)calloc((R * C), sizeof(int)); //Memory allocation for matrix

    printf("Input Matrix -->\n");
    printf("\n");

    GetMatrix(Matrix, R, C); //Function calling for user input of matrix

    printf("\n");
    printf("\n!..... Displaying Matrix .....!");
    printf("\n");

    printf("\n");
    ShowMatrix(Matrix, R, C); //Function calling for displaying matrix entered by the user

    printf("\n");
    printf("\nChecking for symmetric Matrix... ");
    system("pause");

    if (IsSymmetric(Matrix, R, C)) //Function calling to check whether input matrix is symmetric or not
    {
        printf("\n");
        printf("Input matrix is a \"Symmetric Matrix\".");
        printf("\n");

        printf("\n");
        return 0;
    }
    else
    {
        printf("\n");
        printf("Input matrix is NOT a Symmetric Matrix.");
        printf("\n");

        printf("\n");
        return 0;
    }

    /* End of program */
}

/* Function definitions */

/* Function definition to get dimension of matrix from the user */

void GetSize(int *R, int *C)
{
    printf("Input Row    --> : ");
    scanf("%d", R);

    printf("Input Column --> : ");
    scanf("%d", C);
}

/* Function definition to check if square of matrix is possible or not */

int Valid(int R, int C)
{
    if (R != C)
    {
        printf("Invalid dimension... Returning...");
        printf("\n");
        return 0;
    }

    return 1;
}

/* Function definition to get matrix input from user */

void GetMatrix(int *M, int R, int C)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            scanf("%d", (M + (i * C) + j));
        }
    }
}

/* Function definition to display matrix entered by the user */

void ShowMatrix(int *M, int R, int C)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            printf("%d\t", *(M + (i * C) + j));
        }

        printf("\n");
    }
}

/* Function definition to check whether input matrix is symmetric or not */

int IsSymmetric(int *M, int R, int C)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (*(M + (i * C) + j) != *(M + (j * C) + i))
            {
                return 0;
            }
        }
    }

    return 1;
}