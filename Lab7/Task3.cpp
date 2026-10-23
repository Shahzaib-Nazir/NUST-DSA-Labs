// Name: Muhammad Shahzaib Nazir
// Reg No: 543983
// Section: D

#include <iostream>
using namespace std;

class CircularQueue {
private:   
    // set array size and pointers
    int arr[5];
    int front;
    int rear;

public:
    // set both pointers to -1
    CircularQueue() {
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

    void Enqueue(int value) {
        // check if queue is full
        if (IsFull()) {
            cout << "Queue is full, can't add " << value << endl;
            return;
        }
        // check if queue is empty
        if (IsEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % 5;      // mod used to wrap around if needed
        }
        // add the value in the queue
        arr[rear] = value;
        cout << value << " added to the queue" << endl;
    }

    void Dequeue() {
        // check if queue is empty
        if (IsEmpty()) {
            cout << "Queue is empty, nothing to remove" << endl;
            return;
        }
        cout << "Removed " << arr[front] << " from the queue" << endl;
        // set both pointers to -1
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % 5;
        }
    }

    void Peek() {
        // check if queue is empty
        if (IsEmpty()) {
            cout << "Queue is empty, nothing to peek" << endl;
            return;
        }
        cout << "Front value is " << arr[front] << endl;
    }

    void Display() {
        // check if queue is empty
        if (IsEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        // output all the elements in the queue
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % 5;
        }
        cout << "(front = " << front << ", rear = " << rear << ")" << endl;
    }
};

int main() {
    CircularQueue q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);

    q.Dequeue();
    q.Dequeue();

    // these two use the freed spots at the start
    q.Enqueue(60);
    q.Enqueue(70);
    q.Display();

    // queue is full now
    q.Enqueue(80);
    q.Peek();

    // empty it
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Display();

    // one more dequeue on empty
    q.Dequeue();

    // insert again into the empty queue
    q.Enqueue(90);
    q.Display();

    return 0;
}