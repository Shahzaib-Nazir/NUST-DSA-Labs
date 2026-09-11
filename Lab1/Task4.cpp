#include <iostream>
using namespace std;

int main(){

    int integers[8];    // initialize array
    int num;        // holds an array value
    int largest;    // holds largest number
    int largest_index;      // holds largest number index
    int smallest;           // holds smallest number
    int smallest_index;     // holds smallest number index

    for(int i = 0; i < 8; i++){         // loop through 8 times
        // take input from user
        cout << "Enter integer " << i+1 << " : ";
        cin >> num;
        // insert input into the array
        integers[i] = num;
    }   

    // set largest and smallest numbers and indexes to first element
    largest = integers[0];
    largest_index = 0;
    smallest = integers[0];
    smallest_index = 0;

    for(int i = 0; i < 8; i++){     // loop through 8 times
        int count = 0;              // counter of how many times element was found

        if (integers[i] > largest){     // compare array element with largest
            largest = integers[i];          // set new largest
            largest_index = i;              // set new largest index
        }
        if (integers[i] < smallest){     // compare array element with smallest
            smallest = integers[i];         // set new smallest
            smallest_index = i;             // set new smallest index
        }
        for (int j = 0; j < 8; j++){        // loop through 8 times (nested loop)
            if (integers[i] == integers[j]){        // check if element is same
                count++;            // increment count
                
                // if count is more than 2 then it is repeated
                if (count == 2){
                    // check in which loop the element came first
                    int first;
                    if (i < j){
                        first = i;
                    } else if ( j < i) {
                        first = j;
                    } else {
                        continue;
                    }
                    
                    // output message
                    cout << "The number " << integers[i] << " is repeated with first occurance at index " << first << endl;
                    break;   // move to next number in nested loop
                }
            }
        }
        
    }

    // output smallest and largest numbers
    cout << "Largest number is : " << largest << " and it is at index : " << largest_index << endl;
    cout << "Smallest number is : " << smallest << " and it is at index : " << smallest_index << endl;

    return 0;
}