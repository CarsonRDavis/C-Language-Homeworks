/*
    Carson Davis
    CS3335
    Fall 2018
*/

#include <stdio.h>

int main(){

    int num;
    int temp;
    int size = 0;
    int count = 0;
    int d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0, d8 = 0, d9 = 0, d0 = 0;

    printf("\nEnter a number: ");
    scanf("%d", &num);

    temp = num;

    while(temp != 0){
        temp /= 10;
        size++;
    }

    int array[size];

    while(num != 0){
        array[count] = num % 10;
        num /= 10;
        count++;
    }

    for(int i = 0; i < size; i++){
        if(array[i] == 0){
            d0++;
        }
        else if(array[i] == 1){
            d1++;
        }
        else if(array[i] == 2){
            d2++;
        }
        else if(array[i] == 3){
            d3++;
        }
        else if(array[i] == 4){
            d4++;
        }
        else if(array[i] == 5){
            d5++;
        }
        else if(array[i] == 6){
            d6++;
        }
        else if(array[i] == 7){
            d7++;
        }
        else if(array[i] == 8){
            d8++;
        }
        else{
            d9++;
        }
    }

    printf("\n0:\t 1:\t 2:\t 3:\t 4:\t 5:\t 6:\t 7:\t 8:\t 9:\t");
    printf("\n%d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\t", d0, d1, d2, d3, d4, d5, d6, d7, d8, d9);
    printf("\n");

    return 0;

}