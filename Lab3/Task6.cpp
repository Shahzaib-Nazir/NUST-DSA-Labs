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

// Update the marks of a student record if it exists
void updateMarks(Student* s, float newMarks) {
    if (s != nullptr) {
        s->marks = newMarks;
        cout << "Marks updated successfully.\n";
    }
    else {
        cout << "No record available.\n";       // in case of not existing
    }
}

int main() {

    Student* s1 = nullptr;      // initialize to null pointer
    int choice;     // user input choice for menu

    do {
        cout << "\n Student Record : " << endl;
        cout << "1. Create Record" << endl;
        cout << "2. Display Record" << endl;
        cout << "3. Update Marks" << endl;
        cout << "4. Delete Record" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Prevent creating another record
                if (s1 != nullptr) {
                    cout << "A record already exists. Cannot create another." << endl;
                }
                else {
                    s1 = new Student();

                    cout << "Enter roll number: ";
                    cin >> s1->rollNumber;

                    cout << "Enter full name: ";
                    cin.ignore();       // Ignore the newline char left in input buffer
                    getline(cin, s1->fullName);

                    cout << "Enter marks: ";
                    cin >> s1->marks;

                    cout << "Record created successfully." << endl;
                }
                break;

            case 2:
                // Display only if record exists
                displayIfExists(s1);
                break;

            case 3:
                if (s1 != nullptr) {        // check if exists
                    float newMarks;

                    cout << "Enter new marks: ";
                    cin >> newMarks;

                    updateMarks(s1, newMarks);      // update the marks
                }
                else {
                    cout << "No record available." << endl;
                }
                break;

            case 4:
                // Delete only if record exists
                if (s1 != nullptr) {
                    delete s1;
                    s1 = nullptr;

                    cout << "Record deleted successfully." << endl;
                }
                else {
                    cout << "No record available to delete." << endl;
                }
                break;

            case 5:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter 1-5." << endl;
        }

    } while (choice != 5);

    // Release any remaining allocation before exiting
    if (s1 != nullptr) {
        delete s1;
        s1 = nullptr;
    }

    return 0;
}