// Name : Muhammad Shahzaib Nazir
// CMS ID : 543983
// Class : BSCS-15-D
// Task 5: Deleting a node by value
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

    // Removes only the first node containing delData
    void DeleteNode(int delData) {
        if (head == nullptr) {
            cout << "Cannot delete " << delData << ": list is empty." << endl;
            return;
        }
        // Case: first node (also covers the only node)
        if (head->data == delData) {
            node* temp = head;
            head = head->next;               // reconnect first
            delete temp;                     // then release
            cout << "Deleted " << delData << endl;
            return;
        }
        // Case: middle / last node - keep a pointer to the previous node
        node* prev = head;
        node* curr = head->next;
        while (curr != nullptr && curr->data != delData) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) {
            cout << "Cannot delete " << delData << ": value not found." << endl;
            return;
        }
        prev->next = curr->next;             // bypass the node 
        delete curr;
        cout << "Deleted " << delData << endl;
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

    cout << "Test 1: delete from an empty list\n";
    list.DeleteNode(20);
    list.PrintList();

    cout << "\nTest 2: list 10, 15, 20, 20 - delete 20 once\n";
    list.AddNode(10); list.AddNode(15); list.AddNode(20); list.AddNode(20);
    list.PrintList();
    list.DeleteNode(20);
    list.PrintList();

    cout << "\nTest 3: delete the first node (10)\n";
    list.DeleteNode(10);
    list.PrintList();

    cout << "\nTest 4: delete the last node (20)\n";
    list.DeleteNode(30);
    list.PrintList();

    cout << "\nTest 5: delete a missing value (99)\n";
    list.DeleteNode(99);
    list.PrintList();

    cout << "\nTest 6: delete the only node (15)\n";
    list.DeleteNode(20);
    list.PrintList();

    cout << "\nTest 7: middle node - list 1, 2, 3, delete 2\n";
    list.AddNode(1); list.AddNode(2); list.AddNode(3);
    list.DeleteNode(2);
    list.PrintList();

    list.ClearList();
    return 0;
}
