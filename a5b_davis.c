/*
Carson Davis
CS3335
Fall 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int processID;
    double arrivalTime;
    int duration;
    int rank;
} process;

void atSort(process processes[8])
{

    process key;
    int i, j;

    for (int i = 1; i < 7; i++)
    {
        key = processes[i];
        j = i - 1;

        while (j >= 0 && processes[j].arrivalTime > key.arrivalTime)
        {
            processes[j + 1] = processes[j];
            j = j - 1;
        }

        processes[j + 1] = key;
    }

    printf("\nSorted by Arrival Time: \n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", processes[i].processID);
    }
}

void durationSort(process processes[8])
{

    process key;
    int i, j;

    for (int i = 1; i < 7; i++)
    {
        key = processes[i];
        j = i - 1;

        while (j >= 0 && processes[j].duration > key.duration)
        {
            processes[j + 1] = processes[j];
            j = j - 1;
        }

        processes[j + 1] = key;
    }

    printf("\nSorted by Duration: \n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", processes[i].processID);
    }
}

void rankSort(process processes[8])
{

    process key;
    int i, j;

    for (int i = 1; i < 7; i++)
    {
        key = processes[i];
        j = i - 1;

        while (j >= 0 && processes[j].rank > key.rank)
        {
            processes[j + 1] = processes[j];
            j = j - 1;
        }

        processes[j + 1] = key;
    }

    printf("\nSorted by Rank: \n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", processes[i].processID);
    }
}

void menu(process processes[8])
{
    int choice;

    while (choice != 0)
    {

        printf("\n1) Sort by FCFS\n");
        printf("2) Sort by SD\n");
        printf("3) Sort by RANKED\n");
        printf("0) Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            break;
        case 1:
            atSort(processes);
            break;
        case 2:
            durationSort(processes);
            break;
        case 3:
            rankSort(processes);
            break;
        default:
            printf("\nInvalid choice!\n");
            break;
        }
    }
}

int main()
{

    FILE *in;

    process temp;
    process processes[8];

    int loc = 0;

    in = fopen("processes.txt", "r");

    if (in == NULL)
    {
        printf("File could not be found!");
    }

    fscanf(in, "%*s %*s %*s %*s", NULL);

    while (fscanf(in, "%d %lf %d %d", &temp.processID, &temp.arrivalTime, &temp.duration, &temp.rank) != EOF)
    {
        processes[loc] = temp;
        loc++;
    }

    fclose(in);

    menu(processes);

    return 0;
}