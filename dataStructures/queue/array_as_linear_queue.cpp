#include <iostream>


using namespace std;

#define MAX 10 


class Queue {
	
public:
	int nFront, nRear;

	int queue[MAX];

	
	Queue() {
		// nFront = nRear = -1 initial condition
		nFront = nRear = -1;	
	}

// Take an item to queue
	void enqueue(int x) {

		// Queue full condition 
		if (nRear == MAX - 1) {
			cout << "Queue Overflow" << endl;
		}
		// checking if the queue is empty
		// if empty assign nFront = nRear = 0
		// this means after insertion only one element is present
		else if (nFront == -1 && nRear == -1) {
			nFront = nRear = 0;
			queue[nRear] = x;
			cout <<  x << " is Queued\n\n" << endl;
		}
		else {
			nRear++;
			queue[nRear] = x;
			cout  << x << " is Queued\n\n" << endl;
		}
	}

	// Dequeue: remove an element from quieie 
	void dequeue() {
		// To store the deleted item for display
		int nDeleted;

		// condition to check empty 
		if (nRear == -1) {
			cout << "Queue Underflow";
		}
		// Only an item is present;
		else if (nFront == 0 && nRear == 0) {
			// delete nFront most item
			nDeleted = queue[nFront];
			// Queue becomes empty
			nFront = nRear = -1;
			cout << nDeleted << " is dequeued."  << endl;
		}
		else {
			nDeleted = queue[nFront];
			nFront++;
			cout  << nDeleted << " is dequeued." << endl;
		}
	}
	// Display function 
	void seeQueue() {
		if (nFront == -1) {
			cout << "Queue is empty" << endl;
		}
		else {
			cout << "Queue items:\n";
			for (int i = nFront; i <= nRear; i++){
				cout << queue[i] << " " << endl;
			}
			cout << endl;
		}
	}

};


int main() {
	int ch;
	Queue q;
	do {
	cout << "Make your choice:" << endl;
	cout << "1.Enqueue into the data. " << endl;
	cout << "2.Deque the data. " << endl;
	cout << "3.Display into the data. " << endl;
	cout << "4. Quit" << endl;
	cin >> ch;

		switch(ch){

			case 1:{
				int val;
				cout << "Enter the value to enqueue.." << endl;
				cin >> val;
				q.enqueue(val);
				break;
			}

			case 2: {
				cout << "Unqueueing data..." << endl;
				q.dequeue();
				break;
			}

			case 3: {
				cout << "Viewing the queue..." << endl;
				q.seeQueue();
				break;
			}
			default: {
				cout << "Please make a valid choice!"<< endl;
				break;
			}
		}
	}while(ch!=4);
}