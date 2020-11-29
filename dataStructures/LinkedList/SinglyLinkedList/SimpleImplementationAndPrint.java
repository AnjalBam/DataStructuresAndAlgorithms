package dataStructures.LinkedList.SinglyLinkedList;

/**
 * SimpleImplementationAndPrint
 */
public class SimpleImplementationAndPrint {
  Node head;

  static class Node {
    int data;
    Node next;

    Node(int data)
    {
      this.data = data;
      this.next = null;
    }
  }

  public void printLinkedList()  {
    Node n = head;
    while (n != null)
    {
      System.out.print(n.data + " ");
      n = n.next;
    }
    System.out.println();
  }

  public static void main(String[] args) {
    SimpleImplementationAndPrint linkedList = new SimpleImplementationAndPrint();
    linkedList.head = new Node(1);
    Node second = new Node(2);
    Node third = new Node(3);

    linkedList.head.next = second;
    second.next = third;
    third.next = null;

    linkedList.printLinkedList();
  }
}