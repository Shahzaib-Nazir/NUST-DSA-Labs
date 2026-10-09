// Name: Muhammad Shahzaib Nazir
// Reg No: 543983
// Section: D
// Lab 05 - Task 4: Deletion in a circular linked list

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

    // adds a node at the end using tail and keeps tail->next = head
    void AddNode(int value) {
        node* newNode = new node;
        newNode->data = value;

        if (head == nullptr) {
            newNode->next = newNode;
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // prints every value once, stops after one full cycle
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

    // counts nodes by going around the circle once
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

    // deletes the first node holding value
    // search stops after one full cycle if the value is not there
    // handles head, tail, middle and the only node, and keeps tail->next = head
    void DeleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty, cannot delete " << value << "." << endl;
            return;
        }

        node* prev = tail;      // node just before current
        node* current = head;

        do {
            if (current->data == value) {
                if (current == head && current == tail) {
                    // only node in the list
                    head = nullptr;
                    tail = nullptr;
                } else if (current == head) {
                    head = head->next;
                    tail->next = head;
                } else if (current == tail) {
                    prev->next = head;
                    tail = prev;
                } else {
                    prev->next = current->next;
                }

                delete current;
                cout << "Deleted " << value << "." << endl;
                return;
            }

            prev = current;
            current = current->next;
        } while (current != head);

        cout << "Value " << value << " not found, nothing deleted." << endl;
    }

    // prints whether head and tail are nullptr, used to check the end state
    void PrintEnds() {
        cout << "head is " << (head == nullptr ? "nullptr" : "not nullptr")
             << ", tail is " << (tail == nullptr ? "nullptr" : "not nullptr") << endl;
    }

    // breaks the circle first, then deletes node by node
    void ClearList() {
        if (head == nullptr) {
            return;
        }

        tail->next = nullptr;

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

// shows the list and its count after each operation
void Show(CircularList& list) {
    list.PrintList();
    cout << "Count: " << list.CountNodes() << endl << endl;
}

int main() {
    CircularList list;

    cout << "--- Delete on empty list ---" << endl;
    list.DeleteNode(10);
    Show(list);

    cout << "--- Main test: 10, 20, 30 ---" << endl;
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);
    Show(list);

    cout << "Delete 10 (head)" << endl;
    list.DeleteNode(10);
    Show(list);

    cout << "Delete 30 (tail)" << endl;
    list.DeleteNode(30);
    Show(list);

    cout << "Delete 20 (only node)" << endl;
    list.DeleteNode(20);
    Show(list);
    list.PrintEnds();
    cout << endl;

    cout << "--- Missing value ---" << endl;
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);
    list.DeleteNode(99);
    Show(list);

    cout << "--- Middle node ---" << endl;
    list.DeleteNode(20);
    Show(list);

    cout << "--- Duplicates: 10, 20, 20, 30, delete 20 once ---" << endl;
    list.ClearList();
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(20);
    list.AddNode(30);
    list.DeleteNode(20);
    Show(list);

    list.ClearList();
    list.PrintEnds();
    return 0;
}
