//Title: C program for Static Linear Queue.
//Author: Shujaa Ahmad
//Date: 11th September 2018

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

#define MAX 4 //Maximum size for stack
int stack[MAX], top = -1;

void push(int n){
  if(top == MAX-1){
    printf("\n\tError: Stack Overflow!\n\n");
  }else{
    top++;
    stack[top] = n;
    printf("\n\tMessage: Successfully Pushed %d!\n\n", n);
  }
  PAUSE
}
void pop(){
  if(top == -1){
    printf("\n\tError: Stack Underflow!\n\n");
  }else{
    int n = stack[top];
    top--;
    printf("\n\tMessage: Successfully Popped %d!\n\n", n);
  }
  PAUSE
}
void traverse(){
  if(top == -1){
    printf("\n\tError: Stack Underflow!\n\n");
  }else{
    printf("\n\tStack : [ ");
    int i;
    for(i = 0; i <= top; i++){
      printf("%d ", stack[i]);
    }
    printf("]\n");
  }
  PAUSE
}
void menu(){
  CLEAR
  int c;
  printf("[ STACK PROGRAM ]\n\n1. Push\n2. Pop\n3. Traverse\n4. Exit\n\nEnter your choice: ");
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
      printf("\n\tError: Invalid Input! Try again.\n");
  }
}
int main(){
  while(1){
    menu();
  }
  return 0;
}
