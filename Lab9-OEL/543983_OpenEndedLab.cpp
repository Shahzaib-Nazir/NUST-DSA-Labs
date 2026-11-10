// name: Muhammad Shahzaib Nazir
// registration no: 543983
// section: D

// design:
// students are stored in a bst (binary search tree) using roll number as the key.
// a bst keeps rolls in order so display gives a sorted list for free and
// search/insert are fast when the tree is fairly balanced. it also makes
// the duplicate check easy because we search before inserting.
// help requests are kept in a queue (linked list with front and rear).
// the desk should serve people in the order they asked (first come first
// served) which is exactly what a queue does.

// time complexity (worst case):
// add student    -> O(n), happens when the tree is a straight line (sorted input)
// search student -> O(n), same reason. average case is O(log n)
// enqueue/dequeue -> O(1)

// alternative data structure: a hash table would give O(1) average search
// and insert, but it cannot display students in sorted order easily.

#include <iostream>
#include <string>
using namespace std;

// a student node in the tree
struct Student {
    int roll;
    string name;
    Student* left;
    Student* right;
};

// a request node in the queue
struct Request {
    int roll;
    Request* next;
};

Student* root = NULL;
Request* front = NULL;
Request* rear = NULL;

// look for a roll number, returns the node or NULL
Student* searchStudent(int roll) {
    Student* cur = root;
    while (cur != NULL) {
        if (roll == cur->roll)
            return cur;
        else if (roll < cur->roll)
            cur = cur->left;
        else
            cur = cur->right;
    }
    return NULL;
}

// adds a student, returns false if roll already exists
bool addStudent(int roll, string name) {
    if (searchStudent(roll) != NULL)
        return false;

    Student* node = new Student;
    node->roll = roll;
    node->name = name;
    node->left = NULL;
    node->right = NULL;

    if (root == NULL) {
        root = node;
        return true;
    }

    Student* cur = root;
    while (true) {
        if (roll < cur->roll) {
            if (cur->left == NULL) {
                cur->left = node;
                break;
            }
            cur = cur->left;
        } else {
            if (cur->right == NULL) {
                cur->right = node;
                break;
            }
            cur = cur->right;
        }
    }
    return true;
}

// prints in order (left, node, right) so rolls come out sorted
void displayTree(Student* node) {
    if (node == NULL)
        return;
    displayTree(node->left);
    cout << "  " << node->roll << "  " << node->name << endl;
    displayTree(node->right);
}

// deletes the whole tree, children first
void freeTree(Student* node) {
    if (node == NULL)
        return;
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}

// put a roll at the back of the queue
void enqueue(int roll) {
    Request* node = new Request;
    node->roll = roll;
    node->next = NULL;

    if (rear == NULL) {
        front = node;
        rear = node;
    } else {
        rear->next = node;
        rear = node;
    }
}

// take the roll at the front, returns false if queue is empty
bool dequeue(int &roll) {
    if (front == NULL)
        return false;

    Request* temp = front;
    roll = temp->roll;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    delete temp;
    return true;
}

// shows who is waiting without removing anyone
void showQueue() {
    if (front == NULL) {
        cout << "no requests waiting" << endl;
        return;
    }
    cout << "waiting (first to last): ";
    Request* cur = front;
    while (cur != NULL) {
        cout << cur->roll << " ";
        cur = cur->next;
    }
    cout << endl;
}

void addRequest() {
    int roll;
    cout << "enter roll number: ";
    cin >> roll;

    if (searchStudent(roll) == NULL) {
        cout << "that student is not registered, request rejected" << endl;
        return;
    }
    enqueue(roll);
    cout << "request added for roll " << roll << endl;
}

void serveRequest() {
    int roll;
    if (!dequeue(roll)) {
        cout << "no requests to serve" << endl;
        return;
    }
    Student* s = searchStudent(roll);
    cout << "now serving: " << roll << " " << s->name << endl;
}

void helpMenu() {
    int choice;
    do {
        cout << endl << "Help Requests: " << endl;
        cout << "1. add request" << endl;
        cout << "2. serve next request" << endl;
        cout << "3. show waiting requests" << endl;
        cout << "4. back" << endl;
        cout << "choice: ";
        cin >> choice;

        if (choice == 1)
            addRequest();
        else if (choice == 2)
            serveRequest();
        else if (choice == 3)
            showQueue();
        else if (choice != 4)
            cout << "wrong option, try again" << endl;
    } while (choice != 4);
}

int main() {
    int choice;

    do {
        cout << endl << "Student Help Desk:" << endl;
        cout << "1. add student" << endl;
        cout << "2. search by roll number" << endl;
        cout << "3. display all students" << endl;
        cout << "4. help requests" << endl;
        cout << "5. exit" << endl;
        cout << "choice: ";
        cin >> choice;

        if (choice == 1) {
            int roll;
            string name;
            cout << "enter roll number: ";
            cin >> roll;
            cout << "enter name: ";
            cin >> name;
            if (addStudent(roll, name))
                cout << "student added" << endl;
            else
                cout << "roll number " << roll << " already exists" << endl;
        }
        else if (choice == 2) {
            int roll;
            cout << "enter roll number: ";
            cin >> roll;
            Student* s = searchStudent(roll);
            if (s != NULL)
                cout << "found: " << s->roll << " " << s->name << endl;
            else
                cout << "no student with roll number " << roll << endl;
        }
        else if (choice == 3) {
            if (root == NULL)
                cout << "no students yet" << endl;
            else {
                cout << "roll  name" << endl;
                displayTree(root);
            }
        }
        else if (choice == 4) {
            helpMenu();
        }
        else if (choice != 5) {
            cout << "wrong option, try again" << endl;
        }
    } while (choice != 5);

    // clean up before leaving
    freeTree(root);
    int temp;
    while (dequeue(temp)) {
    }

    cout << "Goodbye" << endl;
    return 0;
}
