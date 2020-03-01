//Title: C program for Newton Forward Interpolation Formula
//Author: Shujaa Ahmad
//Date: 19th October 2018

#include<stdio.h>

int main(void){

	int n, i, j, k;
	float x, a, h, u, d, v, temp;
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
		for(j = 0; j < d; j++)
			t[j-1][i] = t[j][i-1]-t[j-1][i-1];

	//Calculating values of a,h,u
	a = cx[0];
	h = cx[1] - cx[0];
	u = (x-a)/h;

	//printing table
	printf("\nTable (Forward):\ny\t\tDy\t\tD^2y\t\tD^3y\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%f\t", t[i][j]);
		}
		printf("\n");
	}

	printf("u = %f\n", u);

	//x = t[0][0] + u*t[0][1] + ((u*(u-1))/2)*t[0][2] + ((u*(u-1)*(u-2))/3)*t[0][3];

	x = t[0][0];
	for(i = 0; i < n-1; i++){
		v = 1;
		for(j = 0; j <= i; j++){
			v *= (u-(j));
			printf("(u-%d)", j);
		}
		temp = v;
		printf(" = %f", temp);
		for(k = i+1; k != 1; k--){
			temp = temp/k;
			printf(" (%f/%d)", temp*k, k);
		}
		v = temp * t[0][i];
		printf(" %f\n", v);
	}

	printf("\nf(x) = %f\n", x);
}
