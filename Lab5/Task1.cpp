// Name: Muhammad Shahzaib Nazir
// Reg No: 543983
// Section: D
// Lab 05 - Task 1: Creating and traversing a doubly linked list

#include <iostream>
using namespace std;

class DoublyList {
private:
    struct node {
        int data;
        node* next;
        node* prev;
    };

    node* head;
    node* tail;

public:
    DoublyList() {
        head = nullptr;
        tail = nullptr;
    }

    ~DoublyList() {
        ClearList();
    }

    // adds a new node at the end of the list using tail, so no traversal is needed
    void AddNode(int value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (head == nullptr) {
            // first node is both head and tail
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;       // add to end
            tail = newNode;     // move tail forward to new node
        }
    }

    // prints the list from head to tail
    void PrintForward() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        node* temp = head;
        cout << "Forward: ";
        while (temp != nullptr) {   // traverse the list
            cout << temp->data;     
            if (temp->next != nullptr) {
                cout << "-> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    // prints the list from tail to head using the prev links
    void PrintReverse() {
        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        node* temp = tail;
        cout << "Reverse: ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->prev != nullptr) {
                cout << "-> ";
            }
            temp = temp->prev;
        }
        cout << endl;
    }

    // deletes every node one by one and resets head and tail
    void ClearList() {
        node* temp = head;
        while (temp != nullptr) {
            node* nextNode = temp->next;   // save the link before deleting
            delete temp;
            temp = nextNode;
        }
        head = nullptr;
        tail = nullptr;
    }
};

int main() {
    DoublyList list;
    int count;
    int value;

    cout << "How many numbers to add: ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> value;
        list.AddNode(value);
    }

    list.PrintForward();
    list.PrintReverse();

    list.ClearList();
    return 0;
}