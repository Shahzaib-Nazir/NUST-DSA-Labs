// Name: Muhammad Shahzaib Nazir
// Reg No: 543983
// Section: D

// Task 5 - removing from a linear queue (Task 4 + dequeue and peekFront)
#include <iostream>
using namespace std;

const int SIZE = 5;
int items[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        cout << "Queue is full, cannot insert " << value << endl;
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    items[rear] = value;
    cout << "Inserted " << value << endl;
}

void dequeue() {
    if (front == -1) {
        cout << "Queue is empty, cannot remove" << endl;
        return;
    }
    cout << "Removed " << items[front] << endl;
    if (front == rear) {
        // last item, reset both
        front = -1;
        rear = -1;
    } else {
        front++;
    }
}

void peekFront() {
    if (front == -1) {
        cout << "Queue is empty, nothing to peek" << endl;
        return;
    }
    cout << "Front is " << items[front] << endl;
}

void display() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue (front to rear): ";
    for (int i = front; i <= rear; i++) {
        cout << items[i] << " ";
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    peekFront();
    display();

    // remove the rest, then try once more
    dequeue();
    dequeue();
    dequeue();
    display();

    // check it works after reset
    enqueue(40);
    display();
    peekFront();
    return 0;
}
