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

int main() {

    // An instance of the Student structure
    Student* s2 = new Student();

    // Take input for roll number, full name and marks from the user
    cout << "Enter roll number for student: ";
    cin >> s2->rollNumber;
    cout << "Enter full name for student: ";
    cin >> s2->fullName;
    cout << "Enter marks for student: ";
    cin >> s2->marks;

    // display the details
    cout << "Roll Number: " << s2->rollNumber << endl;
    cout << "Full Name: " << s2->fullName << endl;
    cout << "Marks: " << s2->marks << endl;

    // delete the memory from heap
    delete s2;
    // set pointer to nullptr after deletion
    s2 = nullptr;

    return 0;
}