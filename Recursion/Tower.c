//Title: C program to solve the Tower of Hanoi puzzle using recursion.
//Author: Shujaa Ahmad
//Date: 20th September 2018
#include<stdio.h>

int i = 0; //global var. to count total number of moves

void move(int n, char source, char dest, char aux){
	i++;
	if(n == 1){
		printf("Move: %c to %c\n", source, dest);
	}else{
		move(n-1, source, aux, dest);
		printf("Move: %c to %c\n", source, dest);
		move(n-1, aux, dest, source);
	}
}

int main(void){
	int n;
	printf("Enter number of plates: ");
	scanf("%d", &n);
	printf("\n\nA = Source, B = Auxiliary, C = Destination\n\n");
	move(n, 'A', 'C', 'B');
	printf("\nTotal moves: %d\n", i);
	return 0;
}
