/*
    --> Insertion in array.

        --> At beginning
        --> At end
        --> At any index in between start and end
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    system("cls");
    system("color 06");

    int size;

    /* Asking user for total size of array */
    
    printf("Enter size of array to be initialised --> ");
    scanf("%d", &size);

    int *p = (int*) calloc (size, sizeof(int)); //Memory allocation for 'size' elements of array

    if(p == NULL)   //To check if memory is allocated or not. in case memmory is not alloacated, p is NULL
    {
        printf("\nError in creating Memory.. ! Returning... !");
        return 0;
    }
    else
    {
        printf("Memory initialised for %d elements...\n", size);
        printf("\n");
    }

    int inputs;

    /* Asking user for total inputs to the array */

    printf("\nHow many inputs you want to give --> ");
    scanf("%d", &inputs);

    if(inputs > size)   //To check number of inputs asked is not more than space available
    {
        printf("\nSufficient space not available... !\n");

        printf("\nTotal space asked     --> %d\n", inputs);
        printf("Total available space --> %d\n", size);

        printf("\nReturning... !\n");
        printf("\n");
        return 0;
    }

    /* Taking inputs from the user */

    printf("\n");
    printf("Input %d elements:\n", inputs);
    printf("\n-->\t");

    for(int i = 0; i < inputs; i++)
    {
        scanf("%d", (p + i));
    }

    /* Displaying array entered by the user */

    printf("\n");
    printf("Input array is:\n");
    printf("\n-->\t");

    for (int i = 0; i < inputs; i++)
    {
        printf("%d\t", *(p + i));
    }

    printf("\n");
    printf("\nReady for insertion operation... ");
    system("pause");

    if(!(inputs < size)) //Checking if space is available for insertion or not
    {
        printf("\n");
        printf("No more space available for insertion...");
        printf("\nInsertion operation cannot be performed...");
        printf("\nReturning... !");
        printf("\n");
        return 0;
    }

    int value, index;

    /* Asking user for value to be inserted */

    printf("\n");
    printf("\nInput the value to be inserted    -- > ");
    scanf("%d", &value);

    /* Asking user for index at which value to be inserted */

    printf("Index at which value to be inserted -- > ");
    scanf("%d", &index);

    if((index < 0) || (index >= size))  //Checking if given index is a valid one or not
    {
        printf("\n");
        printf("Invalid index... ! Returning... !");
        printf("\n");
        return 0;
    }

    if(index > inputs)  //Insertion at the end of the array
    {
        *(p + index) = value;
        
        printf("\n");
        printf("Value inserted succesfully !");
        printf("\n");
    }
    else if(index == 0) //Insertion at the starting of the array
    {
        int temp_holder;

        for(int i = index; i <= inputs; i++)
        {
            temp_holder = *(p + i);
            *(p + i) = value;
            value = temp_holder;
        }

        printf("\n");
        printf("Value inserted succesfully !");
        printf("\n");
    }
    else    //Insertion in between start and end of the array
    {
        int temp_holder;

        for(int i = index; i <= inputs; i++)
        {
            temp_holder = *(p + i);
            *(p + i) = value;
            value = temp_holder;
        }

        printf("\n");
        printf("Value inserted succesfully !");
        printf("\n");
    }

    /* Displaying array after inserting the value given at desired index by the user */

    printf("\n");
    printf("\nArray after insertion is:");
    printf("\n-->\t");

    for (int i = 0; i <= inputs; i++)
    {
        printf("%d\t", *(p + i));
    }

    /* End of program */

    printf("\n");
    return 0;
}