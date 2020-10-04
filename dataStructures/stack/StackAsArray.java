package dataStructures.stack;

public class StackAsArray {
  private int top;
  static final int MAX = 10;
  int[] myStack = new int[MAX];

  public StackAsArray() {
    this.top = -1;
  }

  public boolean isEmpty() {
    return top < 0;
  }

  public boolean push(int nNum) {
    if (top >= MAX - 1) {
      System.out.println("Stack Overflow");
      return false;
    } else {
      myStack[++top] = nNum;
      System.out.println(nNum + " pushed to stack.");
      return true;
    }
  }

  public int pop() {
    if (isEmpty()) {
      System.out.println("Stack Underflow!");
      return -1;
    } else {
      int el = myStack[top--];
      System.out.println(el + " popped from stack.");
      return el;
    }
  }

  public int peek() {
    if (isEmpty()) {
      System.out.println("Stack Empty!!");
      return -1;
    } else {
      System.out.println(myStack[top] + " is the top element.");
      return myStack[top];
    }
  }

  public static void main(String[] args) {
    StackAsArray myStack = new StackAsArray();
    myStack.push(10);
    myStack.push(13);
    myStack.push(100);
    myStack.peek();
    myStack.pop();
  }
}
