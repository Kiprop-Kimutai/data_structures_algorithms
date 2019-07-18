#include <stdio.h>
#include "stdlib.h"
#include "string.h"
int fibonacci(int x);
int main(void) {
  int i;
  for(i = 0; i<11; i++) {
    printf("%d\n",fibonacci(i));
  }
  return 0;
}

int fibonacci(int x) {
  if(x == 0) {
    return 0;
  }
  if(x == 1) {
    return 1;
  }
  return fibonacci(x-1) + fibonacci(x-2);
}