#include <iostream>
using namespace std;

int main(){

    int sales[5];       // integer array of size 5
    int *p = sales;     // p points to the array 
    int num;
    int sum = 0;

    // Taking 5 inputs from user
    for(int i=0; i < 5; i++){
        cout << "Enter a non negative number: ";
        cin >> num;
        *(p+i) = num; // input in the array
        sum += *(p+i);     // add to sum
    }   

    cout << "Original Values: ";
    for(int i=0; i < 5; i++){       // loop through array
        cout << *(p+i) << " ";      // display result
    }

    cout << "\n Total sum: " << sum << endl;        // display total sum

    cout << "Updated Values: ";
    sum = 0;
    for(int i=0; i < 5; i++){       // loop through array
        if(i==2){
            *(p+i) += 2;        // add 2 to the 3rd value
        }
        sum += *(p+i);
        cout << *(p+i) << " ";      // display result
    }

    cout << "\n Total updated sum: " << sum << endl;        // display total sum
    
    return 0;
}