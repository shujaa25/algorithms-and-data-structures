//Title: C program for Regula Flasi Method
//Author: Shujaa Ahmad
//Date: 19th October 2018

#include<stdio.h>

//defining function
#define f(x) ((x*x*x)-(9*x)-1)

int main(void){

  float a, b, x;
  int i;

  //given a = 3 and b = 3.1
  a = 3.0; b = 3.1;
  printf("a = %f, b = %f, f(a) = %f, f(b) = %f\n\n", a, b, f(a), f(b));

  for(i = 1; i <= 5; i++){
    printf("Iteration %d : ", i);
    x = (a*f(b) - b*f(a))/(f(b) - f(a));
    printf("x%d = %f & f(x%d) = %f\n", i, x, i, f(x));
    printf("Hence the root lies between %f & %f\n", a, b);
    if(f(x) >= 0)
      b = x;
    else
      a = x;

  }

  //printf("The required root is = %f\n", x);

  return 0;
}
