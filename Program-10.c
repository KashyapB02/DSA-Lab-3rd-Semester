/*
    Program to perform multiplication on two matrix.
*/

/* Header files */

#include <stdio.h>
#include <stdlib.h>

/* Function declarations */

void GetSize(int *, int *);                       //Function to get dimension of matrix from the user
int Validation(int, int);                         //Function to check if multiplication of matrices is possible of not
void GetMatrix(int *, int, int);                  //Function to get matrix input from the user
void ShowMatrix(int *, int, int);                 //function to display matrix entered by the user
int *Multiplication(int *, int *, int, int, int); //Function to perform multiplicationtion operation with input matrices

/* Starting of main() */

int main()
{
    system("cls");
    system("color 06");

    printf("!!...... Multiplication of Matrices .....!!\n");
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
    if (!(Validation(C1, R2))) //Function calling to check validity of multiplication of matrices
    {
        printf("\n");
        return 0; //If multiplication cannot be performed, terminate the program with return statement
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
    printf("\nMultiplying Matrices... ");
    system("pause");

    int *Product = Multiplication(Matrix_1, Matrix_2, R1, C1, C2);  //Function calling to perform Multiplication of entered matrices

    printf("\n");
    printf("Product of the matrices is -->\n");
    printf("\n");

    ShowMatrix(Product, R1, C2); //Function calling for displaying result of multiplication of matrices

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

/* Function definition to check if multiplication of matrices is possible or not */

int Validation(int C1, int R2)
{
    if (C1 != R2)
    {
        printf("Invalid dimension... Matrix multiplication is not possible...");
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

/* Function definition to perform multiplication operation with input matrices */

int *Multiplication(int *M1, int *M2, int R1, int C1, int C2)
{
    int *P = (int *)calloc((R1 * C2), sizeof(int));

    for (int i = 0; i < R1; i++)
    {
        for (int j = 0; j < C2; j++)
        {
            *(P + (i * C2) + j) = 0;

            for (int k = 0; k < C1; k++)
            {
                *(P + (i * C2) + j) += ((*(M1 + (i * C1) + k)) * (*(M2 + (k * C2) + j)));
            }
        }
    }

    return P;
}