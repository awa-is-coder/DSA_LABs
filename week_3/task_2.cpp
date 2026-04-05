//#include<iostream>
//using namespace std;
//
//template <typename T>
//class AbstractStack {
//public:
//	virtual void push(T value) = 0;
//	virtual T pop() = 0;
//	virtual T top()const = 0;
//	virtual bool isFull()const = 0;
//	virtual bool isEmpty()const = 0;
//	virtual ~AbstractStack() {}
//};
//template <typename T>
//class myStack :public AbstractStack<T> {
//private:
//	int capacity;
//	int topIndex;
//	T* arr;
//	T* minArr;
//	int minTop;
//public:
//	myStack(int size) {
//		capacity = size;
//		arr = new T[capacity];
//		topIndex = -1;
//		minArr = new T[capacity];
//		minTop = -1;
//	}
//	~myStack() {
//		delete[] arr;
//		delete[]minArr;
//	}
//	bool isEmpty()const {
//		return topIndex == -1;
//	}
//	bool isFull()const{
//		return topIndex == capacity - 1;
//	}
//
//	void push(T Value) {
//		if (isFull()) {
//			cout << "stack is overflow...!" << endl;
//			return;
//		}
//		arr[++topIndex] = Value;
//		if (minTop == -1 || Value <= minArr[minTop]) {
//			minArr[++minTop]=Value;
//		}
//	}
//	T pop() {
//		if (isEmpty()) {
//			cout << "Stack UnderFlow...!\n";
//			return T();
//		}
//		T popped = arr[topIndex--];
//		if (popped == minArr[minTop]) {
//			minTop--;
//		}
//		return popped;
//	}
//	T top()const {
//		if (isEmpty()) {
//			cout << "stack is Empty...!\n";
//			return T();
//		}
//		return arr[topIndex];
//	}
//	T getMin()const {
//		if (minTop == -1) {
//			cout << "Stack is Empty!" << endl;
//			return T();
//		}
//		return minArr[minTop];
//	}
//	void display()const {
//		if (isEmpty()) {
//			cout << "stack is Empty...!\n";
//			return;
//		}
//		cout << "stack elements:";
//		for (int i = topIndex; i >= 0; i--) {
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//	}
//};
//int main() {
//	int size;
//	cout << "Enter stack Size: ";
//	cin >> size;
//	myStack<int> s(size);
//	int choice, value;
//	do {
//		cout << "1.Push" << endl;
//		cout << "2.Pop" << endl;
//		cout << "3.Top" << endl;
//		cout << "4.Display" << endl;
//		cout << "5.Check Empty" << endl;
//		cout << "6.check Full" << endl;
//		cout << "7.get Min" << endl;
//		cout << "0.Exit" << endl;
//		cin >> choice;
//		switch (choice) {
//		case 1:
//			cout << "Enter value: ";
//			cin >> value;
//			s.push(value);
//			break;
//
//		case 2:
//			cout << "Popped: " << s.pop() << endl;
//			break;
//
//		case 3:
//			cout << "Top element: " << s.top() << endl;
//			break;
//
//		case 4:
//			s.display();
//			break;
//
//		case 5:
//			cout << (s.isEmpty() ? "Stack is Empty\n" : "Stack is NOT Empty\n");
//			break;
//
//		case 6:
//			cout << (s.isFull() ? "Stack is Full\n" : "Stack is NOT Full\n");
//			break;
//		case 7:
//			cout << "minimum:" << s.getMin() << endl;
//			break;
//		case 0:
//			cout << "Exiting...\n";
//			break;
//
//		default:
//			cout << "Invalid choice!\n";
//		}
//
//	} while (choice != 0);
//
//	return 0;
//}
