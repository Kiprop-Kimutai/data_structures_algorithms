#include <stdio.h>
#include "stdlib.h"
#include "string.h"
int main(void) {
  int list[14] = {10,20,3,6,8,5,44,33,55,33,54,67,21,37};
  int position,item, i;

  /**
  -linear search is the simplest of all search algorithms
  -involves navigating linearly across whole list and returning the position where an item has found
  */
  while(1){
  printf("Enter item to search:\n");
  scanf("%d",&item);
  for(i =0; i<14;i++) {
    if(list[i] == item) {
      printf("match found at position %d\n",i+1);
      return i+1;
    }
  }
    printf("No match found\n");
  }

  return 0;
}