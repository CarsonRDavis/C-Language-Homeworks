/*
Carson Davis
CS3335
Fall 2018
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    FILE *inf, *outf;
    int nums[10000];
    int highest;
    int lowest;
    int sum;
    int average;
    int median;
    int i = 0;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;
    int count6 = 0;
    int count7 = 0;
    int count8 = 0;
    int count9 = 0;
    int count10 = 0;

    inf = fopen("Numbers.txt", "r");

    if (inf == NULL)
    {
        fprintf(stderr, "File not found!");
        exit(1);
    }

    outf = fopen(argv[1], "w");

    if (outf == NULL)
    {
        fprintf(stderr, "Output file not working!", outf);
    }

    while (fscanf(inf, "%d", &nums[i]) != EOF)
    {
        i++;
    }

    lowest = nums[0];
    highest = nums[0];

    for (int i = 0; i < 10000; i++)
    {
        sum += nums[i];

        if (nums[i] < lowest)
        {
            lowest = nums[i];
        }

        if (nums[i] > highest)
        {
            highest = nums[i];
        }

        if (nums[i] >= 0 && nums[i] <= 999)
        {
            count1++;
        }
        else if (nums[i] >= 1000 && nums[i] <= 1999)
        {
            count2++;
        }
        else if (nums[i] >= 2000 && nums[i] <= 2999)
        {
            count3++;
        }
        else if (nums[i] >= 3000 && nums[i] <= 3999)
        {
            count4++;
        }
        else if (nums[i] >= 4000 && nums[i] <= 4999)
        {
            count5++;
        }
        else if (nums[i] >= 5000 && nums[i] <= 5999)
        {
            count6++;
        }
        else if (nums[i] >= 6000 && nums[i] <= 6999)
        {
            count7++;
        }
        else if (nums[i] >= 7000 && nums[i] <= 7999)
        {
            count8++;
        }
        else if (nums[i] >= 8000 && nums[i] <= 8999)
        {
            count9++;
        }
        else
        {
            count10++;
        }
    }

    int temp;

    for (int i = 0; i < 10000; ++i)
    {
        for (int j = i + 1; j < 10000; ++j)
        {
            if (nums[i] > nums[j])
            {

                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }

    average = sum / 10000;
    median = (nums[4998] + nums[4999]) / 2;

    fprintf(outf, "\nHighest: %d", highest);
    fprintf(outf, "\tLowest: %d", lowest);
    fprintf(outf, "\tAverage:%d", average);
    fprintf(outf, "\tMedian: %d\n", median);

    fprintf(outf, "\nRange: 0 - 999   1000 - 1999   2000 - 2999   3000 - 3999   4000 - 4999   5000 - 5999   6000 - 6999   7000 - 7999   8000 - 8999   9000 - 9999");
    fprintf(outf, "\nCount:  %d         %d         %d            %d           %d          %d          %d           %d           %d           %d",
            count1, count2, count3, count4, count5, count6, count7, count8, count9, count10);
}