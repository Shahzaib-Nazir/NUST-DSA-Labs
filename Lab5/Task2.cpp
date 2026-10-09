// Name: Muhammad Shahzaib Nazir
// Reg No: 543983
// Section: D
// Lab 05 - Task 2: Insertion and deletion in a doubly linked list

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

    // adds a new node at the end of the list using tail
    void AddNode(int value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // inserts value before the node at the given position (positions start at 1)
    // if the position is not an existing node, the list is left unchanged
    void InsertBefore(int position, int value) {
        if (position < 1 || head == nullptr) {
            cout << "Invalid position " << position << ", nothing inserted." << endl;
            return;
        }

        // walk to the node at that position
        node* current = head;
        int index = 1;
        while (current != nullptr && index < position) {    // move forward until position is reached
            current = current->next;
            index++;
        }

        if (current == nullptr) {           // end of list reached without reaching position
            cout << "Invalid position " << position << ", nothing inserted." << endl;
            return;
        }

        node* newNode = new node;
        newNode->data = value;
        newNode->next = current;
        newNode->prev = current->prev;

        if (current->prev == nullptr) {
            // inserting before the head, so the new node becomes head
            head = newNode;
        } else {
            current->prev->next = newNode;      // node before curr next points to new node
        }
        current->prev = newNode;

        cout << "Inserted " << value << " before position " << position << "." << endl;
    }

    // deletes only the first node that holds the given value
    // handles head, tail, middle and the only node
    void DeleteNode(int value) {
        node* current = head;
        while (current != nullptr && current->data != value) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Value " << value << " not found, nothing deleted." << endl;
            return;
        }

        if (current->prev == nullptr) {
            // deleting the head
            head = current->next;
        } else {
            current->prev->next = current->next;
        }

        if (current->next == nullptr) {
            // deleting the tail
            tail = current->prev;
        } else {
            current->next->prev = current->prev;
        }

        delete current;
        cout << "Deleted " << value << "." << endl;
    }

    // prints the list from head to tail
    void PrintForward() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        node* temp = head;
        cout << "Forward: ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << ", ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    // prints the list from tail to head
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
                cout << ", ";
            }
            temp = temp->prev;
        }
        cout << endl;
    }

    // prints both directions, used after every change
    void PrintBoth() {
        PrintForward();
        PrintReverse();
        cout << endl;
    }

    // deletes every node one by one and resets head and tail
    void ClearList() {
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
    DoublyList list;

    cout << "--- Main test: 10, 20, 30 ---" << endl;
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);
    list.PrintBoth();

    list.InsertBefore(2, 15);
    list.PrintBoth();

    list.DeleteNode(20);
    list.PrintBoth();      // 10, 15, 30

    cout << "Insert before head" << endl;
    list.InsertBefore(1, 5);
    list.PrintBoth();      // 5, 10, 15, 30

    cout << "Invalid positions" << endl;
    list.InsertBefore(0, 99);
    list.InsertBefore(-3, 99);
    list.InsertBefore(5, 99);   // list only has 4 nodes
    list.PrintBoth();

    cout << "Delete head" << endl;
    list.DeleteNode(5);
    list.PrintBoth();      // 10, 15, 30

    cout << "Delete tail" << endl;
    list.DeleteNode(30);
    list.PrintBoth();      // 10, 15

    cout << "Missing value" << endl;
    list.DeleteNode(77);
    list.PrintBoth();

    cout << "Delete until empty (only node case)" << endl;
    list.DeleteNode(10);
    list.DeleteNode(15);
    list.PrintBoth();

    cout << "Operations on empty list" << endl;
    list.DeleteNode(10);
    list.InsertBefore(1, 10);
    list.PrintBoth();

    cout << "Only node: add one then delete it" << endl;
    list.AddNode(42);
    list.PrintBoth();
    list.DeleteNode(42);
    list.PrintBoth();

    list.ClearList();
    return 0;
}
