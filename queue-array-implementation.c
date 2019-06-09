#include <stdio.h>
#include "string.h"
#include "stdlib.h"
#define maxsize 5
int front = -1, rear = -1, option;
int  stack[maxsize];
char *menu[10] = {"insert","delete","display","exit"};
void insert(void);
void pop(void);
void display(void);
int main(void) {
  while(option != 4) {
    printf("Select an operation to perfom:\n");
    for(int i = 0; i<4; i++) {
      printf("%d. %s\n",i+1,menu[i]);
    }
    scanf("%d",&option);
    switch(option) {
      case 1:
      insert();
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
      printf("select a valid menu\n");
      break;
    }
  }
  return 0;
}

void insert(void){
  int item;
  printf("Enter an element to insert\n");
  scanf("%d",&item);
  //queue is full
  if(rear == maxsize) {
    printf("queue overflow error..\n");
    return;
  }
  //queue is empty
  if(rear == -1 && front == -1) {
    rear = 0;
    front = 0;
    stack[front] = item;
    printf("Element pushed to the beginning of an empty queue\n");
  }
  else {
    rear++;
    stack[rear] = item;
    printf("Element pushed to an existing queue\n");
  }
}

void display(void) {
  printf("Init...\n");
  int counter = front;
  if(front == -1){
    printf("queue is empty!\n");
    return;
  }
  while(counter <= rear){
    printf("element at position %d in the queue is %d\n", counter+1,stack[counter]);
    counter++;
  }
}

void pop(void) {
  int y;
  //empty queue
  if(front == -1) {
    printf("Can't pop from an empty queue\n");
    return;
  }
  y = stack[front];
  //if there is one element in the queue, the queue will be empty subsequently
  if(front == rear) {
    front = rear = -1;
    printf("Queue has been emptied..\n");
  }
  else
  front = front+1;
  printf("Element %d deleted from queue\n",y);

}