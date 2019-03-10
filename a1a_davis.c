/*
Carson Davis
CS3335
Fall 2018
*/

#include <stdio.h>

int main(){
	
	int classes;
	float sum;
	
	printf("\nEnter how many classes you have (No more than 5): ");
	scanf("%d", &classes);
	
	if(classes <= 0 || classes > 5){
		printf("That number is not valid, try again!\n\n");
		return 0;
	}
	
	char gradesLetter[classes];
	int gradesNum[classes];
	
	for(int i = 0; i < classes; i++){
		printf("\nEnter a grade: ");
		scanf("%d", &gradesNum[i]);
		if(gradesNum[i] > 100 || gradesNum[i] < 0){
			printf("\nThat is not a valid grade, try again!\n\n");
			return 0;
		}
	}
	
	for(int i = 0; i < classes; i++){
		if(gradesNum[i] >= 90){
			gradesLetter[i] = 'A';
			sum += 4;
		}
		else if(gradesNum[i] >= 80 && gradesNum[i] <= 89){
			gradesLetter[i] = 'B';
			sum += 3;
		}
		else if(gradesNum[i] >= 70 && gradesNum[i] <= 79){
			gradesLetter[i] = 'C';
			sum += 2;
		}
		else if(gradesNum[i] >= 60 && gradesNum[i] <= 69){
			gradesLetter[i] = 'D';
			sum += 1;
		}
		else{
			gradesLetter[i] = 'F';
		}	
	}
	
	sum /= classes;
	
	printf("\nYour letter grades are: ");
	
	for(int i = 0; i < classes; i++){
		printf("%c ", gradesLetter[i]);
	}
	
	printf("\n");
	printf("Your number grades are: ");
	
	for(int i = 0; i < classes; i++){
		printf("%d ", gradesNum[i]);
	}
	
	printf("\n");
	printf("Your gpa is: %.2f\n\n", sum);
	
	return 0;
}