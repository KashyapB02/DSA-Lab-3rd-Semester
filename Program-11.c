/*
    --> Program to display square of a matrix.
*/

/* Header files */

#include <stdio.h>
#include <stdlib.h> //Header file for calloc() function

/* Function declarations */

void GetSize(int *, int *);       //Function to get dimension of matrix from the user
int Valid(int, int);              //Function to check if square of matrix is possible of not
void GetMatrix(int *, int, int);  //Function to get matrix input from the user
void ShowMatrix(int *, int, int); //function to display matrix entered by the user
int *Square(int *, int, int);     //Function to square input matrix

/* Starting of main() */

int main()
{
    system("cls");
    system("color 06");

    printf("!!...... Square of Matrix .....!!\n");
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
    printf("\nSquaring Matrix... ");
    system("pause");

    int *Result = Square(Matrix, R, C); //Function calling to square entered matrix

    printf("\n");
    printf("Square of the matrix is -->\n");
    printf("\n");

    ShowMatrix(Result, R, C); //Function calling to display square of input matrix

    /* End of program */

    printf("\n");
    return 0;
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
        printf("Invalid dimension... Matrix cannot be squared...");
        printf("\nReturning...");

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
            printf("%3d\t", *(M + (i * C) + j));
        }

        printf("\n");
    }
}

/* Function definition to square the input matrix */

int *Square(int *M, int R, int C)
{
    int *S = (int *)calloc((R * C), sizeof(int));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            *(S + (i * C) + j) = 0;

            for (int k = 0; k < C; k++)
            {
                *(S + (i * C) + j) += ((*(M + (i * C) + k)) * (*(M + (k * C) + j)));
            }
        }
    }

    return S;
}