// Name : Muhammad Shahzaib Nazir
// CMS ID : 543983
// Class : BSCS-15-D
// Task 6: Menu-driven singly linked list application
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

    void InsertAtBeginning(int addData) {
        node* n = new node;
        n->data = addData;
        n->next = head;
        head = n;
    }

    int CountNodes()  {
        int count = 0;
        for (node* curr = head; curr != nullptr; curr = curr->next)
            count++;
        return count;
    }

    void SearchNode(int searchData)  {
        int pos = 1;
        for (node* curr = head; curr != nullptr; curr = curr->next, pos++) {
            if (curr->data == searchData) {
                cout << searchData << " found at position " << pos << endl;
                return;
            }
        }
        cout << "Value not found" << endl;
    }

    void PrintSecondNode()  {
        if (head == nullptr || head->next == nullptr) {
            cout << "The list has fewer than two nodes." << endl;
            return;
        }
        cout << "Second node: " << head->next->data << endl;
    }

    void DeleteNode(int delData) {
        if (head == nullptr) {
            cout << "Cannot delete " << delData << ": list is empty." << endl;
            return;
        }
        if (head->data == delData) {
            node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted " << delData << endl;
            return;
        }
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
        prev->next = curr->next;
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

static void showMenu() {
    cout << "\n===== Singly Linked List Menu =====\n"
         << "1. Insert at beginning\n"
         << "2. Insert at end\n"
         << "3. Search by value\n"
         << "4. Delete by value\n"
         << "5. Display all nodes\n"
         << "6. Count nodes\n"
         << "7. Display second node\n"
         << "8. Exit\n"
         << "Enter your choice: ";
}

int main() {
    List list;
    int choice = 0, value;

    do {
        showMenu();
        if (!(cin >> choice)) {              // non-numeric input: treat as invalid
            cin.clear();
            cin.ignore(10000, '\n');
            choice = 0;
        }

        switch (choice) {
        case 1:
            cout << "Enter value: "; cin >> value;
            list.InsertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value: "; cin >> value;
            list.AddNode(value);
            break;
        case 3:
            cout << "Enter value to search: "; cin >> value;
            list.SearchNode(value);
            break;
        case 4:
            cout << "Enter value to delete: "; cin >> value;
            list.DeleteNode(value);
            break;
        case 5:
            list.PrintList();
            break;
        case 6:
            cout << "Number of nodes: " << list.CountNodes() << endl;
            break;
        case 7:
            list.PrintSecondNode();
            break;
        case 8:
            cout << "Releasing all nodes. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number from 1 to 8." << endl;
        }
    } while (choice != 8);

    list.ClearList();
    return 0;
}
