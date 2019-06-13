#include <stdio.h>
#include "stdlib.h"
void mergeSort(int *arr, int begin, int end);
void merge(int *arr, int begin, int mid, int end);
int main(void) {
  int a[10]= {10, 9, 7, 101, 23, 44, 12, 78, 34, 23}; 
  int i;
  mergeSort(a, 0, 9);
  for(i =0; i<(sizeof(a)/sizeof(int));i++) {
    printf("%d\n",a[i]);
  }
  return 0;
}

void mergeSort(int *arr, int begin, int end) {
  int mid = (begin+end)/2;
  if(end>begin) {
    mergeSort(arr,begin,mid);
    mergeSort(arr, mid+1, end);
    merge(arr, begin,mid, end);
  }
}

void merge(int *arr, int begin, int mid, int end) {
  int i =begin, j = mid+1,k =begin,n=begin;
  int size = (sizeof(arr)/sizeof(int));
  int temp[10];
  while(i<=mid && j<=end) {
      if(arr[i] < arr[j]) {
        temp[k] = arr[i];
        i++;
      }
      else {
        temp[k] = arr[j];
        j++;
      }
      k++;
  }
  while(i<=mid) {
    temp[k] = arr[i];
    i++;
    k++;
  }
  while(j <= end) {
    temp[k] = arr[j];
    j++;
    k++;
  }

  while(n<k) {
    arr[n] = temp[n];
    n++;
  }
}