## Linked List

It is a simple type of Linear data structure in which data is stored in terms of Nodes that store data and a pointer that always points to the next data node available or _Null_ if no node available. And the elements are not stored at the contiguous memory locations but at different locations and are connected to each other via pointers.

#### Types of Linked Lists:

- Singly Linked List
- Circular Linked List
- Doubly Linked List

### Singly Linked List

It is a type of linked list in which each node is connected via pointer and has a data and a pointer/reference that points to the next node or to the Null if no data is available or is the last element/node in the list.

The node structure contains the Data part as well as the node reference part;

```c
// in C
struct Node {
  int data;
  struct Node* next;
};
```

```cpp
  // in C++
  class Node
  {
    int data;
    Node* next;
  };
```

```python
  # In python
  class Node:
    def __init__(self):
      self.data = None
      self.next = None
```

```java
  // in java
  static class Node
  {
    int data;
    Node next;
  }
```

#### Operations to be performed

- Insertion

  - at the front/head(push)
  - at the end(append)
  - after a given key

- Deletion
- Searching
- Traversing
- Reversing

##### Insertion

The insertion of an element is the performed using the following algorithm.

- Define new node
- set data to new node
- set new node's next to prev node's next
- set prev node's next to new node

> The Insertion process in this linked list has time complexity of **O(1)** which is quite efficient.
