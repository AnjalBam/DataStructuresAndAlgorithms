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

void print_linked_list(struct Node* node) {
  while (node != NULL)
  {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
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
  insert_node_at_front(&head);
  print_linked_list(head);

  return 0;
}