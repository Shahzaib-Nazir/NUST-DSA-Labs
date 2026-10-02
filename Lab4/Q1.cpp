// Name : Muhammad Shahzaib Nazir
// CMS ID : 543983
// Class : BSCS-15-D
// Task 1: Creating and traversing a list
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
    List(const List&) = delete;            // copying not allowed
    List& operator=(const List&) = delete;

    // Reads 3 integers and links them in input order
    void CreateThreeNodes() {
        if (head != nullptr) {  // check if list isnt empty
            cout << "List is not empty; CreateThreeNodes() must be called once on an empty list.\n";
            return;
        }
        node* tail = nullptr;
        for (int i = 1; i <= 3; i++) {
            // create a new node
            node* n = new node;
            cout << "Enter value " << i << ": ";
            cin >> n->data;     // take input 
            n->next = nullptr; 
            if (head == nullptr) {      // incase of empty list
                head = n;   // first node
            } else tail->next = n;             // link after previous node
            tail = n;
        }
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
    cout << "Before creation :\n";
    list.PrintList();

    list.CreateThreeNodes();

    cout << "After creation :\n";
    list.PrintList();

    list.ClearList();
    return 0;
}
