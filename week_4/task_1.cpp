#include<iostream>
#include <string>
using namespace std;

template <typename T>
class AbstractQueue {
public:
	virtual void enQueue(T value) = 0;
	virtual T deQueue() = 0;
	virtual T front() const = 0;
	virtual bool isEmpty() const = 0;
	virtual bool isFull() const = 0;
	virtual ~AbstractQueue() {}
};
template <typename T>
class myQueue :public AbstractQueue<T> {
private:
	int capacity;
	int frontIndex;
	int rearIndex;
	T* arr;
public:
	myQueue(int size) {
		capacity = size;
		arr = new T[capacity];
		frontIndex = 0;
		rearIndex = -1;
	}
	~myQueue() {
		delete[] arr;
}
	bool isEmpty() const {
		return frontIndex > rearIndex;
	}
	bool isFull() const {
		return rearIndex == capacity - 1;
	}
	void enQueue(T value) {
		if (isFull()) {
			cout << "Queue overFlow...!" << endl;
			return;
		}
		arr[++rearIndex] = value;
	}
	T deQueue() {
		if (isEmpty()) {
			cout << "Queue underFlow...!" << endl;
			return T();
		}
		return arr[frontIndex++];
	}
	T front()const {
		if (isEmpty()) {
			cout << "Queue is Empty...!";
		}
		return arr[frontIndex];
	}
	void display() const {
		if (isEmpty()) {
			cout << "Queue is Empty...!" << endl;
			return;
		}
		cout << "Queue elements: ";
		for (int i = frontIndex; i <= rearIndex; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};
int main() {
	int size;
	cout << "enter queue size: ";
	cin >> size;

	myQueue<int> q(size);
	int choice, value;

	do {
		cout << "1. enqueue\n";
		cout << "2. dequeue\n";
		cout << "3. front\n";
		cout << "4. display\n";
		cout << "5. check Empty\n";
		cout << "6. check Full\n";
		cout << "0. exit\n";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "enter value: ";
			cin >> value;
			q.enQueue(value);
			break;

		case 2:
			cout << "removed: " << q.deQueue() << endl;
			break;

		case 3:
			cout << "front element: " << q.front() << endl;
			break;

		case 4:
			q.display();
			break;

		case 5:
			cout << (q.isEmpty() ? "queue is empty\n" : "queue is not empty\n");
			break;

		case 6:
			cout << (q.isFull() ? "queue is full\n" : "queue is not full\n");
			break;

		case 0:
			cout << "exiting...\n";
			break;

		default:
			cout << "invalid choice!\n";
		}

	} while (choice != 0);

	return 0;
}