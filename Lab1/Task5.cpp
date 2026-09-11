#include <iostream>
using namespace std;

void reverseArray(int arr[], int start, int end)
{
    // No more swapping
    if (start >= end)
        return;

    // Swapping first and last using a temporary variable
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // Recursive call with moving start ahead and end behind to continue swapping endpoints
    reverseArray(arr, start + 1, end - 1);
}

int main(){
    int arr[6];     // initialize array

    for (int i = 0; i < 6; i++){    // loop through 6 times
        cout << "Enter integer " << i+1 << " : ";       // prompt to enter integer
        cin >> arr[i];      // input the number
    }

    // Reverse array using recursion
    reverseArray(arr, 0, 5);

    // Display updated array
    cout << "Reversed array: ";

    for (int i = 0; i < 6; i++){   // loop through each element
        cout << arr[i] << " ";      // output each element
    }

    return 0;
}