/*
    Program to find transpose of a matrix
*/

/* Header files */

#include <stdio.h>
#include <stdlib.h> //Hearder file for calloc() function

/* Function declarations */

void GetSize(int *, int *);       //Function to get dimension of matrix from the user
void GetMatrix(int *, int, int);  //Function to get matrix input from the user
void ShowMatrix(int *, int, int); //function to display matrix entered by the user
int *Transpose(int *, int, int);  //Function to calculate transpose of the matrix input by user

/* Starting of main() */

int main()
{
    system("cls");
    system("color 06");

    printf("!!...... Transpose of Matrix .....!!\n");
    printf("\n");

    int R, C; //Variables to store dimension of matrix

    printf("!!-----> Input dimension of matrix <-----!!\n");
    printf("\n");

    GetSize(&R, &C); //Function calling for user input of dimension of matrix

    int *Matrix = (int *)calloc((R * C), sizeof(int)); //Memory allocation for matrix

    printf("\n");
    printf("Input Matrix -->\n");
    printf("\n");

    GetMatrix(Matrix, R, C); //Function calling for user input of matrix

    printf("\n");
    printf("\n!..... Displaying Matrix .....!");
    printf("\n");

    printf("\n");
    ShowMatrix(Matrix, R, C); //Function calling for displaying matrix entered by the user

    printf("\n");
    printf("\nCalculating Transpose of Matrix... ");
    system("pause");

    int *Result = Transpose(Matrix, R, C); //Function calling to calculate transpose of matrix

    printf("\n");
    printf("!!-----> Transpose of Matrix <-----!!\n");
    printf("\n");

    ShowMatrix(Result, C, R); //Function calling to display matrix after after calculating transpose

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

/* Function definition to calculate transpose of the matrix */

int *Transpose(int *M, int R, int C)
{
    int *T = (int *)calloc((R * C), sizeof(int));

    for (int j = 0; j < C; j++)
    {
        for (int i = 0; i < R; i++)
        {
            *(T + (j * R) + i) = *(M + (i * C) + j);
        }
    }

    return T;
}