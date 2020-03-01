//Title: C program for Queue using singly linked list.
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

node* head = NULL;

void enqueue(int n){
	node* new = malloc(sizeof(node));
	if(new != NULL){
			new->value = n;
			new->next = NULL;
			if(head == NULL){
				head = new;
			}else{
				node* temp = head;
				while(temp->next != NULL){
					temp = temp->next;
				}
				temp->next = new;
			}
			printf("\n\tMessage: Successfully enqueued %d!\n", n);
	}else{
		printf("\n\tError: Unable to allocate memory!\n");
	}
	PAUSE
}

void traverse(void){
	if(head != NULL){
		node* temp = head;
		printf("Queue = [ ");
		while(temp != NULL){
			printf("%d ", temp->value);
			temp = temp->next;
		}
		printf("]\n");
	}else{
		printf("\n\tError: Queue is empty!\n");
	}
	PAUSE
}

void dequeue(){
	if(head == NULL){
		printf("\n\tError: Queue is empty!\n");
	}else{
		node* temp = head;
		head = head->next;
		int n = temp->value;
		free(temp);
		printf("\n\tMessage: Successfully dequeued %d!\n", n);
	}
	PAUSE
}

void menu(void){
	CLEAR
	int r;
  printf("[ QUEUE PROGRAM using Singly Linked List]\n\n1. Enqueue\n2. Dequeue\n3. Traverse\n4. Exit\n\nEnter your choice: ");
  scanf("%d", &r);
  switch(r){
    int n;
    case 1:
      printf("\nEnter value to enqueue: ");
      scanf("%d", &n);
      enqueue(n);
      break;
    case 2:
      dequeue();
      break;
    case 3:
      traverse();
      break;
    case 4:
      exit(0);
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
