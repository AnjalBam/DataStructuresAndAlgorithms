/* 
* Singly Linked List Implementation in C
* Author: Anjal Bam
* github: anjalbam
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

int get_data() {
  int data;
  printf("Enter data you want to insert: ");
  scanf("%d", &data);
  return data;
}

void insert_node_at_front(struct Node** head) {
  /*
  @param head: reference of Head of the original Linked List
  @param node: Node to be inserted at the front of the linked list
  */
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  int data = get_data();
  new_node->data = data;
  new_node->next = *head;
  *head = new_node;
}

void insert_at_end(struct Node** head_ref) {
  int data = get_data();

  // Allocate new node 
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  struct Node *last = *head_ref;

  // Insert Data to new node
  new_node->data = data;

  // make next as null 'cause it's always gonna be at the end
  new_node->next = NULL;

  // check if head pointer/element is null 
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }

  // find the last node of the list
  while (last->next != NULL) {
    last = last->next;
  }
  // set the last node to point to the new node.
  last->next = new_node;
  return;
}

void print_linked_list(struct Node* node) {
  while (node != NULL)
  {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

void insert_after_node(struct Node* node_after) 
{
  int data = get_data();
  // Check if the prev_node provided is null; 
  if (node_after == NULL) 
  {
    printf("The previous node cannot be null!!");
    return;
  }

  // Allocate the new node;
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  // set data to new node;
  new_node->data = data;

  // set next of new node to the next of prev node;
  new_node->next = node_after->next;
  // set previous node's next as new node;
  node_after->next = new_node;
}

int main(void)
{
  struct Node* head = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL;

  head = (struct Node*) malloc(sizeof(struct Node));
  second = (struct Node*) malloc(sizeof(struct Node));
  third = (struct Node*) malloc(sizeof(struct Node));

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  print_linked_list(head);
  // insert_node_at_front(&head);
  // insert_at_end(&head);
  insert_after_node(second);
  print_linked_list(head);

  return 0;
}