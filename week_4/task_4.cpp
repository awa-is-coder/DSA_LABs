#include <iostream>
using namespace std;

class Queue {
private:
    int arr[100];
    int frontIndex, rearIndex;

public:
    Queue() {
        frontIndex = -1;
        rearIndex = -1;
    }

    bool isEmpty() {
        return (frontIndex == -1 || frontIndex > rearIndex);
    }
    void enqueue(int ticket_id) {
        if (rearIndex == 99) {
            cout << "queue is full. " << endl;
            return;
        }

        if (frontIndex == -1)
            frontIndex = 0;
        rearIndex++;
        arr[rearIndex] = ticket_id;

        cout << "ticket " << ticket_id << " added. " << endl;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "no ticket to resolve. " << endl;
            return;
        }

        cout << "resolving ticket: " << arr[frontIndex] << endl;
        frontIndex++;
    }

    void front() {
        if (isEmpty()) {
            cout << "queue is empty. " << endl;
            return;
        }

        cout << "next ticket: " << arr[frontIndex] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "no pending tickets. " << endl;
            return;
        }

        cout << "pending tickets: ";
        for (int i = frontIndex; i <= rearIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Queue q;
    int choice, ticket_id;

    do {
        cout << "1. add Ticket\n";
        cout << "2. resolve Ticket\n";
        cout << "3. view Next Ticket\n";
        cout << "4. display Tickets\n";
        cout << "5. exit\n";
        cout << "enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "enter 4-digit ticket ID: ";
            cin >> ticket_id;
            q.enqueue(ticket_id);
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