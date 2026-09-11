#include <iostream>
using namespace std;

int main(){
    int arr[10];        // initialize array
    
    for (int i = 0; i < 10; i++){    // loop through 6 times
        cout << "Enter integer " << i+1 << " : ";       // prompt to enter integer
        cin >> arr[i];      // input the number
    }

    int count = 0;

    // Check every element
    for (int i = 0; i < 10; i++){
        bool found = false;
        // Check if arr[i] already exists among unique values
        for (int j = 0; j < count; j++){
            if (arr[i] == arr[j]){
                found = true;
                break;
            }
        }

        // If it is a new value
        if (!found){
            arr[count] = arr[i];
            count++;
        }
    }

    // Display unique values
    cout << "Unique values: ";
    for (int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }

    cout << "\nCount: " << count;

    return 0;
}