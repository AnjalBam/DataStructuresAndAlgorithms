#include <bits/stdc++.h>

using namespace std;

class Node 
{
  public:
    int data;
    Node* next;
};

void push(Node** head_ref, int value)
{
  Node* new_node = new Node(), *temp;
  new_node->data = value;
  
  new_node->next = *head_ref;
  *head_ref = new_node;
}

void print_list(Node *head) {
  Node *temp = head;
  cout << "[ ";
  while(temp != NULL) 
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << "]" << endl;

  delete temp;
}

void delete_node(Node** head_ref, int key)
{
  Node* temp = *head_ref;
  Node* prev_node = NULL;

  // if key  is the head element;
  if(temp != NULL && temp->data == key) 
  {
    *head_ref = temp->next; // Change the new head pos
    delete temp; // delete the old head
    return;
  }

  // search for the key and also keep track of the prev node
  while(temp != NULL && temp->data != key)
  {
    prev_node = temp;
    temp = temp->next;
  }

  if(temp == NULL) return;

  prev_node->next = temp->next; // unlink the node;
  delete temp;
  return;
}

int main()
{
  Node *head = NULL;
  push(&head, 10);
  push(&head, 9);
  push(&head, 3);
  push(&head, 1);
  print_list(head);
  delete_node(&head, 3);
  delete_node(&head, 1);
  print_list(head);
}