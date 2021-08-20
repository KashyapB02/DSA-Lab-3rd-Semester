/*
    Program to read two matrixes and add them.
*/

/* Header files */

#include <stdio.h>
#include <stdlib.h>

/* Function declarations */

void GetSize(int *, int *);            //Function to get dimension of matrix from the user
int ValidAddition(int, int, int, int); //Function to check if addition of matrices is possible of not
void GetMatrix(int *, int, int);       //Function to get matrix input from the user
void ShowMatrix(int *, int, int);      //function to display matrix entered by the user
void Addition(int *, int *, int, int); //Function to perform addition operation with input matrices

/* Starting of main() */

int main()
{
    system("cls");
    system("color 06");

    printf("!!...... Addition of Matrices .....!!\n");
    printf("\n");

    int R1, C1, R2, C2; //Variables to store size of matrices

    printf("!!-----> Input dimension of matrices <-----!!\n");
    printf("\n");

    printf("Input dimension of Matrix 1 -->\n");
    printf("\n");

    GetSize(&R1, &C1); //Function calling for user input of dimension of matrix 1

    printf("\n");
    printf("Input dimension of Matrix 2 -->\n");
    printf("\n");

    GetSize(&R2, &C2); //Function calling for user input of dimension of materix 2

    printf("\n");
    if (!(ValidAddition(R1, C1, R2, C2))) //Function calling to check validity of addition of matrices
    {
        printf("\n");
        return 0; //If addition cannot be performed, terminate the program with return statement
    }

    int *Matrix_1 = (int *)calloc((R1 * C1), sizeof(int)); //Memory allocation for matrix 1
    int *Matrix_2 = (int *)calloc((R2 * C2), sizeof(int)); //Memory allocation for matrix 2

    printf("Input Matrix 1 -->\n");
    printf("\n");

    GetMatrix(Matrix_1, R1, C1); //Function calling for user input of matrix 1

    printf("\n");
    printf("Input Matrix 2 -->\n");
    printf("\n");

    GetMatrix(Matrix_2, R2, C2); //Function calling for user input of matrix 2

    printf("\n");
    printf("\n!..... Displaying Matrices .....!");
    printf("\n");

    printf("\n");
    printf("!..... Matrix 1 .....!\n");
    printf("\n");

    ShowMatrix(Matrix_1, R1, C1); //Function calling for displaying matrix 1 entered by the user

    printf("\n");
    printf("!..... Matrix 2 .....!\n");
    printf("\n");

    ShowMatrix(Matrix_2, R2, C2); //Function calling for displaying matrix 2 entered by the user

    printf("\n");
    printf("\nAdding Matrices... ");
    system("pause");

    printf("\n");
    printf("Addition of the matrices is -->\n");
    printf("\n");

    Addition(Matrix_1, Matrix_2, R1, C1); //Function calling to perform addition of entered matrices

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

/* Function definition to check if addition of matrices is possible or not */

int ValidAddition(int R1, int C1, int R2, int C2)
{
    if ((R1 != R2) || (C1 != C2))
    {
        printf("Dimension of matrices are not same... Matrix Addition is not possible...");
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
            printf("%d\t", *(M + (i * C) + j));
        }

        printf("\n");
    }
}

/* Function definition to perform addition operation with input matrices */

void Addition(int *M1, int *M2, int R, int C)
{
    int add;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            add = (*(M1 + (i * C) + j) + *(M2 + (i * C) + j));
            printf("%d\t", add);
        }

        printf("\n");
    }
}