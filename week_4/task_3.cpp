#include <iostream>
using namespace std;

class Queue {
private:
    int frontIndex, rearIndex, capacity;
    int* arr;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        frontIndex = -1;
        rearIndex = -1;
    }

    bool isEmpty() {
        return frontIndex == -1;
    }

    bool isFull() {
        return (rearIndex + 1) % capacity == frontIndex;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Full!\n";
            return;
        }

        if (isEmpty()) {
            frontIndex = 0;
            rearIndex = 0;
        }
        else {
            rearIndex = (rearIndex + 1) % capacity;
        }

        arr[rearIndex] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Empty!\n";
            return -1;
        }

        int value = arr[frontIndex];

        if (frontIndex == rearIndex) {
            frontIndex = rearIndex = -1;
        }
        else {
            frontIndex = (frontIndex + 1) % capacity;
        }

        return value;
    }

    int size() {
        return rearIndex - frontIndex + 1;
    }

    void display() {
        for (int i = frontIndex; i <= rearIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Queue() {
        delete[] arr;
    }
};

class Stack {
private:
    int topIndex, capacity;
    int* arr;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    void push(int value) {
        arr[++topIndex] = value;
    }

    int pop() {
        return arr[topIndex--];
    }

    ~Stack() {
        delete[] arr;
    }
};
void reverseK(Queue& q, int K) {
    int n = q.size();
    if (K <= 1 || K > n) {
        return;
    }

    Stack s(K);
    for (int i = 0; i < K; i++) {
        s.push(q.dequeue());
    }
    while (!s.isEmpty()) {
        q.enqueue(s.pop());
    }
    for (int i = 0; i < n - K; i++) {
        q.enqueue(q.dequeue());
    }
}

int main() {
    int n, value, K;

    cout << "enter number of elements: ";
    cin >> n;
    Queue q(n);

    cout << "enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enqueue(value);
    }

    cout << "original queue: ";
    q.display();
    cout << "enter K: ";
    cin >> K;

    reverseK(q, K);
    cout << "updated Queue: ";
    q.display();

    return 0;
}