// Name: Muhammad Shahzaib Nazir
// Reg No: 543983
// Section: D
// Lab 05 - Task 5: Implementing a stack using an array

#include <iostream>
using namespace std;

class ArrayStack {
private:
    int items[5];
    int top;

public:
    ArrayStack() {
        top = -1;
    }

    bool IsEmpty() {
        return top == -1;
    }

    bool IsFull() {
        return top == 4;
    }

    // adds a value on top, refuses if the stack is already full (overflow)
    void Push(int value) {
        if (IsFull()) {     //if stack is full
            cout << "Overflow: stack is full, cannot push " << value << "." << endl;
            return;
        }
        top++;
        items[top] = value;     // add value
        cout << "Pushed " << value << "." << endl;
    }

    // removes the top value and shows it, refuses if the stack is empty (underflow)
    void Pop() {
        if (IsEmpty()) {
            cout << "Underflow: stack is empty, nothing to pop." << endl;
            return;
        }
        cout << "Popped " << items[top] << "." << endl;
        top--;
    }

    // shows the top value without removing it
    void Peek() {
        if (IsEmpty()) {
            cout << "Underflow: stack is empty, nothing to peek." << endl;
            return;
        }
        cout << "Top is " << items[top] << "." << endl;
    }

    // prints the stack from top to bottom
    void Display() {
        if (IsEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << items[i];
            if (i > 0) {
                cout << ", ";
            }
        }
        cout << endl;
    }
};

int main() {
    ArrayStack stack;

    cout << "--- Push 10 to 50 ---" << endl;
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Push(50);
    stack.Display();

    cout << "--- Sixth push (should be rejected) ---" << endl;
    stack.Push(60);
    stack.Display();

    cout << "--- Pop then peek ---" << endl;
    stack.Pop();
    stack.Peek();
    stack.Display();

    cout << "--- Empty the stack ---" << endl;
    while (!stack.IsEmpty()) {
        stack.Pop();
    }
    stack.Display();

    cout << "--- Pop and peek on empty stack ---" << endl;
    stack.Pop();
    stack.Peek();

    return 0;
}
