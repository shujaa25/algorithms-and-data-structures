//Title: C program for bisection method
//Author: Shujaa Ahmad
//Date: 19th October 2018

#include<stdio.h>
#include<math.h>

//defining function
#define f(x) x-cos(x)

int main(void){

  float a, b, x;
  int i;

  //Calculating values for a and b
  for(i = 0; ; i++){
    if(f(i) >= 0){
      b = i;
      break;
    }else
      a = i;
  }
  printf("a = %f, b = %f, f(a) = %f, f(b) = %f\n\n", a, b, f(a), f(b));

  for(i = 1; i <= 20; i++){
    printf("Iteration %d : ", i);
    x = (a + b) / 2;
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
