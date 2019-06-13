#include <stdio.h>

int main(void) {
  int arr[] = { 12, 11, 13, 5, 6 }; 
  int i,j,temp;
  for(i=1;i<5;i++) {
    temp = arr[i];
    j = i-1;
    while(j>=0 && temp <= arr[j]) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = temp;
  }
  printf("sorted array\n");
  for (int x = 0; x<5;x++) {
    printf("%d\n",arr[x]);
  }
  return 0;
}