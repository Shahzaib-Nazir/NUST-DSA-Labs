// Name : Muhammad Shahzaib Nazir
// CMS ID : 543983
// Class : BSCS-15-D
// Task 4: Inserting at the beginning
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

    // Insert at the beginning: connect to old first node, then update head
    void InsertAtBeginning(int addData) {
        node* n = new node;
        n->data = addData;
        n->next = head;
        head = n;
    }

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

    void PrintSecondNode()  {
        if (head == nullptr || head->next == nullptr) {     // check for <2 nodes
            cout << "The list has fewer than two nodes." << endl;
            return;
        }
        cout << "Second node: " << head->next->data << endl;
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
    cout << "Initial list: ";
    list.PrintList();

    list.InsertAtBeginning(20);
    cout << "After InsertAtBeginning(20): ";
    list.PrintList();

    list.InsertAtBeginning(10);
    cout << "After InsertAtBeginning(10): ";
    list.PrintList();

    list.AddNode(30);
    cout << "After AddNode(30): ";
    list.PrintList();

    list.ClearList();
    return 0;
}
