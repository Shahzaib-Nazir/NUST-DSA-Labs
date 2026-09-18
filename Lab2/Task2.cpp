#include <iostream>
using namespace std;

int main(){

    int n, score;
    int total = 0;
    int above_or_50 = 0;
    float avg;

    // validate and take input of n (num of students)
    do{
        cout << "Enter the number of students: ";
        cin >> n;
        if(n == 0){     // if studnets are 0 then ask for input again with error
            cout << "Error, number of students cant be 0, Enter a positive number" << endl;
        }
    } while (n <= 0);


    int* marks = new int[n];        // dynamic array of marks of size n
    // Loop through the array and take user input values
    for(int i = 0; i < n; i++){
        cout << "Enter the marks of student " << (i+1) << " : ";
        cin >> score;
        *(marks+i) = score;    
    }

    for(int i = 0; i < n; i++){     // loop through the array
        cout << *(marks+i) << " ";  // output marks
        if (*(marks+i) >= 50){      // check if the student has 50 or more marks
            above_or_50++;
        }
        total += *(marks+i);        // add to total
    }

    avg = total/n;      // calculate average

    // display results
    cout << "Total : " << total << endl;
    cout << "Average : " << avg << endl;
    cout << "Number of students at 50 or above : " << above_or_50 << endl;


    delete[] marks;     // delete the elements
    marks = nullptr;    // point to null

    return 0;
}