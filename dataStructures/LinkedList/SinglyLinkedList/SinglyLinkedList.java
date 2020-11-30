package dataStructures.LinkedList.SinglyLinkedList;

import java.util.Scanner;

public class SinglyLinkedList {
    Node head;

    static class Node {
        int data;
        Node next;
    }

    SinglyLinkedList() {
        this.head = null;
    }

    SinglyLinkedList(int headData) {
        this.head = new Node();
        this.head.data = headData;
        this.head.next = null;
    }

    private int getData() {
        System.out.print("Enter the number you want to enter: ");
        Scanner myScanner = new Scanner(System.in);
        int data = myScanner.nextInt();
        return data;
    }

    void push() {
        /*
        * Steps:
        *   - Get data
        *   - Allocate a new node
        *   - set value to new node;
        *   - set next of new node to current head
        *   - set head of the list as this list
        */
        // 1. get data
        int data = getData();

        // 2. Allocate a new node;
        Node newNode = new Node();

        // 3. set value to new node;
        newNode.data = data;

        // 4. set new node next as current head;
        newNode.next = this.head;

        // 5. set new node as head;
        this.head = newNode;
    }
    void append() {
        /*
        * Steps:
        *   - get data;
        *   - allocate new node;
        *   - set data and next as null in new node;
        *   - traverse to get last node;
        *   - set last node to point the new node;
        */

        // 1. get data;
        int data = getData();

        // 2. allocate new node;
        Node newNode = new Node();

        // 3. Set data and next;
        newNode.next = null;
        newNode.data = data;

        // 0. check if head is null
        if (this.head == null) {
            this.head = newNode;
            return;
        }
        // 4. traverse to get last node;
        Node last = this.head;
        while (last.next != null)
            last = last.next;

        // 5. point the prev last node next to new node;
        last.next = newNode;
    }
    void insertAfter(int value) {
       /*
       * Steps:
       * 1. get data
       * 2. get node from the linked list
       * 3. Allocate a new node
       * 4. set data
       * 5. set new node next to prev node next
       * 6. set prev node next to new node;
       */

        // 1. Get data;
        int data = getData();

        // 2. Get node from linked list
        Node corrNode = null; // corresponding node for the value
        Node temp = this.head;
        if (temp == null) return;
        // traverse through the list and set the corresponding node;
        while (temp != null) {
            if (temp.data == value) {
                corrNode = temp;
                break;
            }
            temp = temp.next;
        }
        // if no node found with the value
        if (corrNode == null) {
            System.out.println("No node found for the value");
            return;
        }
        // 3. Allocate a new node;
        Node newNode = new Node();

        // 4. Set data to new node;
        newNode.data = data;

        // 5. set new node's next to prev node's next;
        newNode.next = corrNode.next;

        // 6. set prev node next to new node
        corrNode.next = newNode;
    }
    void printList() {
        System.out.print("[ ");
        Node temp = this.head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.print("]");
        System.out.println();
    }

    public static void main(String[] args) {
        SinglyLinkedList singlyLinkedList = new SinglyLinkedList(10);
        singlyLinkedList.printList();
//        singlyLinkedList.push();
        singlyLinkedList.printList();
        Scanner choiceScanner = new Scanner(System.in);
        System.out.print("Enter the value you want to append after: ");
        int choice = choiceScanner.nextInt();
//        singlyLinkedList.append();
        singlyLinkedList.insertAfter(choice);
        singlyLinkedList.printList();
    }
}