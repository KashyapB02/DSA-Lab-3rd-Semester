/*
    --> Program to perform deletion in an array
*/

/* Header files */

#include <stdio.h>
#include <stdlib.h>

/* Function declaration for Writing and Reading to the array */

void Read(int *, int);       //Declaration of function for reading from the array
void Write(int *, int);      //Declaration of the function for writing to the array
int Delete(int *, int, int); //Declaration of the function to perform deletion in the array

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
    printf("\nReady for deletion operation... ");
    system("pause");

    int delete;

    /* Asking user for value to be deleted */

    printf("\n");
    printf("\nInput the value to be deleted    -- > ");
    scanf("%d", &delete);

    int deletion = Delete(p, size, delete); //Function call to Delete(int*, int, int)

    if (!deletion) //If input value not found for deletion
    {
        printf("\n");
        printf("Value not found in array... Deletion failed...");
        printf("\nReturning...");

        printf("\n");
        return 0;
    }
    else //If deletion is successful
    {
        printf("\n");
        printf("Value deleted succesfully !");
        printf("\n");

        size--; //Size will be reduced by 1 after deleting an element
    }

    /* Displaying array after performing deletion */

    printf("\n");
    printf("Array after deleting %d is:\n", delete);
    printf("\n-->\t");

    Read(p, size); //Function call to Read(int*, int)

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

int Delete(int *p, int size, int value) //Definition of Write(int*, int, int) funcion to perform deletion
{
    int pos = -1; //Variable to get index of element to be deleted

    for (int i = 0; i < size; i++)
    {
        if (*(p + i) == value) //Matching the value at each index with element to be deleted
        {
            pos = i;
            break;
        }
    }

    if (pos == -1) //If value to be deleted is not found in array
    {
        return 0;
    }
    else if (pos == (size - 1)) //Deletion of elemet at the end index
    {
        return 1;
    }
    else if (pos == 0) //Deletion of elemet at the starting index
    {
        for (int i = 0; i < (size - 1); i++)
        {
            *(p + i) = *(p + (i + 1));
        }

        return 1;
    }
    else //Deletion of elemet in between starting and end index
    {
        for (int i = pos; i < (size - 1); i++)
        {
            *(p + i) = *(p + (i + 1));
        }

        return 1;
    }
}