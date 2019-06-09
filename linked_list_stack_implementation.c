#include <stdio.h>
#include "string.h"
#include "stdlib.h"
struct node {
  int value;
  struct node *next;
};
struct node *head;
int val,option;
char *menu[10] = {"push","pop","display","exit"};
void push(void);
void pop(void);
void display(void);
int main(void) {
  while(option != 4) {
    printf("select operation to perfom:\n");
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

void push(void) {
  struct node *ptr;
  int val;
  //scenarios; popping from an empty stack, from populated stack
  ptr = (struct node*)(malloc(sizeof(struct node *)));
  if(ptr ==NULL) {
    printf("overflow..\n");
    return;
  }
  printf("Enter value to push:\n");
  scanf("%d",&val);
  if(head == NULL) {
    ptr->value = val;
    ptr->next = NULL;
    head = ptr;
    printf("New node inserted successfully at the beginning of an empty list\n");
  }
  else {
    //if node is not empty
    ptr->value = val;
    ptr->next = head;
    head = ptr;
    printf("New node inserted successfully at the end of the list\n");
  }
}

void pop(void) {
  //scenarios; empty stack, populated stack
  int item;
  if(head == NULL) {
    printf("underflow...\n");
    return;
  }
  item = head->value;
  head = head->next;
  printf("Node with item %d popped from list\n",item);
}

void display(void) {
  struct node *ptr;
  if(head == NULL) {
    printf("underflow..\n");
    return;
  }
  ptr = head;
  while(ptr->next != NULL) {
    printf("item at current node is %d\n",ptr->value);
    ptr = ptr->next;
  }
  printf("item at current node is %d\n",ptr->value);

}

