// Name: Muhammad Shahzaib Nazir
// Reg No: 543983
// Section: D
// Lab 05 - Task 6: Implementing a stack using linked nodes

#include <iostream>
using namespace std;


class LinkedStack {
private:
    struct node {
        int data;
        node* next;
    };

    node* top;

public:
    LinkedStack() {
        top = nullptr;
    }

    ~LinkedStack() {
        ClearStack();
    }

    bool IsEmpty() {
        return top == nullptr;
    }

    // adds a new node at the head, O(1)
    void Push(int value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << value << "." << endl;
    }

    // removes the head node, shows its value and deletes it, O(1)
    void Pop() {
        if (IsEmpty()) {
            cout << "Stack is empty, nothing to pop." << endl;
            return;
        }
        node* temp = top;
        cout << "Popped " << temp->data << "." << endl;
        top = top->next;    // move top first, then delete the old node
        delete temp;
    }

    // shows the top value without removing it
    void Peek() {
        if (IsEmpty()) {
            cout << "Stack is empty, nothing to peek." << endl;
            return;
        }
        cout << "Top is " << top->data << "." << endl;
    }

    // prints the stack from top to bottom
    void Display() {
        if (IsEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        node* temp = top;
        cout << "Stack (top to bottom): ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << ", ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    // deletes all remaining nodes and resets top
    void ClearStack() {
        node* temp = top;
        while (temp != nullptr) {
            node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        top = nullptr;
    }
};

int main() {
    LinkedStack stack;
    int choice;
    int value;

    do {
        cout << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to push: ";
            cin >> value;
            stack.Push(value);
        } else if (choice == 2) {
            stack.Pop();
        } else if (choice == 3) {
            stack.Peek();
        } else if (choice == 4) {
            stack.Display();
        } else if (choice == 5) {
            cout << "Exiting..." << endl;
        } else {
            cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 5);

    // free whatever is still left in the stack
    stack.ClearStack();
    return 0;
}
