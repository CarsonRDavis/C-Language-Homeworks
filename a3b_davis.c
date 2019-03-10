/*
Carson Davis
CS3335
Fall 2018
*/

#include <stdio.h>
#include <string.h>

void encode(char phrase[30], int rotation)
{
    char letter;
    int value;

    printf("\nYour original phrase: %s", phrase);
    printf("\nYour encoded phrase: ");

    for (int i = 0; i < strlen(phrase); i++)
    {
        if (phrase[i] >= 'a' && phrase[i] <= 'z')
        {
            value = (((int)phrase[i] + rotation - 97) % 26 + 97);
            letter = (char)value;
        }
        else if (phrase[i] >= 'A' && phrase[i] <= 'Z')
        {
            value = (((int)phrase[i] + rotation - 65) % 26 + 65);
            letter = (char)value;
        }
        else
        {
            letter = ' ';
        }
        printf("%c", letter);
    }
    printf("\n");
}

int main()
{

    char phrase[30];
    int rotation;

    printf("\nEnter a phrase to encode: ");
    gets(phrase);

    if (strlen(phrase) > 30 || strlen(phrase) == 0)
    {
        printf("\nInvalid phrase size, keep it between 1 and 30!");
        main();
    }

    printf("Enter a rotation (1 to 9): ");
    scanf("%d", &rotation);

    if (rotation < 1 || rotation > 9)
    {
        printf("\nInvalid rotation size, use between 1 and 9!");
        main();
    }

    encode(phrase, rotation);

    return 0;
}