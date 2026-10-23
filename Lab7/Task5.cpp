// Name: Muhammad Shahzaib Nazir
// Reg No: 543983
// Section: D

#include <iostream>
using namespace std;

class ArrayDeque {
private:
    // declare array size and pointers
    int arr[5];
    int front;
    int rear;

public:
    ArrayDeque() {
        front = -1;
        rear = -1;
    }

    // check if queue is empty
    bool IsEmpty() {
        return front == -1;
    }

    // check if queue is full
    bool IsFull() {
        return (rear + 1) % 5 == front;
    }

    void InsertFront(int value) {
        // check if queue is full
        if (IsFull()) {
            cout << "Deque is full, can't add " << value << " at front" << endl;
            return;
        }
        // check if queue is empty
        if (IsEmpty()) {
            front = 0;
            rear = 0;
        } else {
            front = (front + 5 - 1) % 5;
        }
        // add value to front
        arr[front] = value;
        cout << value << " added at front" << endl;
    }

    void InsertRear(int value) {
        // check if queue is full
        if (IsFull()) {
            cout << "Deque is full, can't add " << value << " at rear" << endl;
            return;
        }
        // check if queue is empty
        if (IsEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % 5;
        }
        // add value to the rear
        arr[rear] = value;
        cout << value << " added at rear" << endl;
    }

    void DeleteFront() {
        // check if queue is empty
        if (IsEmpty()) {
            cout << "Deque is empty, nothing to delete" << endl;
            return;
        }
        cout << "Deleted " << arr[front] << " from front" << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % 5;        // move front 
        }
    }

    void DeleteRear() {
        // check if queue is empty
        if (IsEmpty()) {
            cout << "Deque is empty, nothing to delete" << endl;
            return;
        }
        cout << "Deleted " << arr[rear] << " from rear" << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            rear = (rear + 5 - 1) % 5;      // move rear
        }
    }

    void Display() {
        // check if queue is empty
        if (IsEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        // print the entire queue front to back
        cout << "Deque: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % 5;
        }
        cout << endl;
    }
};

int main() {
    ArrayDeque d;

    d.InsertRear(20);
    d.InsertFront(10);
    d.InsertRear(30);
    d.Display();

    d.DeleteRear();
    d.DeleteFront();
    d.Display();

    d.InsertFront(5);
    d.InsertRear(30);
    d.InsertRear(40);
    d.InsertFront(1);
    d.Display();

    // full now, both should fail
    d.InsertFront(0);
    d.InsertRear(50);
    d.Display();

    // only value deleted from the front
    cout << endl << "Run 2: delete only value from front" << endl;
    ArrayDeque d2;
    d2.InsertRear(15);
    d2.DeleteFront();
    d2.Display();
    d2.DeleteFront();

    // only value deleted from the rear
    cout << endl << "Run 3: delete only value from rear" << endl;
    ArrayDeque d3;
    d3.InsertFront(25);
    d3.DeleteRear();
    d3.Display();
    d3.DeleteRear();

    return 0;
}