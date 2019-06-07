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
void loop_through_list(void);
void insertion_last(void);
void insertion_specified(void);
void deletion_beginning(void);
void deletion_last(void);
void deletion_specified(void);
void search(void);
int main(void) {
  insertion_beginning();
  insertion_last();
  insertion_specified();
  deletion_beginning();
  deletion_last();
  loop_through_list();
  deletion_specified();
  loop_through_list();
  search();
  return 0;
}

void insertion_beginning(void) {
  struct node *ptr;
  int item;
  ptr = (struct node *)malloc(sizeof(struct node *));
  if(ptr == NULL) {
    printf("memory overflow..\n");
    return;
  }
  printf("Enter node's value:\n");
  scanf("%d",&item);
  if(head == NULL) {
    //list is empty
    ptr->next = NULL;
    ptr->data = item;
    ptr->prev = NULL;
    head = ptr;
    printf("Node inserted at the beginning\n");
    
  }
  else {
      ptr->data = item;
      ptr->next = head;
      ptr->prev = NULL;
      head = ptr;
      printf("Node inserted at the beginning\n");
  }
}

void insertion_last(void) {
  struct node *ptr,*temp;
  int item;
  ptr = (struct node *)malloc(sizeof(struct node *));
  if(ptr == NULL) {
    printf("memory overflow...\n");
    return;
  }
  printf("Enter node's value:\n");
  scanf("%d",&item);
  temp = head;
  while(temp->next != NULL) {
    temp = temp->next;
  }
  ptr->data = item;
  ptr->prev = temp;
  ptr->next = NULL;
  temp->next = ptr;
  printf("node inserted at the end\n");
}

void insertion_specified(void) {
  struct node *ptr, *temp;
  int pos, item, i;
  ptr = (struct node *)malloc(sizeof(struct node *));
  if(ptr == NULL) {
    printf("memory overflow...\n");
    return;
  }
  temp = head;
  printf("Enter preferred node's position:\n");
  scanf("%d",&pos);
  printf("Enter node's value:\n");
  scanf("%d",&item);
  for(i = 0; i<pos; i++) {
    temp = temp->next;
    if(temp == NULL) {
      printf("Node can't be inserted into this position\n");
      return;
    }
  }
  ptr->data = item;
  ptr->next = temp->next;
  ptr->prev = temp;
  temp ->next = ptr;
  printf("Node inserted at the end...\n");
}

void deletion_beginning(void) {
  struct node *ptr;
  if(head ==NULL) {
    printf("List is empty\n");
    return;
  }
  if(head->next == NULL) {
    //means there is only one element in the list
    head = NULL;
    free(head);
    printf("node deleted\n");
  }
  else {
    ptr = head->next;
    ptr->prev = NULL;
    head = ptr;
    free(ptr);
    printf("node deleted..\n");
  }
}

void deletion_last(void) {
  struct node *current;
  if(head == NULL) {
    printf("List is empty\n");
  }
  if(head->next == NULL) {
    head = NULL;
    free(head);
    printf("Node deleted\n");
  }
  else {
    current = head;
    while(current !=NULL) {
      current = current->next;
    }
    current->prev->next = NULL;
    free(current);
    printf("node deleted..\n");
  }
}

void deletion_specified(void) {
  struct node *prev, *ptr;
  int pos, i;
  printf("Enter position to delete node from:\n");
  scanf("%d",&pos);
  ptr = head;
  for(i=0;i<pos;i++) {
    prev = ptr;
    ptr = ptr->next;
    if(ptr == NULL) {
      printf("can't delete\n");
      return;
    }
    if(ptr->next == NULL) {
      printf("can't delete\n");
      return;
    }
  }
  prev->next = ptr->next;
  ptr->next->prev = prev;
  free(ptr);
  printf("node at position %d deleted\n", i+1);
}
void loop_through_list(void) {
  struct node *ptr;
  int i = 0;
  ptr = head;
  while(ptr != NULL) {
    printf("value of node at position %d = %d\n",i+1, ptr->data);
    ptr = ptr->next;
    i++;
  }
}

void search(void) {
  struct node *ptr;
  int flag = 0, item, i= 0;
  ptr = head;
  if(ptr == NULL) {
    printf("Empty list!...\n");
    return;
  }
  printf("Enter item to search for:\n");
  scanf("%d",&item);
  while(ptr != NULL) {
    if(ptr->data == item) {
      printf("match found at position %d\n",i+1);
      flag = 1;
      i++;
      ptr = ptr->next;
    }
    else {
      ptr = ptr->next;
      i++;
    }
  }
  if(flag == 0) {
    printf("No match found!\n\n");
  }
}