/* 
    Name : Muhammad Shahzaib Nazir
    CMS ID : 543983
    Section : D
*/

#include <iostream>
#include <string>
using namespace std;

// Create a structure student with roll number, full name and marks
struct Student {
    int rollNumber;
    string fullName;
    float marks;
};

// display a record if it exists
void displayIfExists(const Student* s) {
    if (s == nullptr) {
        cout << "No record available" << endl;
    } else {
        cout << "Roll Number: " << s->rollNumber << endl;
        cout << "Full Name: " << s->fullName << endl;
        cout << "Marks: " << s->marks << endl;
    }
}

int main() {

    // An instance of the Student structure
    Student* s2 = nullptr;
    displayIfExists(s2);

    s2 = new Student();

    // Assign values to the s2 instance
    s2->rollNumber = 670;
    s2->fullName = "Ammar";
    s2->marks = 91;

    displayIfExists(s2);

    // delete the memory from heap
    delete s2;
    // set pointer to nullptr after deletion
    s2 = nullptr;

    displayIfExists(s2);

    return 0;
}