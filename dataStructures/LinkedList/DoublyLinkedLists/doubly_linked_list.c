/*
C program to Illustrate the DoublyLinkedList(DLL);

Insertion methods in a DLL
1 - At the beginning => push();
2 - At the end => append();
3 - Before the given value => insert_before();
4 - After the given value => insert_after();

Author: Anjal Bam
github: https://github.com/anjalbam
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* prev_node, *next_node;
};

/*
create a new node with the data provided
and set prev and next as null;
@param data: data to be added to the node
*/
struct node* create_node(int data)
{
  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->prev_node = NULL;
  new_node->next_node = NULL;
  return (new_node);
}

// method for printing the list;
void print_linked_list(struct node*);

// - At the beginning => push();
void push(struct node**, int);
// - At the end => append();
void append(struct node**, int);
// - Before the given value => insert_before();
void insert_after(struct node**, int, int);
// - After the given value => insert_after();
void insert_before(int, int);

int main(void)
{
  struct node* head = create_node(12);
  print_linked_list(head);
  push(&head, 10);
  push(&head, 9);
  print_linked_list(head);
  append(&head, 30);
  append(&head, 100);
  print_linked_list(head);
  insert_after(&head, 30, 7);
  insert_after(&head, 30, 12);
  print_linked_list(head);
  return 0;
}

void print_linked_list(struct node*head)
{
  struct node *temp = head;
  printf("[ ");
  while(temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next_node;
  }
  printf("]\n");
}

/*
Inserts the data at the beginning of the DLL

@param head_ref: pointer reference to the head node
@param data: data to be inserted
*/
void push(struct node **head_ref, int new_data)
{
  // create a node with data;
  struct node* new_node = create_node(new_data);
  // set the prev head_ref prev_node to the new node;
  (*head_ref)->prev_node = new_node;
  // set the new node's next to point the prev head node;
  new_node->next_node = (*head_ref);
  // point the head ref to the new node;
  (*head_ref) = new_node;
}

/*
Inserts the data at the end of the DLL

@param head_ref: pointer reference to the head node
@param data: data to be inserted
*/
void append(struct node** head_ref, int new_data) 
{
  // create_node with the data.
  struct node* new_node = create_node(new_data);
  struct node* last = (*head_ref);

  // if list is empty make the new node the head
  if (*head_ref == NULL) {
    (*head_ref) = new_node;
    return;
  }

  // else traverse to find the last element in the list;
  while(last->next_node != NULL) 
    last = last->next_node;

  // set new node prev to point the last element
  new_node->prev_node = last;
  // set the prev last node's next to point the new node;
  last->next_node = new_node;
}

/*
This function inserts the data after the first match for the data provided as the argument;

@param ref_data: the data after which the data is to be inserted;
@param data: the data which is to be inserted;
*/
void insert_after(struct node** head_ref, int ref_data, int new_data)
{
  // create node with the data
  struct node* new_node = create_node(new_data);

  // traverse to find the first matching value in the list;
  struct node* temp = (*head_ref), *prev_node;
  while(temp != NULL)
  {
    if (temp->data == ref_data)
    {
      prev_node = temp;
      break;
    }
    temp = temp->next_node;
  }

  // inserting operation;
  // make new node next_node point the previous node's next node;
  new_node->next_node = prev_node->next_node;
  // first make the next of prev node point the new node;
  prev_node->next_node = new_node;
  // make the new node's prev node point the previous_node
  new_node->prev_node = prev_node;

  if(new_node->next_node != NULL)
    new_node->next_node->prev_node = new_node;
}