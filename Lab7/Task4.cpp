// Name: Muhammad Shahzaib Nazir
// Reg No: 543983
// Section: D

#include <iostream>
using namespace std;

// same circular queue as Task 3, just quieter so the turns are easy to read
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

    int Peek() {
        // check if the queue is empty
        if (IsEmpty()) {
            cout << "Queue is empty, nothing to peek" << endl;
            return -1;
        }
        return arr[front];      // return front element
    }

    // get the size of the queue
    int Size() {
        if (IsEmpty()) {
            return 0;
        }
        return (rear - front + 5) % 5 + 1;
    }

    void Display() {
        // check if the queue is empty
        if (IsEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        // output the queue front to back
        cout << "Queue: ";
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

    // serve the front student then send them to the back
    void RotateTurn() {
        // check if the queue is empty
        if (IsEmpty()) {
            cout << "No students waiting, nobody to serve" << endl;
            return;
        }
        int id = Peek();    // store front student in id
        Dequeue();
        Enqueue(id);        
        cout << "Student " << id << " had their turn" << endl;
        Display();
        cout << "Students in queue: " << Size() << endl;    // students in queue
    }
};

int main() {
    CircularQueue q;

    q.Enqueue(101);
    q.Enqueue(102);
    q.Enqueue(103);
    cout << "Starting line-up" << endl;
    q.Display();
    cout << endl;

    // five turns in a loop
    for (int turn = 1; turn <= 5; turn++) {
        cout << "Turn " << turn << endl;
        q.RotateTurn();
        cout << endl;
    }

    // empty queue
    cout << "Empty queue test" << endl;
    CircularQueue empty;
    empty.RotateTurn();
    cout << endl;

    // only one student
    cout << "One student test" << endl;
    CircularQueue single;
    single.Enqueue(201);
    single.RotateTurn();

    return 0;
}