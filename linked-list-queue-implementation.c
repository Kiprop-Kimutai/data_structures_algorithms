#include <stdio.h>
#include "string.h"
#include "stdlib.h"
struct node{
  int data;
  struct node *next;
};
struct node *front;
struct node *rear;
void push(void);
void pop(void);
void display(void);
char *menu[10] = {"push","pop","display","exit"};
void display(void);
int main(void) {
  int option;
  printf("select queue operation to perform:\n");
  while(option != 4) {
    for(int i = 0; i<4;i++) {
      printf("%d.%s\n",i+1, menu[i]);
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
      printf("exiting..\n");
      break;
      default:
      printf("select a valid menu\n");
    }
  }
  return 0;
}
void push(void) {
  struct node *element;
  int value;
  element = (struct node *)(malloc(sizeof(struct node*)));
  if(element == NULL) {
    printf("memory overflow..\n");
    return;
  }
  printf("enter value to queue\n");
  scanf("%d",&value);
  if(rear == NULL){
    //queue is empty
    element->data = value;
    element->next = NULL;
    front = element;
    rear = element;
    printf("Element queued at an empty queue\n");
  }
  else {
    //not an empty queue
    element->data = value;
    element->next = NULL;
    rear->next = element;
    rear = element;
    printf("Item queued at a populated queue\n");
  }
}

void pop(void) {
  struct node *ptr;
  if(front == NULL) {
    printf("underflow..\n");
    return;
  }
  ptr = front;
  front = front->next;
  free(ptr);
  printf("Item dequeued successfully\n");

}
void display(void) {
  struct node *ptr;
  int i = 0;
  ptr = front;
  if(rear == NULL) {
    printf("queue is empty\n");
    return;
  }

  while(ptr != NULL) {
    printf("Value at position %d in queue is %d\n",i+1,ptr->data);
    i++;
    ptr = ptr->next;
  }
}