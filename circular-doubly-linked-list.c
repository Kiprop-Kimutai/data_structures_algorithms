#include <stdio.h>
#include "string.h"
#include "stdlib.h"
struct node {
  struct node *prev;
  int data;
  struct node *next;
};
struct node *head;
void insertion_beginning(void);
void loopThroughList(void);
void insertion_last(void);
void deletion_beginning(void);
void deletion_last(void);
void search(void);
int main(void) {
  insertion_beginning();
  loopThroughList();
  insertion_beginning();
  insertion_beginning();
  insertion_last();
  loopThroughList();
  deletion_beginning();
  loopThroughList();
  deletion_last();
  loopThroughList();
  search();
  return 0;
}
void insertion_beginning(void) {
  //likely scenarios; empty list, populated list
  struct node *ptr,*temp;
  int item;
  ptr = (struct node*)malloc(sizeof(struct node *));
  if(ptr == NULL) {
    printf("Memory overflow..\n");
    return;
  }
  printf("Enter node's value:\n");
  scanf("%d",&item);
  if(head == NULL) {
    //means the list is empty
    ptr->data = item;
    head = ptr;
    ptr->next = head;
    ptr->prev = head;
    printf("Node inserted at the beginning of an empty list\n");
  }
  else {
    //not an empty list
    temp = head;
    ptr->data = item;
    while(temp->next != head) {
      temp = temp->next;
    }
    temp->next = ptr;
    ptr->next = head;
    ptr->prev = temp;
    head->prev = ptr;
    head = ptr;
    printf("Node inserted at the beginning of not an empty list\n");
  }
}

void insertion_last(void) {
  //likely scenarios; empty list, populated list
  struct node *ptr,*temp;
  int item;
  ptr = (struct node *)(malloc(sizeof(struct node *)));
  if(ptr == NULL) {
    printf("memory overflow...\n");
    return;
  }
  printf("Enter node's value:\n");
  scanf("%d",&item);
  if(head == NULL) {
    //list is empty
    ptr->data = item;
    head = ptr;
    ptr->next = head;
    ptr->prev = head;
    head = ptr;
    printf("Node inserted at the beginning of an empty list\n");
  }
  else {
    temp = head;
    while(temp->next != head) {
      temp = temp->next;
    }
    ptr->data = item;
    temp->next = ptr;
    ptr->next = head;
    ptr->prev = temp;
    head->prev = ptr;
    printf("Node inserted at the end on not an empty list\n");
  }
}
void deletion_beginning(void) {
  struct node *ptr,*temp;
  temp = head;
  ptr = head->next;
  while(temp->next != head) {
    temp = temp->next;
  }
  temp->next = ptr;
  ptr->prev = temp;
  head = ptr;
  free(ptr);
  printf("Node deleted at the beginning\n");
}
void deletion_last(void) {
  struct node  *temp;
  temp = head;
  while(temp->next != head) {
    temp = temp->next;
  }
  temp->prev->next = head;
  head->prev = temp->prev;
  free(temp);
  printf("Node deleted at the end\n");
}
void search(void) {
  struct node *temp;
  int item, flag = 0,i=0;
  printf("Enter item to search for:\n");
  scanf("%d",&item);
  temp = head;
  while(temp->next != head) {
    if(temp->data == item) {
      printf("match found at node %d for value %d\n",i+1,item);
      flag = 1;
    }
    temp = temp->next;
    i++;
  }
  if(temp->data == item) {
  printf("match found at node %d for value %d\n",i+1,item);
  flag = 1;
  }
  if(!flag) {
    printf("No match found for item..\n");
  }
}

void loopThroughList(void) {
  struct node *temp;
  int i = 0;
  temp = head;
  while(temp->next != head) {
    printf("Node value at position %d = %d\n",i+1,temp->data);
    temp = temp->next;
    i++;
  }
  printf("Node value at position %d = %d\n",i+1,temp->data);
}

