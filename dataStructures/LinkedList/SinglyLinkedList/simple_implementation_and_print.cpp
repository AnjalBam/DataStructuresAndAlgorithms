#include <bits/stdc++.h>

using namespace std;

class Node 
{
  public:
    int data;
    Node* next;
};

void print_linked_list(Node* node)
{
  while (node != NULL) 
  {
    cout << node->data << " ";
    node = node->next;
  }
  cout << endl;
}

int main(void) 
{
  Node* head = NULL;
  Node* second = NULL;
  Node* third = NULL;
  
  head = new Node();
  second = new Node();
  third = new Node();


  head->data = 1;
  head->next = second;
  
  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  print_linked_list(head);
  return 0;
}
