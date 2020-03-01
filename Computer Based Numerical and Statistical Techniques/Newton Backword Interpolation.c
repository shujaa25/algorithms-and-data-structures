//Title: C program for Newton Backward Interpolation Formula
//Author: Shujaa Ahmad
//Date: 20th October 2018

#include<stdio.h>
int main(void){

	int n, i, j;
	float x, an, h, u, d;
	printf("Enter number of elements: ");
	scanf("%d", &n);

	float cx[n], cy[n], t[n][n];

	printf("Enter value of x: ");
	scanf("%f", &x);

	printf("Enter values for the column x\n");
	for(i = 0; i < n; i++){
		printf("x[%d]: ", i);
		scanf("%f", &cx[i]);
	}

	printf("Enter values for the column y\n");
	for(i = 0; i < n; i++){
		printf("y[%d]: ", i);
		scanf("%f", &cy[i]);
	}

	//Initializing the table with 0
	for(i = 0; i < n; i++){
		for(j = 1; j < n; j++){
			t[i][j] = 0;
		}
	}
	//Copying y array in 0th column of t
	for(i = 0; i < n; i++)
		t[i][0] = cy[i];

	//Calculating table values
	d = n;
	for(i = 1; i < n; i++, d--)
		for(int j = 0; j < d; j++)
			t[j-1][i] = t[j][i-1]-t[j-1][i-1];

	//Calculating values of a,h,u
	an = cx[n-1];
	h = cx[1] - cx[0];
	u = (x-an)/h;

	//printing table
	printf("\nTable (Backward):\ny\t\tDy\t\tD^2y\t\tD^3y\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%f\t", t[i][j]);
		}
		printf("\n");
	}

	printf("u = %f\n", u);

	//SEE THIS
	//Program
	x = t[4][0] + u*t[3][1] + ((u*(u+1))/2)*t[2][2] + (((u*(u+1)*(u+2))/3)/2)*t[1][3] + (((u*(u+1)*(u+2)*(u+3))/4)/6)*t[0][4];

	printf("f(x) = %f\n", x);
}
