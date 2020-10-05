#include<iostream>
using namespace std;

class CircularQueue {

	public:
	int front, rear;

	int size, *arr;

	CircularQueue(int s) {
		// Initialized front and rear to -1
		front = rear = -1;
		size = s;
		arr = new int[s];
	}

	void enqueue(int val);
	int dequeue();
	void displayQueue();
};

// inserting an element to the queue
void CircularQueue::enqueue(int val) {

	// Check if queue is full
	if ((front == 0 && rear == size - 1) || (rear == (front - 1))) {

		cout << "\nQueue is full";
		return;
	}
	else if (front == -1) {
		front = rear = 0;
		arr[rear] = val;
    cout << val << " is enqueued!";
  }
  else {
		rear++;
		arr[rear] = val;
    cout << val << " is enqueued!" << endl;
  }
}

// Removing the element from the queue
int CircularQueue::dequeue() {

	if (front == -1) {
    cout << "\n Queue is empty" << endl;
    // return NULL;
    return -1;
  }

  int deletedData = arr[front];
	arr[front] = -1;

	if (front == rear) {
		front = -1;
		rear = -1;
	}
	else if (front == size - 1) {
		front = 0;
	}
	else 
		front++;

	return deletedData;
}

void CircularQueue::displayQueue() {

	if (front == -1) {
		cout << "Queue is empty"<< endl;
		return;
	}

	cout << "\nElements in Circular Queue are:" << endl;

	if (rear >= front) {
		for(int i = front; i <= rear; i++){
			cout << arr[i] << endl;
		}
	}
	else {
		for (int i = front; i < size; i++) 
            cout << arr[i] << endl; 
  
        for (int i = 0; i <= rear; i++) 
            cout << arr[i] << endl; 
	}
}

int main() 
{ 
    CircularQueue q(5);
    int ch;
    bool doExit = false;

    do {
      cout << "\nCirular queue\n" << endl;
      cout << "1. Enqueue item" << endl;
      cout << "2. Dequeue item" << endl;
      cout << "3. Display Queue" << endl;
      cout << "4. Quit (Press any key to Quit)" << endl;
      cout << "Please enter your choice: ";
      cin >> ch;

      switch (ch)
      {
      case 1:
        {
          int nNum;
          cout << "Enter item to enqueue: ";
          cin >> nNum;
          q.enqueue(nNum);
          doExit = false;
          break;
        }

      case 2:
          {
        if (q.dequeue() < 0) {
          cout << "\nNothing dequeued! \n"
               << endl;
          doExit = false;
          break;
        }
        cout << q.dequeue() << " is dequeued!";
        doExit = false;
      break;
          }
      case 3:{
        q.displayQueue();
        doExit = false;
        break;}

      default:{
        doExit = true;
        break;
        }
      }

    } while (!doExit);

    
    return 0; 
} 