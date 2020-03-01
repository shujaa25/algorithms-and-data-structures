//Title: C program for Newton Raphson Method
//Author: Shujaa Ahmad
//Date: 19th October 2018

#include<stdio.h>
#include<math.h>

//defining function
#define f(x) (x-(2*sin(x)))
#define f1(x) (1-(2*cos(x)))

int main(void){

  float a, b, x;
  int i;

  //Calculating values for a and b
  for(i = 1; ; i++){
    if(f(i) >= 0){
      b = i;
      break;
    }else
      a = i;
  }
  x = b;
  printf("a = %f, b = %f, x0 = %f\n\n", a, b, x);

  for(i = 1; i < 7; i++){
    printf("\nIteration %d : ", i);
    x = (x - (f(x)/f1(x)));
    printf("x%d = %f", i, x);
  }

  //printf("The required root is = %f\n", x);

  return 0;
}
