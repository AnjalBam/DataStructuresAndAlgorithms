# Stack

The Stack is a linear Data Structure which follows a particular order in which the operations are performed. The order is **Last In First Out _(LIFO)_/First in Last Out _(FILO)_**.

### Basic Operations

- Push: adds an item in the stack
- Peek: See or return the topmost element in the stack
- Pop: remove and return the topmost elemet from the stack
- isEmpty: returns _true_ if stack is empty else _false_

#### **Example:**

The practical example can be the stack of homeworks on the table to be checked by the teacher. The topmost book is picked first by the teacher and is checked first. There are a lot of stack implementation in the real life.

#### **Time Complexities of operations on stack**

The operations push(), pop() and peek() all have the time complexities as O(1) since we do not use any kind of loop in the operation.

#### **Application of _Stack_**:

- Balancing of Symbols
- Infix to prefix/ Infix to postfix
- Undo redo changes in various softwares.
- Forward backward features in modern browsers
- In various algorithms like _Tower Of Hanoi_, _Tree traversals,_ etc.

> There are various other problems that can be solved via stack implementation.

#### **Implementation**:

The stack can be implemented in two different ways:

- Using array
  - **pros**: They are easy to implement and memory is also saved as no pointers are used.
  - **cons**: It is not dynamic that means the arrays cannot grow or shrink as per the needs in runtime.
- Using Linked List
  - **pros**: Liked lists are dynamic and the stack can grow or shrink as per the need in the runtime.
  - **cons**: Requirement of extra memory on the runtime as pointers are involved.
