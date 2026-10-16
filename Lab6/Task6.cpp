// Name: Muhammad Shahzaib Nazir
// Reg No: 543983
// Section: D

// Task 6 - customer service queue (linear queue, size 5)
// Note: once rear reaches 4 no one can be added until the queue is empty and resets
#include <iostream>
using namespace std;

const int SIZE = 5;
int items[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        cout << "Queue is full, cannot add token " << value << endl;
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    items[rear] = value;
    cout << "Customer with token " << value << " added" << endl;
}

void dequeue() {
    if (front == -1) {
        cout << "No customers to serve" << endl;
        return;
    }
    cout << "Serving token " << items[front] << endl;
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;        // dequeue the customer at the front
    }
}

void peekFront() {
    if (front == -1) {
        cout << "No customers waiting" << endl;
        return;
    }
    cout << "Next customer is token " << items[front] << endl;
}

void display() {
    if (front == -1) {
        cout << "No customers waiting" << endl;
        return;
    }
    cout << "Waiting tokens: ";
    for (int i = front; i <= rear; i++) {
        cout << items[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, token;

    do {
        cout << endl;
        cout << "1. Add customer" << endl;
        cout << "2. Serve next" << endl;
        cout << "3. View next" << endl;
        cout << "4. Display queue" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter token number: ";
            cin >> token;
            enqueue(token);
        } else if (choice == 2) {
            dequeue();
        } else if (choice == 3) {
            peekFront();
        } else if (choice == 4) {
            display();
        } else if (choice == 5) {
            cout << "Goodbye" << endl;
        } else {
            cout << "Invalid choice, try again" << endl;
        }
    } while (choice != 5);

    return 0;
}
