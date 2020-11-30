#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* next;
};

void push(struct Node** head_ref, int value) {
  /*
  This function pushes the given value to the start of the list.
  */
  struct Node* my_node = (struct Node*) malloc(sizeof(struct Node));

  my_node->data = value;
  my_node->next = *head_ref;

  *head_ref = my_node;
}

void delete_node(struct Node** head_ref, int key) {
  /*
  This deletes the first matching node with the key.
  */
  struct Node* temp = *head_ref, *prev_node;

  // If head node holds the key to be deleted.
  if(temp != NULL && key == temp->data) 
  {
    *head_ref = temp->next;

    free(temp);
    return;
  }
  // Traverse to find the key to be deleted and also keep the track of prev node
  while(temp != NULL && temp->data != key) 
  {
    prev_node = temp;
    temp = temp->next;
  }

  // if the key is not found return
  if(temp == NULL) return;

  // unlink the node from the linked list;
  prev_node->next = temp->next;
  free(temp); // Free memory;
}

void print_list(struct Node** head_ref) {
  printf("[ ");
  struct Node* temp = *head_ref;

  while(temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("]\n");

  free(temp);
}

int main() 
{
  struct Node* head = NULL;
  push(&head, 10);
  push(&head, 7);
  push(&head, 9);
  push(&head, 3);
  print_list(&head);
  delete_node(&head, 3);
  print_list(&head);
  delete_node(&head, 7);
  print_list(&head);
}