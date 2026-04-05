#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
    string arr[100];
    int frontIndex, rearIndex;

public:
    Queue() {
        frontIndex = -1;
        rearIndex = -1;
    }

    bool isEmpty() {
        return (frontIndex == -1 || frontIndex > rearIndex);
    }
    void enqueue(string document_name) {
        if (rearIndex == 99) {
            cout << "queue is full." << endl;
            return;
        }

        if (frontIndex == -1)
            frontIndex = 0;

        rearIndex++;
        arr[rearIndex] = document_name;

        cout << "document \"" << document_name << "\" added to print queue." << endl;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "no document to print." << endl;
            return;
        }

        cout << "printing document: " << arr[frontIndex] << endl;
        frontIndex++;
    }

    void front() {
        if (isEmpty()) {
            cout << "queue is empty." << endl;
            return;
        }

        cout << "next document: " << arr[frontIndex] << endl;
    }
    void display() {
        if (isEmpty()) {
            cout << "No pending print jobs." << endl;
            return;
        }

        cout << "pending documents: " << endl;
        for (int i = frontIndex; i <= rearIndex; i++) {
            cout << arr[i] << " | ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice;
    string document_name;

    do {
        cout << "1. add Print Job\n";
        cout << "2. print Document\n";
        cout << "3. view Next Document\n";
        cout << "4. display All Documents\n";
        cout << "5. exit\n";
        cout << "enter choice: ";
        cin >> choice;

        cin.ignore();

        switch (choice) {
        case 1:
            cout << "enter document name: ";
            getline(cin, document_name);
            q.enqueue(document_name);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.front();
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "program ended.\n";
            break;

        default:
            cout << "invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}