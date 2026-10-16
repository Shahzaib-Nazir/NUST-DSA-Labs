// Name: Muhammad Shahzaib Nazir
// Reg No: 543983
// Section: D

// Task 3 - reverse a word using a stack
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 20;
char stack[SIZE];       // stack of chars
int top = -1;

void push(char c) {
    if (top == SIZE - 1) {
        cout << "Stack is full" << endl;
        return;
    }
    top++;
    stack[top] = c;
}

char pop() {
    if (top == -1) {
        return '\0';
    }
    char c = stack[top];
    top--;
    return c;
}

int main() {
    string word;
    cout << "Enter a word (max 20 letters): ";
    cin >> word;

    // check length before pushing
    if (word.length() > 20) {
        cout << "Word is too long" << endl;
        return 0;
    }

    int len = word.length();
    for (int i = 0; i < len; i++) {
        push(word[i]);
    }

    cout << "Reversed: ";
    while (top != -1) {
        cout << pop();
    }
    cout << endl;
    return 0;
}