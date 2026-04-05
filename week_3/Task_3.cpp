//#include <iostream>
//using namespace std;
//
//class myCarStack {
//private:
//    int capacity;
//    int topIndex;
//    int* arr;
//
//public:
//    myCarStack(int size) {
//        capacity = size;
//        arr = new int[capacity];
//        topIndex = -1;
//    }
//    ~myCarStack() {
//        delete[] arr;
//    }
//    bool isEmpty() {
//        return topIndex == -1;
//    }
//    bool isFull() {
//        return topIndex == capacity - 1;
//    }
//    void push(int car) {
//        if (isFull()) {
//            cout << "Parking Full!\n";
//            return;
//        }
//        arr[++topIndex] = car;
//        cout << "Car " << car << " parked.\n";
//    }
//    int pop() {
//        if (isEmpty()) {
//            cout << "No cars to remove!\n";
//            return -1;
//        }
//        return arr[topIndex--];
//    }
//    int top() {
//        if (isEmpty()) return -1;
//        return arr[topIndex];
//    }
//    int getSize() {
//        return topIndex + 1;
//    }
//    bool search(int car) {
//        for (int i = 0; i <= topIndex; i++) {
//            if (arr[i] == car)
//                return true;
//        }
//        return false;
//    }
//    void display() {
//        if (isEmpty()) {
//            cout << "Parking is empty!\n";
//            return;
//        }
//        cout << "Parked Cars: ";
//        for (int i = topIndex; i >= 0; i--) {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
//    }
//    void removeCar(int car) {
//        if (isEmpty()) {
//            cout << "Parking is empty!\n";
//            return;
//        }
//
//        myCarStack temp(capacity);
//
//        bool found = false;
//        while (!isEmpty()) {
//            if (top() == car) {
//                pop();
//                cout << "Car " << car << " removed.\n";
//                found = true;
//                break;
//            }
//            else {
//                temp.push(pop());
//            }
//        }
//        while (!temp.isEmpty()) {
//            push(temp.pop());
//        }
//        if (!found) {
//            cout << "Car not found!\n";
//        }
//    }
//};
//int main() {
//    myCarStack parking(8);
//
//    int choice, car;
//
//    do {
//        cout << "1. Park Car\n";
//        cout << "2. Remove Car\n";
//        cout << "3. Show Top Car\n";
//        cout << "4. Show All Cars\n";
//        cout << "5. Total Cars\n";
//        cout << "6. Search Car\n";
//        cout << "0. Exit\n";
//
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            cout << "enter car number: ";
//            cin >> car;
//            parking.push(car);
//            break;
//
//        case 2:
//            cout << "enter car number to remove: ";
//            cin >> car;
//            parking.removeCar(car);
//            break;
//
//        case 3:
//            cout << "top car: " << parking.top() << endl;
//            break;
//
//        case 4:
//            parking.display();
//            break;
//
//        case 5:
//            cout << "total cars: " << parking.getSize() << endl;
//            break;
//
//        case 6:
//            cout << "enter car to search: ";
//            cin >> car;
//            if (parking.search(car))
//                cout << "car found!\n";
//            else
//                cout << "car not found!\n";
//            break;
//
//        case 0:
//            cout << "exiting...\n";
//            break;
//
//        default:
//            cout << "invalid choice!\n";
//        }
//
//    } while (choice != 0);
//
//    return 0;
//}