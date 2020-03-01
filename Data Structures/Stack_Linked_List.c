//Title: C program for Stack using singly linked list.
//Author: Shujaa Ahmad
//Date: 21th September 2018

#include<stdio.h>
#include<stdlib.h>

//Please ignore this block of code
#ifdef linux
#define CLEAR system("clear");
#define PAUSE system("echo Press enter to continue...; read dummy;");
#else
#define CLEAR system("cls");
#define PAUSE system("pause");
#endif
//Thanks. :-)

typedef struct node{
	int value;
	struct node* next;
} node;

node* top = NULL;

void push(int n){
	node* new = malloc(sizeof(node));
	if(new != NULL){
			new->value = n;
			new->next = NULL;
			if(top == NULL){
				top = new;
			}else{
				node* temp = top;
				while(temp->next != NULL){
					temp = temp->next;
				}
				temp->next = new;
			}
			printf("\n\tMessage: Successfully pushed %d!\n", n);
	}else{
		printf("\n\tError: (STACK OVERFLOW!) Unable to allocate memory!\n");
	}
	PAUSE
}

void traverse(void){
	if(top != NULL){
		node* temp = top;
		printf("Stack = [ ");
		while(temp != NULL){
			printf("%d ", temp->value);
			temp = temp->next;
		}
		printf("]\n");
	}else{
		printf("\n\tError: Stack underflow!\n");
	}
	PAUSE
}

void pop(){
	if(top == NULL){
		printf("\n\tError: Stack underflow!\n");
	}else{
		int n;
		if(top->next != NULL){
			node* temp = top;
			while(temp->next->next != NULL){
				temp = temp->next;
			}
			n = temp->next->value;
			free(temp->next);
			temp->next = NULL;
		}else{
			n = top->value;
			free(top);
			top = NULL;
		}
		printf("\n\tMessage: Successfully popped %d!\n", n);
	}
	PAUSE
}

void menu(void){
	CLEAR
	int c;
	printf("[ STACK PROGRAM using Singly Linked List ]\n\n1. Push\n2. Pop\n3. Traverse\n4. Exit\n\nEnter your choice: ");
  scanf("%d", &c);
	switch(c){
		int n;
		case 1:
      printf("\nEnter value to push: ");
      scanf("%d", &n);
      push(n);
      break;
    case 2:
      pop();
      break;
    case 3:
      traverse();
      break;
    case 4:
      exit(0);
      break;
		default:
			printf("\n\tError: Invalid input!\n");
	}
}

int main(void){
	while(1){
		menu();
	}
	return 0;
}
