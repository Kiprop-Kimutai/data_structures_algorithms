#include <stdio.h>
#include "stdlib.h"
#include "string.h"
int stack[100], top = -1,n, value, option;
char *menu[100] = {"push","pop","show","exit"};
void push(void);
void pop(void);
void show(void);
int main(void) {
  printf("Enter number of elememnts to be accomodated in stack\n");
  scanf("%d",&n);
  while(option !=4){
  printf("select an option below:\n");
  for(int i=0;i<4;i++) {
    printf("%d. %s\n",i+1,menu[i]);
  }
  scanf("%d",&option);
    switch(option) {
      case 1:
      push();
      break;
      case 2:
      pop();
      break;
      case 3:
      show();
      break;
      case 4:
      printf("exiting..\n");
      break;
      default:
      printf("select valid menu:\n");
      break;
    }
  }
  return 0;
}
void push(void) {
  printf("Enter value to push to stack..\n");
  scanf("%d",&value);
  if(top == n) {
    printf("stack overflow error\n");
    return;
  }
  top = top+1;
  stack[top] = value;
  return;
}

void pop(void) {
  if(top == -1){
    printf("stack is empty. Can't be emptied more\n");
    return;
  }
  top = top-1;
}

void show(void) {
  for(int i = top;i>=0;i--){
    printf("Element at position %d is %d\n",i,stack[i]);
  }
}