// Name: Muhammad Shahzaib Nazir
// Reg No: 543983
// Section: D

#include <iostream>
using namespace std;

class ArrayQueue {
private:
    // set queue size and pointers
    int arr[5];
    int front;
    int rear;

public:
    ArrayQueue() {
        front = -1;
        rear = -1;
    }

    bool IsEmpty() {
        return front == -1;
    }

    // linear queue, so rear at last index means full
    bool IsFull() {
        return rear == 4;
    }

    void Enqueue(int value) {
        // check if queue is full first
        if (IsFull()) {
            cout << "Queue is full, can't add " << value << endl;
            return;
        }
        // check if queue is empty
        if (IsEmpty()) {
            front = 0;
        }
        // add value
        rear++;
        arr[rear] = value;

        cout << value << " added to the queue" << endl;
    }

    void Dequeue() {
        // check if queue is empty
        if (IsEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Removed " << arr[front] << " from the queue" << endl;
        if (front == rear) {
            // that was the last element so reset
            front = -1;
            rear = -1;
        } else {
            // move front ahead
            front++;
        }
    }

    void Peek() {
        // check if queue is empty
        if (IsEmpty()) {
            cout << "Queue is empty, nothing to peek" << endl;
            return;
        }
        // output top value
        cout << "Front value is " << arr[front] << endl;
    }

    void Display() {
        // check if queue is empty
        if (IsEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayQueue q;       // create the queue

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.Display();

    q.Dequeue();
    q.Dequeue();

    // rear is still at the end so this should fail
    q.Enqueue(60);
    q.Display();
    q.Peek();

    // empty the queue
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Display();

    // dequeue on empty
    q.Dequeue();

    // indices were reset so this should work now
    q.Enqueue(70);
    q.Display();

    return 0;
}