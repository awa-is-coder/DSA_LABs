#include <iostream>
#include <string>
using namespace std;

class Package {
public:
    int id;
    string address;
    int startTime;
    int endTime;
};
class Queue {
private:
    Package arr[100];
    int frontIndex, rearIndex;

public:
    Queue() {
        frontIndex = -1;
        rearIndex = -1;
    }

    bool isEmpty() {
        return (frontIndex == -1 || frontIndex > rearIndex);
    }

    void enqueue(int id, string address, int start, int end) {
        if (rearIndex == 99) {
            cout << "queue is full." << endl;
            return;
        }

        if (frontIndex == -1)
            frontIndex = 0;
        rearIndex++;
        arr[rearIndex].id = id;
        arr[rearIndex].address = address;
        arr[rearIndex].startTime = start;
        arr[rearIndex].endTime = end;

        cout << "package " << id << " added.\n";
    }
    void timeToDeliver(int currentTime) {
        if (isEmpty()) {
            cout << "no packages.\n";
            return;
        }

        if (currentTime >= arr[frontIndex].startTime && currentTime <= arr[frontIndex].endTime) {
            cout << "package " << arr[frontIndex].id << " can be delivered now.\n";
        }
        else {
            cout << "package " << arr[frontIndex].id << " expired. skipping...\n";
            frontIndex++;
        }
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "no package to deliver." << endl;
            return;
        }

        cout << "delivering package " << arr[frontIndex].id << endl;
        frontIndex++;
    }
    void front() {
        if (isEmpty()) {
            cout << "queue is empty.\n";
            return;
        }

        cout << "front Package:\n";
        cout << "ID: " << arr[frontIndex].id << endl;
        cout << "address: " << arr[frontIndex].address << endl;
        cout << "time Window: " << arr[frontIndex].startTime
            << " - " << arr[frontIndex].endTime << endl;
    }
    void display() {
        if (isEmpty()) {
            cout << "no packages in queue.\n";
            return;
        }
        for (int i = frontIndex; i <= rearIndex; i++) {
            cout << "ID: " << arr[i].id
                << ", address: " << arr[i].address
                << ", time: " << arr[i].startTime
                << "-" << arr[i].endTime << endl;
        }
    }
};

int main() {
    Queue q;
    int choice, id, start, end, currentTime;
    string address;

    do {
        cout << "1. add Package\n";
        cout << "2. deliver Package\n";
        cout << "3. check Front Package\n";
        cout << "4. display All Packages\n";
        cout << "5. check Time To Deliver\n";
        cout << "6. exit\n";
        cout << "enter choice: ";
        cin >> choice;

        cin.ignore();

        switch (choice) {
        case 1:
            cout << "enter Package ID: ";
            cin >> id;
            cin.ignore();

            cout << "enter Address: ";
            getline(cin, address);

            cout << "enter Start Time: ";
            cin >> start;

            cout << "enter End Time: ";
            cin >> end;

            q.enqueue(id, address, start, end);
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
            cout << "enter current time: ";
            cin >> currentTime;
            q.timeToDeliver(currentTime);
            break;

        case 6:
            cout << "program ended." << endl;
            break;

        default:
            cout << "invalid choice." << endl;
        }

    } while (choice != 6);
    return 0;
}