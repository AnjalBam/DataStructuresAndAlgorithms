# Doubly Linked List (DLL)

It is a linear data structure similar to Singly Linked List and it contains of nodes that have three main parts viz. data, previous pointer and the next pointer.

### Advantages over singly linked list

1. A DLL can be traversed in both forward and backward direction.
2. The delete operation in DLL is more efficient if pointer to the node to be deleted is given.
3. We can quickly insert a new node before a given node.

### Disadvantages over singly linked list

1. Every node of DLL Require extra space for an previous pointer.
2. All operations require an extra pointer previous to be maintained. For example, in insertion, we need to modify previous pointers together with next pointers.

### Node structure

A node consists of three parts A data and two self referencing pointers to point the prev and next data.

```c
// C implementation
struct Node {
  int data;
  struct Node* prev;
  struct Node* next;
};
```

```C++
// C++ implementation
class Node
{
  public:
    int data;
    Node* next;
    Node* prev;
};
```

```Java
// Java implementation
public class DLL {
  Node head;
  class Node {
    int data;
    Node next;
    Node prev;

    Node(int d) { data = d; }
  }
}
```

```c#
// C# implementation
public class Node {
  int data;
  Node next;
  Node prev;
}
```

## Operations

1. Insertion

- Insert at the end (Append)
- Insert at the beginning (Push)
- Insert before a node
- Insert after a node

2. Deletion

- Delete a provided node
- Delete a provided key/value
- Delete an element at a position

3. Display
