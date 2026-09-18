#include <iostream>
using namespace std;

int main() {
    int n;

    // Current students
    cout << "Enter number of students (1-10) : ";
    cin >> n;

    // Validate n
    if (n < 1 || n > 10) {
        cout << "Invalid number of students!" << endl;
        return 1;
    }

    // Allocate the original block of n marks
    int* marks = new int[n];

    // Read the n existing marks using pointer notation
    cout << "Enter " << n << " marks:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter mark : ";
        cin >> *(marks + i);
    }

    // Allocate a second, bigger block (n + 1 slots)
    int* newMarks = new int[n + 1];

    // Copy the old marks over into the new block, one by one, using pointer notation
    for (int i = 0; i < n; i++) {
        *(newMarks + i) = *(marks + i);
    }

    // Read the brand new student's mark straight into the last open slot
    cout << "Enter mark for the new student : ";
    cin >> *(newMarks + n);


    delete[] marks;

    // Make the original pointer point at the new block instead
    marks = newMarks;

    // Update size variable
    n = n + 1;

    // Display everything, old marks and the new ones
    cout << "\nUpdated marks list: ";
    for (int i = 0; i < n; i++) {
        cout << *(marks + i) << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    // Release the heap memory and set pointer to null pointer
    delete[] marks;
    marks = nullptr;

    return 0;
}   