#include <iostream>

using namespace std;

/* Write a boolean expression that checks if the bit on position p in the inteeger v
has the value 1. Example v=5, p=1 -> false */


int main(int argc, char const *argv[])
{
    int number;
    int position;
    
    cout << "Bit wise operations can be hard but let's see how it goes" << endl;
    cout << "Enter a number" << endl; 
    cin >> number;
    cout << "Enter the byte position to be printed " << endl;
    cin >> position; 

    cout << ((number >> position) != 0) ? cout << " True " : cout << " False " << endl; 
    return 0;
}
