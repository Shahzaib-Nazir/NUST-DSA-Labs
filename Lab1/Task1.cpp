#include <iostream>
using namespace std;

int main(){
    int nums[5] = {2,4,6,8,10};     // array of 5 integers
    nums[2] = 7;        // setting the 3rd element (2nd index) to 7

    for(int i=0; i<5;i++){      // looping through 5 times
        cout << nums[i] << " ";     // output the each array element with a space
    }
    
    return 0;
}
