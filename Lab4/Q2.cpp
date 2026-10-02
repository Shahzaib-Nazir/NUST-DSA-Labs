// Name : Muhammad Shahzaib Nazir
// CMS ID : 543983
// Class : BSCS-15-D
// Task 2: Appending nodes using a loop
#include <iostream>
using namespace std;

// Creating node class
class List {
private:
    struct node {
        int data;
        node* next;
    };
    node* head;

public:
    List() : head(nullptr) {}
    ~List() { ClearList(); }
    List(const List&) = delete;
    List& operator=(const List&) = delete;

    // Inserts a new node at the end of the list
    void AddNode(int addData) {
        node* n = new node;         // creating a node
        n->data = addData;          // add data
        n->next = nullptr;                   // new node is always the last one
        if (head == nullptr) {      // incase of empty lit
            head = n;
            return;
        }
        node* curr = head;      // current node points same place as head
        while (curr->next != nullptr)        // walk to the last node
            curr = curr->next;
        curr->next = n;     // join to our new node
    }

    int CountNodes() {
        int count = 0;
        node* curr = head;
        while (curr != nullptr) {   // traverse linked list until last node
            count++;        // increment count
            curr = curr->next;
        }
        return count;
    }

    void PrintList() {
        if (head == nullptr) {      // check if list is empty
            cout << "List is empty.\n";
            return;
        }
        node* curr = head;                   // current pointer pointing same pos as head
        while (curr != nullptr) {       // traverse list
            cout << curr->data;         // print data
            if (curr->next != nullptr) cout << " -> ";
            curr = curr->next;          // move current pointer forward
        }
        cout << " -> NULL\n";       // end of the list
    }

    void ClearList() {
        while (head != nullptr) {
            node* temp = head;
            head = head->next;               // save link before deleting
            delete temp;                // delete node
        }
        head = nullptr;
    }
};

int main() {
    List list;
    int n;
    int value;
    cout << "Input amount of positive integers you want to add? ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Enter integer " << i << ": ";
        cin >> value;
        list.AddNode(value);
    }

    cout << "List : ";
    list.PrintList();
    cout << "Count: " << list.CountNodes() << endl;

    list.ClearList();
    return 0;
}
