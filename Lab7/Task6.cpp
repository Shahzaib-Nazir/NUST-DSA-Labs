// Name: Muhammad Shahzaib Nazir
// Reg No: 543983
// Section: D

#include <iostream>
using namespace std;

class LinkedDeque {
private:
    struct node {
        int data;
        node* next;
        node* prev;
    };

    // front and rear pointers
    node* front;
    node* rear;


public:
    LinkedDeque() {
        front = nullptr;
        rear = nullptr;
    }

    ~LinkedDeque() {
        ClearDeque();
    }

    // check if dequeue is empty
    bool IsEmpty() {
        return front == nullptr;
    }

    void InsertFront(int value) {
        // create a new node
        node* n = new node;
        n->data = value;
        n->next = nullptr;
        n->prev = nullptr;

        // check if dequeue is empty
        if (IsEmpty()) {
            front = n;
            rear = n;
        } else {
            // connect current front and n
            n->next = front;
            front->prev = n;
            front = n;      // make n new front
        }
        cout << value << " added at front" << endl;
    }

    void InsertRear(int value) {
        // create a new node
        node* n = new node;
        n->data = value;
        n->next = nullptr;
        n->prev = nullptr;

        // check if dequeue is empty
        if (IsEmpty()) {
            // new node is first node
            front = n;
            rear = n;
        } else {
            // connect current rear and n
            n->prev = rear;
            rear->next = n;
            rear = n;       // make n the new rear
        }
        cout << value << " added at rear" << endl;
    }

    void DeleteFront() {
        // check if dequeue is empty
        if (IsEmpty()) {
            cout << "Deque is empty, nothing to delete" << endl;
            return;
        }
        // temporary pointer to output
        node* temp = front;
        cout << "Deleted " << temp->data << " from front" << endl;
        front = front->next;        // move front one step back
        if (front == nullptr) {
            rear = nullptr;
        } else {
            front->prev = nullptr;
        }
        delete temp;        // delete the node
    }

    void DeleteRear() {
        // check if dequeue is empty
        if (IsEmpty()) {
            cout << "Deque is empty, nothing to delete" << endl;
            return;
        }
        // temporary pointer to output
        node* temp = rear;
        cout << "Deleted " << temp->data << " from rear" << endl;
        rear = rear->prev;
        if (rear == nullptr) {
            front = nullptr;
        } else {
            rear->next = nullptr;
        }
        delete temp;        // delete a node
    }

    void Display() {
        // check if dequeue is empty
        if (IsEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        // output the entire dequeue
        cout << "Deque: ";
        node* curr = front;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    // clear the entire dequeue front to back
    void ClearDeque() {
        while (front != nullptr) {
            node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }
};

int main() {
    LinkedDeque d;
    int choice;
    int value;

    do {
        cout << endl;
        cout << "1. Insert at front" << endl;
        cout << "2. Insert at rear" << endl;
        cout << "3. Delete from front" << endl;
        cout << "4. Delete from rear" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            d.InsertFront(value);
        } else if (choice == 2) {
            cout << "Enter value: ";
            cin >> value;
            d.InsertRear(value);
        } else if (choice == 3) {
            d.DeleteFront();
        } else if (choice == 4) {
            d.DeleteRear();
        } else if (choice == 5) {
            d.Display();
        } else if (choice == 6) {
            cout << "Clearing the deque and exiting..." << endl;
        } else {
            cout << "Invalid choice, try again" << endl;
        }
    } while (choice != 6);

    // free whatever is left
    d.ClearDeque();

    return 0;
}