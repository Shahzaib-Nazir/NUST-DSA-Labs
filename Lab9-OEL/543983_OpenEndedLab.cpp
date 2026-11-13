// name: Muhammad Shahzaib Nazir
// registration no: 543983
// section: D

// time complexity (worst case):
// add student is O(n), happens when the tree is a straight line (sorted input)
// search student is O(n) and average case is O(log n)
// enqueue/dequeue is O(1)

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
    Student* cur = root;        // use a current pointer from root
    while (cur != NULL) {
        if (roll == cur->roll)      // roll no found
            return cur;
        // split left or right
        else if (roll < cur->roll)      // move left
            cur = cur->left;
        else        // move right
            cur = cur->right;
    }
    return NULL;
}

// adds a student, returns false if roll already exists
bool addStudent(int roll, string name) {
    if (searchStudent(roll) != NULL)        // check if student already exists
        return false;

    // create a new node 
    Student* node = new Student;
    node->roll = roll;
    node->name = name;
    node->left = NULL;
    node->right = NULL;

    // in case of being first node
    if (root == NULL) {
        root = node;
        return true;
    }

    // use current pointer to find the right place to insert
    Student* cur = root;
    while (true) {
        if (roll < cur->roll) {
            if (cur->left == NULL) {        // check if empty
                cur->left = node;           // insert here 
                break;
            }
            cur = cur->left;        // mmove left
        } else {
            if (cur->right == NULL) {       // check if empty
                cur->right = node;          // insert here 
                break;
            }
            cur = cur->right;       // move right
        }
    }
    return true;
}

// prints in order (left, node, right) so rolls come out in ascending order
void displayTree(Student* node) {
    if (node == NULL)       // check for empty tree
        return;
    displayTree(node->left);
    cout << node->roll << "  " << node->name << endl;
    displayTree(node->right);
}

// deletes the whole tree deleting the children first (post order)
void deleteTree(Student* node) {
    if (node == NULL)
        return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// help requests are kept in a queue (linked list with front and rear).
// the desk should serve people in the order they asked (first come first served)

// put a roll at the back of the queue
void enqueue(int roll) {
    // create a new node
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

    Request* temp = front;      // temporary pointer to delete the front node
    roll = temp->roll;
    front = front->next;        // move front forward
    if (front == NULL)
        rear = NULL;    
    delete temp;        // delete the node
    return true;
}

// shows who is waiting without removing anyone
void showQueue() {
    if (front == NULL) {        // incase of empty queue
        cout << "no requests waiting" << endl;
        return;
    }
    cout << "waiting (first to last): ";
    Request* cur = front;
    // traverse the queue and output all rolls
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
    Student* s = searchStudent(roll);       // point to the roll number in the tree
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
    } while (choice != 5);      // exit

    // clean up before leaving
    deleteTree(root);
    int temp;
    while (dequeue(temp)) {     // dequeue all requests
    }

    return 0;
}