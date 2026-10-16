// Name: Muhammad Shahzaib Nazir
// Reg No: 543983
// Section: D

// Task 4 - inserting into a linear queue
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
        front = 0;   // first insertion
    }
    rear++;
    items[rear] = value;    // insert value in the rear
    cout << "Inserted " << value << endl;
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
    display();   // empty display test

    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    // fill it up, then one more
    enqueue(40);
    enqueue(50);
    display();
    enqueue(60);
    return 0;
}
