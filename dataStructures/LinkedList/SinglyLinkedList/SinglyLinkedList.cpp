/* 
* Singly Linked List Implementation in C
* Author: Anjal Bam
* github: anjalbam
*/
#include <bits/stdc++.h>

using namespace std;

class Node 
{
  public:
    int data;
    Node* next;
};

class LinkedList
{
  private:
    Node* head;
  public:
    LinkedList(){
      head = NULL;
    }

    LinkedList(int head_data) {
      head = new Node();
      head->data = head_data;
      head->next = NULL;
    }
  
  private:
    int get_data();
  // insert before the head or the start of the singly linked list;
  public:
    void push();
    // Insert after the Linked List;
    void append();
    // Insert the element after a given node;
    void insert_after(Node* prev_node);
    // Print Linked List;
    void print_list();
};

int LinkedList::get_data() {
  int data;
  cout << "Enter value you want to insert: ";
  cin >> data;
  return data;
}

void LinkedList::push()
{
  /*
    Steps:
    - get data;
    - allocate new node;
    - set data to new node;
    - make head ptr to point to new node;
    - make new node's next to point prev head;
  */
  
  // 1. get data;
  int data = get_data();

  // 2. Allocate new node;
  Node* new_node = new Node();

  // 3. Set Data to new node;
  new_node->data = data;

  // 4. set new_node next to prev head
  new_node->next = this->head;

  // 5. Set set new node as the head
  this->head = new_node;
}

void LinkedList::append()
{
  /*
  Steps:
    - get data;
    - allocate new node;
    - set data to new node and next as null;
    - check if list is empty, if empty, make data head and return;
    - traverse to find the last node;
    - set last node's next to the new node;
  */
  
  // 1. Get data;
  int data = get_data();

  // 2. Allocate new node;
  Node* new_node = new Node();

  // 3. Set data and next;
  new_node->data = data;
  new_node->next = NULL;

  // 4. check if empty and and make data head if empty;
  if(this->head == NULL){
    this->head = new_node;
    return;
  }

  // 5. traverse to find the last Node;
  Node* last = this->head;
  while(last->next != NULL)
    last = last->next;
  
  // 6. Set last node's next to new node;
  last->next = new_node;
  return;
}

void LinkedList::insert_after(Node* prev_node)
{
  /*
    Steps:
      - check if the provided prev node is NULL;
      - get data;
      - allocate new node;
      - set data in a new node;
      - set new node's next to prev_node's next
      - set prev_node's next to new_node;
  */
  // 0. Check the availability of prev node;
  if (prev_node == NULL) 
  {
    cout << "The previous node must not be null" << endl;
    return;
  }

  // 1. Get data;
  int data = get_data();

  // 2. Allocate new node;
  Node* new_node = new Node();
  
  // 3. set data in new node;
  new_node->data = data;

  // 4. set prev node's next to new node's next;
  new_node->next = prev_node->next;

  // 5. set prev node's next to new node;
  prev_node->next = new_node;
}

void LinkedList::print_list()
{
  Node* temp = this->head;
  cout << "[";
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << "]" << endl;
}

int main(void) 
{
  LinkedList* linkedList = new LinkedList(12);
  linkedList->print_list();
  linkedList->push();
  linkedList->print_list();
  linkedList->append();
  linkedList->print_list();
}