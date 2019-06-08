#include <stdio.h>
#include "stdlib.h"
#include "string.h"
struct node {
  int data;
  struct node *next;
};
void beginsert(void);
void loopThroughList(void);
void lastinsert(void);
void begin_delete(void);
void last_delete(void);
void search(void);
struct node *head;
int main(void) {
  beginsert();
  lastinsert();
  lastinsert();
  lastinsert();
  begin_delete();
  last_delete();
  loopThroughList();
  search();
  return 0;
}
void beginsert(void) {
  struct node *ptr, *temp;
  int item;
  ptr = (struct node*)malloc(sizeof(struct node*));
  if(ptr == NULL) {
    printf("Memorty overflow\n");
  }
  printf("Enter node's value:\n");
  scanf("%d",&item);
  /**
  -use cases: [empty list, populated list]
  */
  ptr->data = item;
  if(head == NULL) {
    head = ptr;
    ptr->next = head;
    printf("Node inserted at the beginning of an empty list\n");
    return;
  }
  temp = head;
  while(temp->next !=head) {
    temp = temp->next;
  }
  ptr->next = temp->next;
  temp->next = ptr;
  printf("Node inserted at the beginning of not an empty list\n");
}

void lastinsert(void) {
  /*scenarios are; empty list and populated list*/
  struct node *ptr, *temp;
  int item;
  ptr = (struct node *)malloc(sizeof(struct node *));
  if(ptr == NULL) {
    printf("memory overflow...\n");
  }

  printf("Enter node's value:\n");
  scanf("%d",&item);
  ptr->data = item;
  if(head == NULL) {
    //empty list
    head = ptr;
    ptr->next = head;
    printf("Node inserted at the end of not an empty list (same as inserting at the beginning of the list\n");
  }
  temp = head;
  while(temp->next !=head) {
    temp = temp->next;
  }
  ptr->next = head;
  temp->next = ptr;
  printf("Node inserted at the end of not an empty list\n");
}

void begin_delete(void) {
  /*scenarios; empty list,populated list*/
  struct node *temp,*ptr;
  ptr = head;
  temp = head;
  if(head == NULL) {
    head = NULL;
    free(head);
    printf("deleted an empty list\n");
  }
  while(temp->next != head) {
    temp = temp->next;
  }
  temp->next = ptr->next;
  head = ptr->next;
  free(ptr);
  printf("Node deleted at the beginning of the list\n");
}

void last_delete(void) {
  /*scenarios; empty list and populated list*/
  struct node *current,*prev;
  if(head == NULL) {
    free(head);
  }
  current = head;
  while(current->next != head){
    prev = current;
    current = current->next;
  }
  prev->next = head;
  free(current);
  printf("Node deleted at the end of the list\n");

}
void search(void) {
  struct node *temp;
  int flag=0, item,i=0;
  printf("Enter item to search:\n");
  scanf("%d",&item);
  temp = head;
  while(temp->next != head) {
    if(temp->data == item) {
      printf("Match found at node %d for value %d\n",i+1,item);
      flag = 1;
      i++;
    }
    temp = temp->next;
  }
  if(temp->data == item) {
    flag = 1;
    printf("Match found at node %d for value %d\n",i+1,item);
  }
  if(!flag) {
    printf("No match found...\n");
  }
}
void loopThroughList(void) {
  struct node *temp;
  int i = 0;
  temp = head;
  while(temp->next !=head) {
    printf("Node's value at position %d = %d\n",i+1,temp->data);
    temp = temp->next;
    i++;
  }
  printf("Node's value at position %d = %d\n",i+1,temp->data);
}
