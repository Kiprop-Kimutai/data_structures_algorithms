#include <stdio.h>
#include "string.h"
#include "stdlib.h"

int recursive(int *arr,int begin, int end, int item);
int main(void) {
  int arr[10] = {16, 19, 20, 23, 45, 56, 78, 90, 96, 100};
  int flag = -1;
  int begin = 0, end = (sizeof(arr)/sizeof(int))-1,item = 50;
   flag = recursive(arr,begin,end,item);
   if(flag>=0) {
     printf("Match found at position %d\n",flag+1);
     return 0;
   }
   printf("No match found..\n");

  return 0;
}
int recursive(int *arr,int begin, int end, int item){
  int mid = (end+begin)/2;
  if(end>=begin){
      if(arr[mid] == item) {
        return mid;
      }
      else if(arr[mid] > item) {
        return recursive(arr,begin,mid-1,item);
      }
      else {
        return recursive(arr,mid+1,  end, item);
      }
  }
  printf("end cannnot be less than beginning\n");
  return -1;
}