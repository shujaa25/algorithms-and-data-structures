//Title: C program for Doubly Linked List.
//Author: Shujaa Ahmad
//Date: 26th September 2018

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
	struct node* prev;
} node;

node* head = NULL;
node* tail = NULL;

void insertAtHead(int n){
	node* new = malloc(sizeof(node));
	if(new != NULL){
			new->value = n;
			new->prev = NULL;
			if(head == NULL){
				new->next = NULL;
				head = tail = new;
			}
			else{
				new->next = head;
				head = new;
			}
			printf("\n\tMessage: Successfully inserted %d at head!\n", n);
	}else{
		printf("\n\tError: Unable to allocate memory!\n");
	}
	PAUSE
}

void insertAtEnd(int n){
	node* new = malloc(sizeof(node));
	if(new != NULL){
			new->value = n;
			new->next = NULL;
			if(head == NULL){
				new->prev = NULL;
				head = tail = new;
			}
			else{
				new->prev = tail;
				tail->next = new;
				tail = new;
			}
			printf("\n\tMessage: Successfully inserted %d at the end!\n", n);
	}else{
		printf("\n\tError: Unable to allocate memory!\n");
	}
	PAUSE
}

void insert(int n){
	if(head != NULL){
		node* temp = head;
		while(temp->value != n && temp != NULL){
			temp = temp->next;
		}
		if(temp == NULL){
			printf("\n\tError: %d is not in the list!", n);
		}else{
			node* new = malloc(sizeof(node));
			printf("\nEnter value to insert: ");
			scanf("%d", &new->value);
			new->next = temp->next;
			new->prev = temp;
			temp->next = new;
			temp->next->prev = new;
		
			n = new->value;
		}
		printf("\n\tMessage: Successfully inserted %d!\n", n);

	}else{
		printf("\n\tError: No Linked List exists!\n");
	}
	PAUSE
}

void traverse(void){
	if(head != NULL){
		node* temp = head;
		printf("DLL = [ ");
		while(temp != NULL){
			printf("%d ", temp->value);
			temp = temp->next;
		}
		printf("]\n");
	}else{
		printf("\n\tError: No Linked List exists!\n");
	}
	PAUSE
}

void deleteFromHead(){
	if(head == NULL){
		printf("\n\tError: No Linked List exists!\n");
	}else{
		node* temp = head;
		head = head->next;
		int n = temp->value;
		free(temp);
		printf("\n\tMessage: Successfully deleted %d from head!\n", n);
	}
	PAUSE
}

void deleteFromEnd(){
	if(head == NULL){
		printf("\n\tError: No Linked List exists!\n");
	}else{
		int n;
		node* temp = head;
		if(temp->next == NULL){
			free(temp);
			head = NULL;
		}else{
			while(temp->next->next != NULL){
			temp = temp->next;
			}
			n = temp->next->value;
			free(temp->next);
			temp->next = NULL;
		}
		printf("\n\tMessage: Successfully deleted %d from the end!\n", n);
	}
	PAUSE
}

void delete(int n){
	if(head == NULL){
		printf("\n\tError: No Linked List exists!\n");
	}else{
		if(head->next == NULL){
			if(head->value == n){
				free(head);
				head = NULL;
			}else{
				printf("\n\tError: %d is not in the list!", n);	
			}
		}else{
			node* temp = head;
			while(temp->next->value != n && temp != NULL){
			temp = temp->next;
			}
			if(temp == NULL){
				printf("\n\tError: %d is not in the list!", n);
			}else{
				temp->next = temp->next->next;
				free(temp->next);
				
			}
		}
		printf("\n\tMessage: Successfully deleted %d!\n", n);
	}
	PAUSE
}

void menu(void){
	CLEAR
	int c;
	printf("[ DOUBLY LINKED LIST ]\n\n1. InsertAtHead\n2. InsertAtEnd\n3. Insert\n4. Traverse\n5. DeleteFromHead\n6. DeleteFromEnd\n7. DeleteSpecific\n8. Exit\n\nEnter your choice: ");
	scanf("%d", &c);
	switch(c){
		int n;
		case 1:
			printf("Enter value to insert: ");
			scanf("%d", &n);
			insertAtHead(n);
			break;
		case 2:
			printf("Enter value to insert: ");
			scanf("%d", &n);
			insertAtEnd(n);
			break;
		case 3:
			printf("Enter value to insert after of: ");
			scanf("%d", &n);
			insert(n);
			break;
		case 4:
			traverse();
			break;
		case 5:
			deleteFromHead();
			break;
		case 6:
			deleteFromEnd();
			break;
		case 7:
			printf("Enter value to delete: ");
			scanf("%d", &n);
			delete(n);
			break;
		case 8:
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
