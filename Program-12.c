/*
    Program to display square of each element of a matrix
*/

/* Header files */

#include <stdio.h>
#include <stdlib.h> //Hearder file for calloc() function
#include <math.h>   //Header file for pow() function

/* Function declarations */

void GetSize(int *, int *);            //Function to get dimension of matrix from the user
void GetMatrix(int *, int, int);       //Function to get matrix input from the user
void ShowMatrix(int *, int, int);      //function to display matrix entered by the user
int *SquareElemenets(int *, int, int); //Function to square elements of the matrix

/* Starting of main() */

int main()
{
    system("cls");
    system("color 06");

    printf("!!...... Square of Each Elements of Matrix .....!!\n");
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
    printf("\nSquaring elements of Matrix... ");
    system("pause");

    int *Result = SquareElemenets(Matrix, R, C); //Function calling to square each element of matrix

    printf("\n");
    printf("Matrix after squaring each element -->\n");
    printf("\n");

    ShowMatrix(Result, R, C); //Function calling to display matrix after squaring each element

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
            printf("%3d\t", *(M + (i * C) + j));
        }

        printf("\n");
    }
}

/* Function definition to square elements of the matrix */

int *SquareElemenets(int *M, int R, int C)
{
    int *S = (int *)calloc((R * C), sizeof(int));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            *(S + (i * C) + j) = ((*(M + (i * C) + j)) * (*(M + (i * C) + j)));
        }
    }

    return S;
}