# Trees

Unlike Arrays, Linked Lists, Stack and Queue which are linear data structures, trees are hierarchial data structures.

##### Vocabulary

- The topmost node is called the root node.
- Elements that are directly under an element are called children.
- Element directly above something is called its parent.
- Elements with no children are called leaves.

### Why Trees?

1. One Reason can be to follow the natural hierarchial form of data structure.
2. Trees (with some sort of ordering, eg. BST) provide moderate access/search (Quicker than Linked List and slower than Arrays).
3. Trees provide moderate insertion/deletion (slower than unordered Linked lists and quicker than arrays).
4. Like Linked lists and unlike Arrays there's no uppper limit for the no. of nodes as they are linked using the self referencing pointers.

### Aplications

- Manipulate hierarchial data.
- Make element access easier.
- Manipulate sorted lists of data.
- As a workflow for composing digital images for visual effects.
- Router Algorithms.
- Form a multi- stage decision-making

## Binary Tree

A tree which has at most two children is known as a **Binary Tree**. Since each element only has two children max, they're named left and right child.

#### Node

A binary tree node consists of following parts:

- Data
- Pointer to the left child
- Pointer to the right child

```c
// In C
struct Node {
  int data;
  struct Node *left;
  struct Node *right;
}
```

```python
# In Python
class Node:
  def __init__(self, d = None):
    self.data = data
    self.left = None
    self.right = None
```

```java
// In Java
class Node
{
  int key;
  Node left, right;

  public Node(int data)
  {
    key = data;
    left = right = null;
  }
}
```

```C#
// In C#
class Node
{
  int key;
  Node left, right;

  public Node(int data)
  {
    key = data;
    left = right = null;
  }
}
```

## Properties of Binary Tree

<ul>
  <li>
    <p> The max no. of nodes at a level 'l' is <span>2<sup>l</sup></span>.
    </p>
    <p>
    Here the level is the no. of nodes in the path from the root node (including the root and the node).<br><small>The level of root node is zero(0)</small>
    </p>
    <p>
    Since in binary tree a children can have at most two children, next level would have twice nodes, i.e. 2*<span>2<sup>l</sup></span>.
    </p>
  </li>
</ul>
