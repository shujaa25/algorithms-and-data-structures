#include<stdio.h>

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int arr[], int n){
  for(int i = 0; i < n-1; i++){
    for(int j = 0; j < n-i-1; j++)
      if(arr[j] > arr[j+1])
        swap(&arr[j], &arr[j+1]);
  }
}

void printArray(int arr[], int n){
  for(int i= 0; i<n; i++)
    printf("%d ", arr[i]);
}

int main(){
  int arr[] = {9,6,7,8,3,2,1};

  int size = sizeof(arr)/sizeof(arr[0]);

  bubbleSort(arr, size);

  printArray(arr, size);

  return 0;
}
