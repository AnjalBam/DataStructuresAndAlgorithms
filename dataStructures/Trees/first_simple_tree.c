#include <stdio.h>
#include <stdlib.h>

struct Node 
{
  int data;
  struct Node* left;
  struct Node* right;
};

/* 
Creates a new node with the data and left and right set to null.
@param data: data to be set to the node.
*/
struct Node* create_node(int data)
{
  // allocate memory for new node
  struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
  // set data to data part of node
  new_node->data = data;

  // set left and right part of node to NULL
  new_node->left = NULL;
  new_node->right = NULL;

  return (new_node);
}