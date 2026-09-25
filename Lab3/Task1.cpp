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
    Student s1;

    // Assign values to the s1 instance
    s1.rollNumber = 505;
    s1.fullName = "Hasan";
    s1.marks = 85;

    // Print the details of s1
    cout << "Roll Number: " << s1.rollNumber << endl;
    cout << "Full Name: " << s1.fullName << endl;
    cout << "Marks: " << s1.marks << endl;

    return 0;
}