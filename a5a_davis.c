/*
Carson Davis
CS3335
Fall 2018
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int addressNum;
    char roadName[50];
    char roadExt[50];
    int sqrFeet;
    int price;
} house;

void searchByFeet(house houses[20], int lowFeet, int highFeet)
{

    printf("\n");

    for (int i = 0; i < 20; i++)
    {
        if (houses[i].sqrFeet >= lowFeet && houses[i].sqrFeet <= highFeet)
        {
            printf("Address: %d %s %s\t Price: $%d\n", houses[i].addressNum, houses[i].roadName, houses[i].roadExt, houses[i].price);
        }
    }

    return;
}

void searchByPrice(house houses[20], int lowPrice, int highPrice)
{

    printf("\n");

    for (int i = 0; i < 20; i++)
    {
        if (houses[i].price >= lowPrice && houses[i].price <= highPrice)
        {
            printf("Address: %d %s %s\t Square Feet: %d\n", houses[i].addressNum, houses[i].roadName, houses[i].roadExt, houses[i].sqrFeet);
        }
    }

    return;
}

void searchByName(house houses[20], char roadName[50], char roadExt[50])
{

    printf("\n");

    int totalPrice = 0;
    int totalFeet = 0;

    int count = 0;

    int averagePrice = 0;
    int averageFeet = 0;

    for (int i = 0; i < 20; i++)
    {
        if (strcmp(houses[i].roadName, roadName) == 0 && strcmp(houses[i].roadExt, roadExt) == 0)
        {
            totalPrice += houses[i].price;
            totalFeet += houses[i].sqrFeet;
            count++;
        }
    }

    averagePrice = totalPrice / count;
    averageFeet = totalFeet / count;

    printf("Average Square Feet: %d\t Average Price: %d\n\n", averageFeet, averagePrice);

    for (int i = 0; i < 20; i++)
    {
        if (strcmp(houses[i].roadName, roadName) == 0 && strcmp(houses[i].roadExt, roadExt) == 0)
        {
            printf("Address: %d %s %s   Price: $%d   Square Feet: %d\n", houses[i].addressNum, houses[i].roadName, houses[i].roadExt, houses[i].price, houses[i].sqrFeet);
        }
    }

    return;
}

void menu(house houses[20])
{
    int choice = 1;

    int lowFeet = 0;
    int highFeet = 0;

    int lowPrice = 0;
    int highPrice = 0;

    char roadName[50];
    char roadExt[50];

    while (choice != 0)
    {

        printf("\n1) Search by Square feet\n");
        printf("2) Search by Price\n");
        printf("3) Search by Road Name\n");
        printf("0) Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("Enter your lowest square feet: ");
            scanf("%d", &lowFeet);
            printf("Enter your highest square feet: ");
            scanf("%d", &highFeet);

            if (lowFeet > highFeet)
            {
                printf("Invalid numbers entered!");
                break;
            }

            searchByFeet(houses, lowFeet, highFeet);
            break;

        case 2:

            printf("Enter your lowest price: ");
            scanf("%d", &lowPrice);
            printf("Enter your highest price: ");
            scanf("%d", &highPrice);

            if (lowPrice > highPrice)
            {
                printf("Invalid numbers entered!");
                break;
            }
            searchByPrice(houses, lowPrice, highPrice);
            break;

        case 3:

            printf("Enter a road to search for (EX: Ruby Way): ");
            scanf("%s %s", &roadName, &roadExt);

            searchByName(houses, roadName, roadExt);
            break;

        default:
            printf("\nInvalid choice!\n");
            break;
        }
    }

    return;
}

int main()
{

    house temp;
    int loc = 0;

    house houses[20];

    FILE *in;

    in = fopen("properties.txt", "r");

    if (in == NULL)
    {
        printf("File not found!");
    }

    fscanf(in, "%*s %*s %*s", NULL);

    while (fscanf(in, "%d %s %s %d %d", &temp.addressNum, &temp.roadName, &temp.roadExt, &temp.sqrFeet, &temp.price) != EOF)
    {
        houses[loc] = temp;
        loc++;
    }

    fclose(in);

    menu(houses);

    return 0;
}