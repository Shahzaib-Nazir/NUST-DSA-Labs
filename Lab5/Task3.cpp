// Name: Muhammad Shahzaib Nazir
// Reg No: 543983
// Section: D
// Lab 05 - Task 3: Creating and traversing a circular linked list

#include <iostream>
using namespace std;

class CircularList {
private:
    struct node {
        int data;
        node* next;
    };

    node* head;
    node* tail;

public:
    CircularList() {
        head = nullptr;
        tail = nullptr;
    }

    ~CircularList() {
        ClearList();
    }

    // adds a node at the end using tail and keeps tail->next pointing to head
    // a single node links to itself
    void AddNode(int value) {
        node* newNode = new node;
        newNode->data = value;

        if (head == nullptr) {
            newNode->next = newNode;   // points to itself
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // prints every value exactly once, stops after one full cycle
    void PrintList() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        node* temp = head;
        cout << "List: ";
        do {
            cout << temp->data;
            if (temp != tail) {
                cout << ", ";
            }
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // counts the nodes by going around the circle once
    int CountNodes() {
        if (head == nullptr) {
            return 0;
        }

        int count = 0;
        node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);

        return count;
    }

    // breaks the circle first, then deletes node by node
    void ClearList() {
        if (head == nullptr) {
            return;
        }

        tail->next = nullptr;   // break the circle so the loop can end

        node* temp = head;
        while (temp != nullptr) {
            node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = nullptr;
        tail = nullptr;
    }
};

int main() {
    CircularList list;

    cout << "--- Empty list ---" << endl;
    list.PrintList();
    cout << "Count: " << list.CountNodes() << endl << endl;

    cout << "--- One node ---" << endl;
    list.AddNode(10);
    list.PrintList();
    cout << "Count: " << list.CountNodes() << endl << endl;

    cout << "--- 10, 20, 30 ---" << endl;
    list.ClearList();
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);
    list.PrintList();
    cout << "Count: " << list.CountNodes() << endl;

    list.ClearList();
    return 0;
}
