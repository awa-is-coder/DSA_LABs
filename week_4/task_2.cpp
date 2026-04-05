#include <iostream>
using namespace std;

class QueueStacks {
private:
    static const int size = 100;
    int stack1[size], stack2[size];
    int top1, top2;

public:
    QueueStacks() {
        top1 = -1;
        top2 = -1;
    }
    void push1(int value) {
        if (top1 == size - 1) {
            cout << "overflow...!\n";
            return;
        }
        stack1[++top1] = value;
    }
    void push2(int value) {
        if (top2 == size - 1) {
            cout << "overflow...!\n";
            return;
        }
        stack2[++top2] = value;
    }
    int pop1() {
        if (top1 == -1) return -1;
        return stack1[top1--];
    }
    int pop2() {
        if (top2 == -1) return -1;
        return stack2[top2--];
    }
    void transfer() {
        while (top1 != -1) {
            push2(pop1());
        }
    }
    void enqueue(int value) {
        push1(value);
        cout << "inserted: " << value << endl;
    }
    int dequeue() {
        if (top2 == -1) {
            if (top1 == -1) {
                cout << "Queue Empty...!\n";
                return -1;
            }
            transfer();
        }
        return pop2();
    }
    int front() {
        if (top2 == -1) {
            if (top1 == -1) {
                cout << "queue empty...!\n";
                return -1;
            }
            transfer();
        }
        return stack2[top2];
    }
    void display() {
        if (top1 == -1 && top2 == -1) {
            cout << "queue Empty...!\n";
            return;
        }

        cout << "queue elements: ";
        for (int i = top2; i >= 0; i--) {
            cout << stack2[i] << " ";
        }

        for (int i = 0; i <= top1; i++) {
            cout << stack1[i] << " ";
        }

        cout << endl;
    }
};
int main() {
    QueueStacks q;

    int choice, value;
    do {
        cout << "1. enqueue\n";
        cout << "2. dequeue\n";
        cout << "3. front\n";
        cout << "4. display\n";
        cout << "0. exit\n";

        cin >> choice;
        switch (choice) {
        case 1:
            cout << "enter value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            cout << "removed: " << q.dequeue() << endl;
            break;

        case 3:
            cout << "front: " << q.front() << endl;
            break;

        case 4:
            q.display();
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