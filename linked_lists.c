#include <stdio.h>
#include "stdlib.h"
#include "string.h"
struct node{
  int data;
  struct node *next;
};
struct node *head;
void insertFirst(void);
void insertLast(void);
void loopThroughList(void);
void randomInsert(void);
void deleteFirstNode(void);
void deleteLast(void);
void deleteRandomNode(void);
void searchItem(void);
int main(void) {
  insertFirst();
  insertLast();
  insertFirst();
  insertFirst();
  loopThroughList();
  randomInsert();
  loopThroughList();
  deleteFirstNode();
  loopThroughList();
  deleteLast();
  loopThroughList();
  deleteRandomNode();
  loopThroughList();
  searchItem();
  return 0;
}
void insertFirst(void){
  struct node * ptr;
  int item;
  printf("Enter value to insert\n");
  scanf("%d",&item);
  ptr = (struct node *)(malloc(sizeof(struct node*)));
  if(ptr == NULL) {
    printf("OVERFLOW...\n");
  }
  else{
    ptr->data = item;
    ptr->next = head;
    head = ptr;
    printf("node inserted\n");
  }
}

void insertLast(void){
  struct node *temp, *last;
  int item;
  last = (struct node *)malloc(sizeof(struct node *));
  if(last == NULL){
    printf("memory overflow!!\n");
  }
  else {
    printf("Enter integer to insert..\n");
    scanf("%d",&item);
    last->data = item;
    if(head == NULL) {
      printf("List is empty. We will insert at the beginining..\n");
      last->next = NULL;
      head = last;
    }
    else{
    temp = head;
    while(temp->next!= NULL) {
      temp = temp->next;
    }
    printf("Inserting list at the end..\n");
    temp->next = last;
    last->next = NULL;
    }
  }
}

void loopThroughList(void) {
  //avergare time (θ(n))   worst time (O(n))
  struct node *temp;
  temp = head;
  printf("print out the list....\n");
  while(temp->next !=NULL){
    printf("Data: %d\n",temp->data);
    temp = temp ->next;
  }
  printf("Last item:%d\n",temp->data);
}
void randomInsert(void) {
  struct node *temp, *next;
  int pos,item;
  next = (struct node*)malloc(sizeof(struct node*));
  if(next == NULL){
    printf("memory overflow");
    return;
  }
  printf("Enter value to insert..\n");
  scanf("%d",&item);
  printf("enter random position to insert element\n");
  scanf("%d",&pos);
  next->data = item;

  temp = head;
  for(int i = 0;i<pos; i++) {
    temp = temp->next;
    if(temp == NULL) {
      printf("Cannot insert here!!!\n");
      return;
    }
  }
  next->next = temp->next;
  temp->next = next;
  printf("Node inserted at position %d\n",pos);
}

void deleteFirstNode(void) {
  printf("About to delete head....\n");
  struct node *ptr;
  if(head == NULL){
    printf("List is empty..!\n");
    return;
  }
  ptr = (struct node*)malloc(sizeof(struct node*));
  if(ptr == NULL) {
    printf("memory overflow..\n");
    return;
  }
  ptr = head;
  head = ptr->next;
  free(ptr);
}

void deleteLast(void) {
  printf("About to delete last node..\n");
  struct node *prev,*current;
  if(head == NULL){
    printf("List is empty..\n");
    return;
  }
  if(head->next == NULL) {
    //only node in the list
    head = NULL;
    free(head);
    printf("Only item in the list has been deleted..\n");
  }
  else{
    current = head;
    while(current->next != NULL) {
      prev = current;
      current = current->next;
    }
    prev->next = NULL;
    free(current);
    printf("deleted last item in the lsit\n");
  }
}

void deleteRandomNode(void) {
  struct node *prev,*current;
  int pos;
  printf("Enter position to delete node from\n");
  scanf("%d",&pos);
  current = head;
  for(int i = 0; i<pos;i++) {
      prev = current;
      current = current->next;
      if(current == NULL){
        //this can't be deleted. It is yet to be added
        printf("Node can't be deleted\n");
        return;
      }
  }
  prev->next = current->next;
  free(current);
  printf("Node deleted at the random position\n");
}

void searchItem(void) {
  struct node *ptr;
  int item, i=0, flag = 1;
  ptr = head;
  if(ptr ==NULL) {
    printf("List is empty...\n");
    return;
  }
  printf("Enter item to search\n");
  scanf("%d",&item);
  while(ptr != NULL){
    if(ptr->data == item) {
      printf("Item found at position %d\n",i+1);
      flag = 0;
    }
      i++;
      ptr = ptr->next;
    
  }
  if(flag ==1) {
    printf("No item found...\n");
  }

}
