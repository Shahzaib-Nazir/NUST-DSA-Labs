#include <iostream>
using namespace std;

// creating student class
class student {
    public:
        // class fields
        int rollNumber;     
        int marks;

        // class function 
        void display(){
            // print details
            cout << "roll number: " << rollNumber << endl;
            cout << "marks: " << marks << endl;
        }
};

int main(){
    // creating 2 student objects
    student s1;
    student s2;

    // assign student 1 roll no and marks
    s1.rollNumber = 1;
    s1.marks = 75;

    // assign student 2 roll no and marks
    s2.rollNumber = 2;
    s2.marks = 90;

    // display both student details
    cout << "Student 1 details :" << endl;
    s1.display();
    cout << "Student 2 details :" << endl;
    s2.display();

    s1.marks = 80;
    // display both student details again
    cout << "Student 1 details :" << endl;
    s1.display();
    cout << "Student 2 details :" << endl;
    s2.display();

    return 0;
}