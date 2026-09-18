#include <iostream>
using namespace std;

int main(){

    int sales[2][3];
    int (*rowPtr)[3] = sales;
    int num, branch_total, days_total;

    // Loop through the 2D array
    for(int i =0; i < 2; i++){
        for(int j =0; j < 3; j++){ 
            // Take user input
            cout << "Enter a number : ";
            cin >> num;
            *(*(rowPtr + i) + j) = num;      // put input in array  
        }
    }

    // Loop through the array
    for(int i =0; i < 2; i++){
        branch_total = 0;      // reset total for next branch
        for(int j =0; j < 3; j++){
            branch_total += *(*(rowPtr + i) + j);      // add total
            cout << *(*(rowPtr + i) + j) << " ";        // display value
        }
        cout << "       Total for this branch is : " << branch_total;      // display branch total
        cout << endl;
    }

    // Loop through the array again
    for(int j = 0; j < 3; j++){
        days_total = 0;      // reset total for next day
        for(int i = 0; i < 2; i++){
            days_total += *(*(rowPtr + i) + j);      // add total
        }
        cout << "Total for day " << j+1 <<  " is : " << days_total;      // display branch total
        cout << endl;
    }

    return 0;
}