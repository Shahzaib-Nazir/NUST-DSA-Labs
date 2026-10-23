// Name: Muhammad Shahzaib Nazir
// Reg No: 543983
// Section: D

#include <iostream>
using namespace std;

class LinkedQueue {
private:
    struct node {
        int data;
        node* next;
    };

    node* front;
    node* rear;

public:
    LinkedQueue() {
        front = nullptr;
        rear = nullptr;
    }

    ~LinkedQueue() {
        ClearQueue();
    }

    bool IsEmpty() {
        return front == nullptr;
    }

    void Enqueue(int value) {
        // create a new node
        node* n = new node;
        n->data = value;
        n->next = nullptr;      // set next to nullptr for now

        // check if empty (first node added)
        if (IsEmpty()) {
            front = n;
            rear = n;
        } else {
            // add n as last node and set n to new rear
            rear->next = n;
            rear = n;
        }
        cout << value << " added to the queue" << endl;
    }

    void Dequeue() {
        // check if it is empty
        if (IsEmpty()) {
            cout << "Queue is empty, nothing to remove" << endl;
            return;
        }
        // create a temporary pointer to output removed data (front node)
        node* temp = front;
        cout << "Removed " << temp->data << " from the queue" << endl;
        front = front->next;        // move front back
        if (front == nullptr) {
            // last node gone, rear must reset too
            rear = nullptr;
        }
        delete temp;        // delete that node
    }

    void Peek() {
        // check if queue is empty
        if (IsEmpty()) {
            cout << "Queue is empty, nothing to peek" << endl;
            return;
        }
        // output value
        cout << "Front value is " << front->data << endl;
    }

    void Display() {
        // check if queue is empty
        if (IsEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue: ";
        // current pointer set to front for traversing
        node* curr = front;
        while (curr != nullptr) {
            // output the queue one by one (front to rear)
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    
    // delete all nodes and set both pointer to nullptr
    void ClearQueue() {
        while (front != nullptr) {
            node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }
};

int main() {
    LinkedQueue q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    q.Dequeue();
    q.Display();
    q.Peek();

    // remove everything
    q.Dequeue();
    q.Dequeue();

    // empty queue tests
    q.Dequeue();
    q.Peek();
    q.Display();

    // insert after it became empty
    q.Enqueue(40);
    q.Display();

    // removing the only node
    q.Dequeue();
    q.Display();

    // leave a few nodes and clear before exit
    q.Enqueue(50);
    q.Enqueue(60);
    q.Display();

    q.ClearQueue();
    cout << "Queue cleared before exit" << endl;
    q.Display();

    return 0;
}