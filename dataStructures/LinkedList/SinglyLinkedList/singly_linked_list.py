class Node:
    def __init__(self):
        self.data = None
        self.next = None


class SinglyLinkedList:
    head = None;

    def __init__(self, value):
        my_head = Node()
        my_head.data = value
        my_head.next = None

        self.head = my_head

    # print the list;
    def print_list(self):
        temp = self.head
        print('[ ', end='')
        while temp is not None:
            print(temp.data," ", end='')
            temp = temp.next
        print(']')

    @staticmethod
    def get_data():
        return int(input("Enter data you want to insert: "))

    # insert at the beginning of list
    def push(self):
        """
        Appends the data at the first or the beginning of the list.
        /*
        * Steps:
        *   - Get data
        *   - Allocate a new node
        *   - set value to new node;
        *   - set next of new node to current head
        *   - set head of the list as new node
        */
        """

        # 1. Get data
        data = self.get_data()
        
        # 2. Allocate new node
        new_node = Node()

        # 3. Set new data
        new_node.data = data

        # 4. set next of new node to current head
        new_node.next = self.head

        # 5. set the head sas this new node
        self.head = new_node

    # insert at the end of the list
    def append(self):
        """
        Inserts the element to the end of the list.
        /*
        * Steps:
        *   - get data;
        *   - allocate new node;
        *   - set data and next as null in new node;
        *   - traverse to get last node;
        *   - set last node to point the new node;
        */
        """

        # 1. get data
        data = self.get_data()

        # 2. allocate new node
        new_node = Node()

        # 3. assign data as input data and next as null 
        new_node.data = data
        new_node.next = None
        
        # 4. find last element
        if self.head is None:
            self.head = new_node
            return

        last = self.head
        while last.next is not None:
            last = last.next
        
        # 5. point last el next to point new node
        last.next = new_node

    # insert after the given value
    def insert_after(self, value):
        """
        Insert the element after the first value that matches the given value
        /*
       * Steps:
       * 1. get data
       * 2. get node from the linked list
       * 3. Allocate a new node
       * 4. set data
       * 5. set new node next to prev node next
       * 6. set prev node next to new node;
       */
        """
        # 1. Get data  
        data = self.get_data()

        # 2. get the node from the linked list
        prev_node = None;
        temp = self.head
        # traverse through the list to find the node with given value
        while temp is not None:
            if temp.data == value:
                prev_node = temp
                break
            temp = temp.next
        
        # 3. Allocate new node
        new_node = Node()

        # 4. set data
        new_node.data = data

        # 5. set new node next to prev node next 
        new_node.next = prev_node.next

        # 6. set prev node next to new node
        prev_node.next = new_node

if __name__ == "__main__":
    linkedList = SinglyLinkedList(10)
    linkedList.print_list()
    linkedList.push()
    linkedList.print_list()
    linkedList.append()
    linkedList.print_list()
    value = int(input("Enter the value you want to insert after: "))

    linkedList.insert_after(value)
    linkedList.print_list()