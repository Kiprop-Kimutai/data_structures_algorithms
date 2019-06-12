#include <stdio.h>
#include "stdio.h"
#include "string.h"
//bubble sort
int main(void) {
  int a[10] = { 10, 9, 7, 101, 23, 44, 12, 78, 34, 23};
  int temp, i,j;
  for(i = 0; i<10; i++) {
    for(j = i+1;j<10;j++) {
      if(a[i] > a[j]) {
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
      }
    }
  }
  printf("sorted list...\n");
  for(int x = 0;x<10;x++) {
    printf("%d\n",a[x]);
  }
  return 0;
}