#include <iostream>

using namespace std;

/* We're given a number n and a position p. Write a sequence of operations that prints
the value of the bit on the position p in the number (0 or 1). Example n=35, p=5 -> 1.
Another example n=35 p=6 ->0. */


int main(int argc, char const *argv[])
{
    int number;
    int position;
    int digit;
    
    cout << "Bit wise operations can be hard but let's see how it goes" << endl;
    cout << "Enter a number" << endl; 
    cin >> number;
    cout << "Enter the byte position to be printed " << endl;
    cin >> position; 

    cout << "Digit at position: " << position << " = " << (number >> position) << endl;  
    return 0;
}
