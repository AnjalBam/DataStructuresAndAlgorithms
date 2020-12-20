#include <bits/stdc++.h>

using namespace std;
/*
The Node for the implementation of circular linked list.
*/
class Node 
{
    public:
        int data;
        Node* next;

        Node()
        {
            data = 0;
            next = NULL;
        }
        Node(int data)
        {
            this->data = data;
        }
};

class CircularLinkedList
{
    public: 
    Node* head;

    CircularLinkedList() { head = NULL; }
    CircularLinkedList(int data) 
    {
        Node* head_node = new Node(data);
        head_node->next = head_node;
        head = head_node;
    }

    /*
    This method checks if the node exists in the list and returns it, or NULL if no data is matched in the list.
    @param data: data to be looked for in the list.
    */
    Node* node_exists(int data)
    {
        Node* ptr = head;

        if (ptr == NULL) 
            return NULL;
        
        do
        {
            if (ptr->data == data)
            {
                return ptr;
            }
            ptr = ptr->next;
        } while (ptr != head);
        return NULL;
    }

    /*
    This method creates a new node with data and sets next to NULL
    @param data: data to set in the Node
    */
    Node* create_node(int data)
    {
        Node* new_node = new Node();
        new_node->data = data;
        new_node->next = NULL;
        return new_node;
    }
    /*
    Method to print the nodes of the linked list.
    */
   void print_list()
   {
       Node* temp = head;
       cout << "[ ";
       if (temp == NULL)
       {
            cout << "]" << endl;
            return;
       }
       do 
       {    
           cout << temp->data << " ";
           temp = temp->next;
       } while(temp != head);
       cout << "]" << endl;
       return;
   }
    /*
    This method appends the node to the end of the CircularLinkedList.
    @param data: data to be inserted in the list.
    */
    void append_node(int data)
    {
        // new node with data;
        Node* new_node = create_node(data);
        // Set next to point to head as it will be at last and always point to the head.
        if (head == NULL) 
        {
            new_node->next = new_node;
            head = new_node;
            return;
        }
        // to store the last element in the list
        Node* last = head;
        new_node->next = head;
        do
        {
            last = last->next;
        } while (last->next != head);

        last->next = new_node;
        return;
    }

    /*
    This pushes a node at the beginning of the list.
    @param data: data to be added to the node.
    */
    void push(int data)
    {
        /*
        Algorithm For Pushing a node to the beginning of CircularLinkedList
        1. Allocate a node with data.
        2. set the next of the node to point to the head node.
        3. if head node is null, point the next of new node to itself and point the head to the new pointer, and return;
        4. if head is not null, traverse to find the last node and set its next to new node.
        5. lastly point the head to the new node.
        */

       // New node with the given data.
        Node* new_node = new Node(data);
        Node* temp = head; // used in tracking the last element
        new_node->next = head; // default action for the first element should point to the previous head.
        if (head == NULL)
        {
            new_node->next = new_node;
            return;
        }

        while (temp->next != head)
            temp = temp->next;
        temp->next = new_node;

        head = new_node;
    }

    /*
    This method inserts a node with the provided data, after the first occourence of given key in the list.
    @param data: data to be inserted.
    @param key: the node in the list after which the data is to be inserted.
    */
   void insert_after(int key, int data)
   {
        Node* new_node = new Node(data);
        Node* node_with_key = node_exists(key);
        if (node_with_key == NULL)
        {
            cout << "Node doesnot exist." << endl;
            return;
        }
        new_node->next = node_with_key->next;
        node_with_key->next = new_node;
   }

   /*
   Delete a node from the beginning of the list.
   */
    void delete_node() 
    {
        Node *temp = head, *last = head;
        // If the list is empty and you try the deletion operation.
        if (temp == NULL)
        {
            cout << "Underflow" << endl;
            return;
        }
        // if the list has just one node i.e. head node
        if (temp->next == head)
        {
            head = NULL;
            delete(head);
        }
        else 
        {
            temp = head;
            last = head;
            while (last->next != head)
            {
                last = last->next;
            }
            head = temp->next;
            last->next = temp->next;
        }
        delete(temp);
    }
};

int main()
{
    CircularLinkedList circularLinkedList(100);
    circularLinkedList.append_node(10);
    circularLinkedList.append_node(20);
    circularLinkedList.append_node(8);
    circularLinkedList.append_node(1);
    circularLinkedList.push(1010);
    circularLinkedList.push(20);
    circularLinkedList.insert_after(10, 11);
    circularLinkedList.insert_after(10, 12);
    circularLinkedList.delete_node();
    circularLinkedList.print_list();
    return 0;
}