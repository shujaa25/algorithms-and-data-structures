#include<stdio.h>
#include<math.h>

int binSearch(int arr[], int n, int l, int h){
  while(l <= h){
    int mid = floor((l+h)/2);
    if(n == arr[mid])
      return mid;
    else if(n > arr[mid])
      l = mid+1;
    else
      h = mid-1;
  }
  return -1;
}

int main(void){
  int a[] = {0,1,2,3,4,5,6,7,8,9,10};

  printf("%d\n", binSearch(a, 20, 0, 10));

  return 0;

}
