#include <iostream>
using namespace std;

int main(){
    int numbers[5];         // initialize an array to hold 5 integers (empty right now)
    int total =0;       // set total to 0
    int val;            // initialize variable val

    for(int i = 0; i < 5; i++){         // loop 5 times
        cout << "Enter a number: ";     // prompt user to enter a number 
        cin >> val;                     // take input from user and store in 'val'
        numbers[i] = val;               // insert the input number to the array 
    }

    for(int i = 0; i < 5; i++){         // loop 5 times
        cout << i << " ";               // output index 
        cout << numbers[i] << " ";      // output the array element
        total += numbers[i];            // add each value to the total one by one
        cout << total << endl;          // sum after the loop
    }

    cout << "The total is: " << total;          // print the total

    return 0;
}
