/*
    --> Program to find average of the elements of rows
*/

/* Header files */

#include <stdio.h>
#include <stdlib.h> //Header file for calloc() function

/* Function declarations */

void GetSize(int *, int *);       //Function to get dimension of matrix from the user
void GetMatrix(int *, int, int);  //Function to get matrix input from the user
void ShowMatrix(int *, int, int); //function to display matrix entered by the user
float RowAverage(int *, int, int);    //Function to find average of elements of a row

/* Starting of main() */

int main()
{
    system("cls");
    system("color 06");

    printf("!!...... Average of Rows .....!!\n");
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
    printf("\nCalculating average of rows... ");
    system("pause");

    printf("\n");
    fflush(stdin);

    for(int i = 1; i <= R; i++)
    {
        printf("Average of elements of Row - %d --> %.2f", i, RowAverage(Matrix, i, C));    //Function call to get average of elements of rows
        getchar();
    }

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

/* Function definition to find average of elemets of a row */

float RowAverage(int *M, int R, int C)
{
    static int i = 0;
    float Sum = 0;

    for(; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            Sum += *(M + (i *C) + j);
        }
    }

    return (Sum / C);
}