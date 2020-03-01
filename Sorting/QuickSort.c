#include<stdio.h>
#include<math.h>

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printArray(int arr[], int n){
  for(int i= 0; i<n; i++)
    printf("%d ", arr[i]);
}

int partition(int arr[], int low, int high){
  int pivot = arr[low];
  int i = low, j = high;

  while(i < j){
    while(arr[i] <= pivot)
      i++;
    while(arr[j] > pivot)
    j--;
    if(i < j)
      swap(&arr[i], &arr[j]);
  }
  swap(&arr[low], &arr[j]);
  return j;
}

void quickSort(int arr[], int low, int high){
  if(low < high){
    int pt = partition(arr, low, high);
    quickSort(arr, low, pt);
    quickSort(arr, pt+1, high);
  }
}

int main(){
  int arr[] = {9,6,7,8,3,2,1};

  int size = sizeof(arr)/sizeof(arr[0]);

  quickSort(arr, 0, size-1);

  printArray(arr, size);

  return 0;
}
