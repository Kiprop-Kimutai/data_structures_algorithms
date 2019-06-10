#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#define maxsize 5
int queue[maxsize];
int rear =-1, front = -1;
char *menus[10] = {"push","pop","display","exit"};
void push(void);
void display(void);
void pop(void);
int main(void) {
  int option;
  while(option !=4) {
    printf("select queue operation to perform\n");
    for(int i =0; i<4; i++) {
      printf("%d. %s\n",i+1,menus[i]);
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
      display();
      break;
      case 4:
      printf("exiting...\n");
      break;
      default:
      printf("enter valid menu\n");
      break;
    }
  }
  return 0;
}
void push(void) {
  int item;
  if(rear == maxsize) {
    printf("que overflow error\n");
    return;
  }
  printf("Enter value to queue:\n");
  scanf("%d",&item);
  //empty queue
  if(rear == -1) {
    rear = 0;
    front = 0;
    queue[rear] = item;
    printf("Item inserted into an empty queue\n");
  }
  else {
    //not an empty queue
    rear = rear+1;
    queue[rear] = item;
    printf("Item enqueued into an existing queue\n");
  }
}

void pop(void) {
  if(front == -1) {
    printf("underflow...queue is empty\n");
    return;
  }
  int item = queue[front];
  front = front+1;
  printf("Item %d has been dequeued\n",item);
}
void display(void) {
  printf("rear%d\n",rear);
  int counter = front;
  while(counter<=rear) {
    printf("element at position %d is %d\n",counter, queue[counter]);
    counter++;
  }
}