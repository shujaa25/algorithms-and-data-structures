#include<stdio.h>

void insertionSort(int arr[], int n){
  int j = 0, key;
  for(int i = 0; i < n; i++){
    key = arr[i];
    j = i-1;
    while(j >= 0 && arr[j] > key){
      arr[j+1] = arr[j];
      j = j-1;
    }
    arr[j+1] = key;
  }
}

void printArray(int arr[], int n){
  for(int i= 0; i<n; i++)
    printf("%d ", arr[i]);
}

int main(){
  int arr[] = {9,6,7,8,3,2,1};

  int size = sizeof(arr)/sizeof(arr[0]);

  insertionSort(arr, size);

  printArray(arr, size);

  return 0;
}
