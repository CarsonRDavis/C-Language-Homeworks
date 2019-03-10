/*
Carson Davis
CS3335
Fall 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define max 10

int main(){
	
	srand(time(NULL));
	
	int number = rand() % 100;
	int attempts = 10;
	int guess;
	_Bool correct = false;
	
	for (int i = 0; i < max; i++){
		if(attempts > 1){
			printf("\nYou have %i attempts left!\n", attempts);
		}	
		else{
			printf("\nYou have %i attempt left!\n", attempts);
		}
		printf("Guess the number: ");
		scanf("%i", &guess);
		if(guess == number){
			printf("\nYou are correct!\n\n");
			correct = true;
			break;
		}
		else if(guess > number){
			printf("Too high!\n");
			attempts--;
		}
		else{
			printf("Too Low!\n");
			attempts--;
		}
	}
	
	if(correct == true){
		return 0;
	}
	else{
		printf("\nPlease try again!\n");
		printf("The number was %i\n\n", number);
		return 0;
	}
}	