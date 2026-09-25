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

void displayStudent(const Student* s){
    // display the details
    cout << "Roll Number: " << s->rollNumber << endl;
    cout << "Full Name: " << s->fullName << endl;
    cout << "Marks: " << s->marks << endl;
    cout << endl;
}

void updateMarks(Student* s, float newMarks){
    cout << "Updated marks for student: ";
    s->marks = newMarks;
    cout << endl;
}


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

    displayStudent(s2);
    updateMarks(s2, 95);
    displayStudent(s2);

    // delete the memory from heap
    delete s2;
    // set pointer to nullptr after deletion
    s2 = nullptr;

    return 0;
}