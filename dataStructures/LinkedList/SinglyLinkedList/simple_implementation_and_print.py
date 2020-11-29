class Node:
  def __init__(self, data):
    self.data = data
    self.next = None

class LinkedList:
  
  def __init__(self):
    self.head = None;


  def print_linked_list(self):
    node = self.head
    while node:
      print(node.data)
      node = node.next


if __name__ == "__main__":
    linked_list = LinkedList()
    head = Node(1)
    second = Node(2)
    third = Node(3)

    linked_list.head = head
    linked_list.head.next = second
    second.next = third
    third.next = None

    linked_list.print_linked_list()