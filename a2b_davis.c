/*
    Carson Davis
    CS3335
    Fall 2018
*/

#include <stdio.h>

int choice;
int retry;

void IntToBinary()
{

    long number, temp, remainder, base = 1, binary = 0;
    int retry = 2;

    printf("Enter an integer: ");
    scanf("%ld", &number);

    temp = number;

    while (number > 0)
    {
        remainder = number % 2;
        binary = binary + remainder * base;
        number = number / 2;
        base = base * 10;
    }

    printf("\nNumber inputed: %ld\n", temp);
    printf("Number in binary: %ld\n", binary);
}

void BinaryToInt()
{

    int number, temp, remainder, integer = 0, base = 1;

    printf("Enter a binary number (1s and 0s): ");
    scanf("%d", &number);

    temp = number;

    while (number > 0)
    {
        remainder = number % 10;
        integer = integer + remainder * base;
        number = number / 10;
        base = base * 2;
    }

    printf("\nNumber inputed: %d\n", temp);
    printf("Number as integer: %d\n", integer);
}

int main()
{

    printf("\nType 0 for IntToBinary and Type 1 for BinaryToInt: ");
    scanf("%d", &choice);

    if (choice == 0)
    {
        IntToBinary();
    }
    else if (choice == 1)
    {
        BinaryToInt();
    }
    else
    {
        puts("\nEnter 0 or 1!");
        main();
    }

    printf("\nTry again? 1 for yes or another number for no: ");
    scanf("%d", &retry);

    if (retry == 1)
    {
        main();
    }
    else
    {
        return 0;
    }
}