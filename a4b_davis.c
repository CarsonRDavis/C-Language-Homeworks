/*
Carson Davis
CS3335
Fall 2018
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *inf;

    int hours[20];
    int minutes[20];

    int departureTimes[10];
    int arrivalTimes[10];

    int userTimeHour;
    int userTimeMin;
    int userTimeTotal;

    int loc = 0;

    int bestArrivalTime;
    int bestDepartureTime;

    int bestArrivalHour;
    int bestArrivalMin;

    int bestDepartureHour;
    int bestDepartureMin;

    inf = fopen("flights.txt", "r");

    if (inf == NULL)
    {
        fprintf(stderr, "File could not be found!");
        exit(1);
    }

    fscanf(inf, "%*s %*s", NULL);

    while (fscanf(inf, "%d:%d ", &hours[loc], &minutes[loc]) != EOF)
    {
        loc++;
    }

    loc = 0;

    for (int i = 0; i < 20; i++)
    {
        if (i % 2 == 0)
        {
            departureTimes[loc] = (hours[i] * 60) + minutes[i];
        }
        else
        {
            arrivalTimes[loc] = (hours[i] * 60) + minutes[i];
            loc++;
        }
    }

    printf("\nEnter a departure time between 00:00 and 23:59: ");
    scanf("%d:%d", &userTimeHour, &userTimeMin);

    if (userTimeHour > 23 || userTimeHour < 0 || userTimeMin > 59 || userTimeMin < 0)
    {
        printf("Invalid time entered!");
        return 0;
    }

    userTimeTotal = (userTimeHour * 60) + userTimeMin;

    for (int i = 0; i < 10; i++)
    {
        if (userTimeTotal < departureTimes[i])
        {
            bestArrivalTime = arrivalTimes[i];
            bestDepartureTime = departureTimes[i];
            break;
        }
    }

    bestDepartureMin = bestDepartureTime % 60;
    bestDepartureHour = bestDepartureTime / 60;

    bestArrivalMin = bestArrivalTime % 60;
    bestArrivalHour = bestArrivalTime / 60;

    printf("\nThe closest departure time is: %d:%d and it will arrive in location B at: %d:%d\n", bestDepartureHour, bestDepartureMin, bestArrivalHour, bestArrivalMin);

    return 0;
}