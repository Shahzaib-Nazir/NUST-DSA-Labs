// Name: Muhammad Shahzaib Nazir
// Reg No: 543983
// Section: D

// Task 2 - stack using a linked list
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;

void push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;   // new node goes on the head
    top = newNode;      // top points to new value
    cout << "Pushed " << value << endl;
}

void pop() {
    if (top == nullptr) {
        cout << "Stack is empty, cannot pop" << endl;
        return;
    }
    Node* temp = top;       // temporary pointer to top
    cout << "Popped " << temp->data << endl;
    top = top->next;        // move top down
    delete temp;
}

void peek() {
    if (top == nullptr) {
        cout << "Stack is empty, nothing to peek" << endl;
        return;
    }
    cout << "Top is " << top->data << endl;
}

void display() {
    if (top == nullptr) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack (top to bottom): ";
    Node* temp = top;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    push(5);
    push(15);
    push(25);
    display();
    pop();
    peek();
    display();

    // empty pop test
    pop();
    pop();
    pop();

    // free whatever is left
    push(7);
    push(8);
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    display();
    return 0;
}
