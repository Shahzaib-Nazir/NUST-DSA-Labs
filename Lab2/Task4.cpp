#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    // Read and validate rows and cols
    cout << "Enter the number of students and subjects : ";
    cin >> rows >> cols;

    if (rows <= 0 || cols <= 0) {
        cout << "Invalid inputs!" << endl;
        return 1;
    }

    // Allocate dynamically
    int** marks = new int*[rows];
    for (int r = 0; r < rows; r++) {        // Loop through rows
        marks[r] = new int[cols];           // create marks arrays
    }

    // Read marks using pointer notation
    cout << "Enter marks for each student:" << endl;
    // Loop through the rows and columns
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << "Enter marks : ";
            cin >> *(*(marks + r) + c);
        }
    }

    // Display matrix using pointer notation
    cout << "Marks Matrix:" << endl;
    // Loop through the matrix
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << *(*(marks + r) + c) << "\t";        // output marks
        }
        cout << endl;
    }

    // Calculate student totals and tell the top student
    int bestStudent = 1;
    int highestTotal = -1;

    cout << "\nTotals: ";
    for (int r = 0; r < rows; r++) {
        int studentTotal = 0;
        for (int c = 0; c < cols; c++) {
            studentTotal += *(*(marks + r) + c);
        }

        cout << studentTotal << (r == rows - 1 ? "" : ", ");

        // Set baseline for first student then keep first on ties
        if (r == 0 || studentTotal > highestTotal) {
            highestTotal = studentTotal;
            bestStudent = r + 1;
        }
    }
    cout << endl;

    cout << "Top student: " << bestStudent << " (Total: " << highestTotal << ")" << endl;

    // Delete the allocated memory
    for (int r = 0; r < rows; r++) {        // loop through the rows
        delete[] marks[r];
    }
    delete[] marks;     // release heap memory
    marks = nullptr;       

    return 0;
}