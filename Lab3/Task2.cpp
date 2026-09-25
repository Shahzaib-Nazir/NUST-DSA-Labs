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
    Student* s1 = new Student();

    // Assign values to the student1 instance
    s1->rollNumber = 670;
    s1->fullName = "Ammar";
    s1->marks = 91;

    // Print the details of student1
    cout << "Roll Number: " << s1->rollNumber << endl;
    cout << "Full Name: " << s1->fullName << endl;
    cout << "Marks: " << s1->marks << endl;

    // Take new input for marks from the user
    cout << "Enter new marks for " << s1->fullName << ": ";
    cin >> s1->marks;

    // Print the updated details of student1
    cout << "Roll Number: " << s1->rollNumber << endl;
    cout << "Full Name: " << s1->fullName << endl;
    cout << "Marks: " << s1->marks << endl;

    delete s1;      // Free the allocated memory
    s1 = nullptr;   // Set the pointer to nullptr after deletion

    return 0;
}