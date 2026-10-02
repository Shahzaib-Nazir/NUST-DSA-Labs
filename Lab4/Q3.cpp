// Name : Muhammad Shahzaib Nazir
// CMS ID : 543983
// Class : BSCS-15-D
// Task 3: Searching and accessing the second node
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

    // Displays the position (first node = 1) of the first match
    void SearchNode(int searchData) {
        int pos = 1;
        node* curr = head;      // make current node point to same place as head
        while (curr != nullptr) {       // traverse linked list
            if (curr->data == searchData) {     // find the data we are searching for
                cout << searchData << " found at position " << pos << endl;
                return;
            }
            curr = curr->next;      // move current pointer forward
            pos++;
        }
        cout << "Value not found" << endl;      // incase pos was not found
    }   

    void PrintSecondNode() const {
        if (head == nullptr || head->next == nullptr) {
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

// Runs the required checks on one list
static void runChecks(const char* title, List& list) {
    cout << "--- " << title << " ----" << endl;
    cout << "List: ";
    list.PrintList();
    list.PrintSecondNode();
    cout << "Search 20: ";
    list.SearchNode(20);
    cout << "Search 99: ";
    list.SearchNode(99);
    cout << endl;
}

int main() {
    List empty;
    runChecks("Empty list", empty);

    List one;
    one.AddNode(10);
    runChecks("One-node list", one);

    List many;
    many.AddNode(10);
    many.AddNode(20);
    many.AddNode(30);
    many.AddNode(20);
    runChecks("List 10, 20, 30, 20", many);

    empty.ClearList();
    one.ClearList();
    many.ClearList();
    
    return 0;
}
