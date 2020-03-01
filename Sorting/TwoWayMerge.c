#include<stdio.h>
#include<math.h>

void merge(int A[], int B[], int m, int n){
  int i, j, k;
  i = j = k = 0;
  int C[m+n];
  while(i<m && j<n){
    if(A[i] < B[j])
      C[k++] = A[i++];
    else
      C[k++] = B[j++];
  }
  for(; i<m; i++)
      C[k++] = A[i];
  for(; j<n; j++)
      C[k++] = B[j];

  for(i = 0; i< m+n; i++)
    printf("%d ", C[i]);
}

int main(){
  int A[] = {1,4,8,9,10,15,25,35,40};
  int B[] = {2,5,6,7,45,50,55,60,65,99};

  merge(A,B,9,10);

  return 0;
}
