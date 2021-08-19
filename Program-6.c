/*
    --> Program tp find highest and lowest element in an array.
*/

/* Header files */

#include <stdio.h>
#include <stdlib.h>

/* Function declaration for Writing and Reading to the array */

void Read(int *, int);       //Declaration of function for reading from the array
void Write(int *, int);      //Declaration of the function for writing to the array
int Highest(int *, int); //Declaration of the function to find highest element in the array
int Lowest(int*, int);  //Declaration of function to find lowest element in the array

/* Starting of main() */

int main()
{
    system("cls");
    system("color 06");

    int size;

    /* Asking user for total size of array */

    printf("Enter size of array to be initialised --> ");
    scanf("%d", &size);

    int *p = (int *)calloc(size, sizeof(int)); //Memory allocation for 'size' elements of array

    if (p == NULL) //To check if memory is allocated or not. in case memmory is not alloacated, p is NULL
    {
        printf("\nError in creating Memory.. ! Returning... !");
        return 0;
    }
    else
    {
        printf("Memory initialised for %d elements...\n", size);
        printf("\n");
    }

    /* Taking inputs from the user */

    printf("\n");
    printf("Input %d elements:\n", size);
    printf("\n-->\t");

    Write(p, size); //Function call to Write(int*, int)

    /* Displaying array entered by the user */

    printf("\n");
    printf("Input array is:\n");
    printf("\n-->\t");

    Read(p, size); //Function call to Read(int*, int)

    printf("\n");
    printf("\nHighest element in the array --> %d", Highest(p, size));  //Function call to Highest(int*, int)
    
    printf("\nLowest element in the array  --> %d", Lowest(p, size));  //Function call to Lowest(int*, int)
    printf("\n");

    /* End of program */

    printf("\n");
    return 0;
}

/* Function declaration for Writing and Reading to the array */

void Read(int *p, int size) //Definition of Read(int*, int) function for reading from the array
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", *(p + i));
    }
}

void Write(int *p, int size) //Definition of Write(int*, int) funcion for writing to the array
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", (p + i));
    }
}

int Highest(int *p, int size) //Definition of Highest(int*, int) funcion to perform deletion
{
    int max = *(p);

    for(int i = 0; i<size; i++)
    {
        if(*(p + i) > max)
        {
            max = *(p + i);
        }
    }

    return max;
}

int Lowest(int *p, int size) //Definition of Lowest(int*, int) funcion to perform deletion
{
    int small = *(p);

    for(int i = 0; i<size; i++)
    {
        if(*(p + i) < small)
        {
            small = *(p + i);
        }
    }

    return small;
}