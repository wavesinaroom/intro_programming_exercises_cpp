#include <iostream>

using namespace std;

/* We are given a number n, the value v (v=0 or 1) and the position p. 
Write a sequence of operations that changes the value of n, so the bit on
the position p has the value of v. Example: n=35, p=5, v=0 -> n=3.
Another example: n=35 p=2, v=1 -> n=39; */

int main(int argc, char const *argv[])
{
    int number;
    int value;
    int position; 

    cout << "Things get hard so does maths " << endl;
    cout << "Enter any positive integer " << endl;
    cin >> number;
    //cout << "Enter value 1 or 0" << endl;
    //cin >> value;
    cout << "Enter bit position " << endl;
    cin >> position;

    cout << "New number! : " << (number & (~(1 << position)))  << endl;  

    return 0;
}
