/*
Carson Davis
CS3335
Fall 2018
*/

#include <stdio.h>
#include <stdlib.h>

void ms(int size)
{
    int magicSquare[size][size];

    int row = 0;
    int column = size / 2;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            magicSquare[i][j] = 0;
        }
    }

    for (int i = 1; i <= size * size;)
    {

        if (row < 0 && column == size)
        {
            row += 2;
            column = size - 1;
        }
        else if (row < 0)
        {
            row = size - 1;
        }
        else if (column == size)
        {
            column = 0;
        }

        if (magicSquare[row][column] > 0)
        {
            row += 2;
            column--;
        }

        magicSquare[row][column] = i++;

        row--;
        column++;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d\t", magicSquare[i][j]);
        }
        printf("\n");
    }

    printf("\n\tThe sum is: %d\n", size * (size * size + 1) / 2);
}

int main(int argc, char *argv[])
{

    int size = atoi(argv[1]);

    if (size > 15 || size <= 0 || size % 2 == 0)
    {
        printf("Invalid size! Try Again!");
        return 0;
    }
    else
    {
        ms(size);
        return 0;
    }
}