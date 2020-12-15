/*
C program to Illustrate the DoublyLinkedList(DLL);

Insertion methods in a DLL
1 - At the beginning => push();
2 - At the end => append();
3 - Before the given value => insert_before();
4 - After the given value => insert_after();

Deletion methods
1 - Deleting the provided node => delete_node();
2 - Deleting the first occourence of the provided key => delete_key();
3 - Deleting the object at the given position => delete_at_pos();

Display Methods
1 - Display forwards => print_linked_list();

Author: Anjal Bam
College: Thapathali Campus
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

void push(struct node**, int);
void append(struct node**, int);
void insert_after(struct node**, int, int);
void insert_before(struct node**, int, int);

void delete_node(struct node**, struct node*);
void delete_key(struct node**, int );
void delete_at_pos(struct node**, int);

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
  insert_before(&head, 30, 111);
  insert_before(&head, 30, 112);
  print_linked_list(head);
  // delete_node(&head, head->next_node);
  print_linked_list(head);
  delete_key(&head, 30);
  print_linked_list(head);
  delete_at_pos(&head, 1);
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
@param new_data: the data which is to be inserted;
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

/*
This function inserts the data before the first match for the data provided as the argument;

@param ref_data: the data before which the data is to be inserted;
@param new_data: the data which is to be inserted;
*/
void insert_before(struct node** head_ref, int ref_data, int new_data)
{
  // create node with the data;
  struct node *new_node = create_node(new_data);

  // traverse to find the first matching value in the list;
  struct node* temp = (*head_ref), *match_node;
  while(temp != NULL)
  {
    if (temp->data == ref_data)
    {
      match_node = temp;
      break;
    }
    temp = temp->next_node;
  }

  // inserting operation start;
  // point new node prev node to match_node prev node;
  new_node->prev_node = match_node->prev_node;

  // if match node's prev node is not null make it's next node point to the new node 
  if (match_node->prev_node != NULL)
    match_node->prev_node->next_node = new_node;

  // point new node's next to matching node;
  new_node->next_node = match_node;

  // point matching node's prev to point the new node;
  match_node->prev_node = new_node;
}

/*
Deletes the node provided as the second argument

@param head_ref: pointer reference to the head of the list;
@param del_node: node to be freed or deleted from the list;
*/
void delete_node(struct node** head_ref, struct node*del_node)
{
  // Base condition check
  if (del_node == NULL || *head_ref == NULL)
    return;

  // if provided node is the head node;
  if((*head_ref) == del_node) 
    *head_ref = del_node->next_node;
  
  // if next of node to be deleted is NOT the last node update the prev node of the next od the del_node
  if (del_node->next_node != NULL) 
    del_node->next_node->prev_node = del_node->prev_node;

  // if the del node is NOT the first node update the next of the prev of the del node to the next of current del node;
  if (del_node->prev_node != NULL)
    del_node->prev_node->next_node = del_node->next_node;

  free(del_node);
  return;
}

/*
This method deletes the first node with the given value
@param head_ref: pointer to the reference of head node;
@param key: the data to be deleted
*/
void delete_key(struct node**head_ref, int key)
{
  // find the element/node with the key
  struct node* temp = (*head_ref), *match_node;
  while(temp != NULL) 
  {
    if (temp->data == key)
    {
      match_node = temp;
      break;
    }
    temp = temp->next_node;
  }
  //delete the key
  // printf("%d\n", match_node->data);
  delete_node(head_ref, match_node);
}
/*
This method deletes the node at the position
@param head_ref: pointer to the reference of head node;
@param key: the position of element in the list to be deleted;
*/
void delete_at_pos(struct node**head_ref, int pos)
{
  // find the node at the position
  struct node*current = (*head_ref);
  for(int i = 1; current != NULL && i < pos; i++)
    current = current->next_node;
  // delete the node at the position
  delete_node(head_ref, current);
  // printf("%d\n", current->data);
}