//Title: C program for Static Linear Queue.
//Author: Shujaa Ahmad
//Date: 15th September 2018

//Please ignore this block of code
#ifdef linux
#define CLEAR system("clear");
#define PAUSE system("echo Press enter to continue...; read dummy;");
#else
#define CLEAR system("cls");
#define PAUSE system("pause");
#endif
//Thanks. :-)

#include<stdio.h> //For basic IO operations
#include<stdlib.h> //For exit() function

#define MAX 4 //Maximum size for queue
int queue[MAX], front = -1, rear = -1;

void enqueue(int n){
  if(rear == MAX-1){
    printf("\n\tError: Queue is full!\n");
  }else{
    if(rear == -1){
      front = rear = 0;
    }else{
      rear++;
    }
    queue[rear] = n;
    printf("\n\tMessage: Successfully enqueued %d!\n", n);
  }
  PAUSE //Ignore it
}

void dequeue(){
  if(front == -1){
    printf("\n\tError: Queue is empty!\n");
  }else{
    int n = queue[front];
    if(front == rear){
      rear = front = -1;
    }else{
      front++;
    }
    printf("\n\tMessage: Successfully dequeued %d!\n", n);
  }
  PAUSE //Ignore it
}

void traverse(){
  if(front == -1){
    printf("\n\tError: Queue is empty!\n");
  }else{
    printf("\n\tQueue = [ ");
    int i;
    for(i = front; i <= rear; i++){
      printf("%d ", queue[i]);
    }
    printf("]\n");
  }
  PAUSE //Ignore it
}

void menu(){
  CLEAR //Ignore it
  int r;
  printf("[ QUEUE PROGRAM ]\n\n1. Enqueue\n2. Dequeue\n3. Traverse\n4. Exit\n\nEnter your choice: ");
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
