#include<stdio.h>
#include<math.h>

void printArray(int arr[], int n){
  for(int i= 0; i<n; i++)
    printf("%d ", arr[i]);
}

void merge(int arr[], int low, int mid, int high){
  int m = mid-low+1;
  int n = high - mid;

  int left[m], right[n];

  for(int i = 0; i < m; i++)
    left[i] = arr[low+i];
  for(int j = 0; j < n; j++)
    right[j] = arr[mid+1+j];

  int i = 0, j = 0;
  int k = low;

  while(i < m && j < n){
    if(left[i] < right[j])
      arr[k++] = left[i++];
    else
      arr[k++] = right[j++];
  }
  while(i<m)
    arr[k++] = left[i++];
  while(j<n)
    arr[k++] = right[j++];
}

void mergeSort(int arr[], int low, int high){
  if(low < high){
    int mid = floor((low+high)/2);
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
  }
}

int main(){
  int arr[] = {9,6,7,8,3,2,1};

  int size = sizeof(arr)/sizeof(arr[0]);

  mergeSort(arr, 0, size-1);

  printArray(arr, size);

  return 0;
}
