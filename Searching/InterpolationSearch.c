#include<stdio.h>

int search(int arr[], int key, int n){
  int l = 0, h = n-1;
  while(l < h){
    int mid = l + ((h-l)/(arr[h]-arr[l]))*(key-arr[l]);

    if(key == arr[mid])
      return mid;
    else if(key > arr[mid])
      l = mid+1;
    else
      h = mid-1;
  }
  return -1;
}

int main(void){
  int arr[] = {1,2,3,4,5,6,7,9,10,20,25,50,90,100};
  int size = sizeof(arr)/sizeof(arr[0]);
  int res = search(arr, 5, 0, size);
  if(res != -1)
    printf("Index = %d\n", res);
}
