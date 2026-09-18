#include <iostream>
using namespace std;

int main() {
    int n = 3;

    // Dynamically allocate array for n integers
    int *values = new int[n];

    // Read n integers
    for (int i = 0; i < n; i++) {
        cout << "Enter values : ";
        cin >> values[i];
    }

    // Display all three integers
    for (int i = 0; i < n; i++) {
        cout << values[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    // Correctly release array memory and reset pointer
    delete[] values;
    values = nullptr;

    return 0;
}