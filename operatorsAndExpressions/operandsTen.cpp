#include <iostream>

using namespace std;

/*Write a program that takes as input a four-digit number in format abcd (e.g. 2011)
and performs the following actions:

- Calculates the sum of the digits (in our example 2+0+1+1=4).
- Prints on the console the number in reversed order: dcba in our example.
- Puts the last digit in the first position: dabc (in our example 1102).
- Exchanges the second and the third digits: acbd (in our example 2101).
*/

int fourDigitNumber; 

int digitOne;
int digitTwo;
int digitThree;
int digitFour;

int main(int argc, char const *argv[])
{


    cout << "Let's mess around with some digits: " << endl;
    cout << "Please enter a four digit number " << endl; 
    cin >> fourDigitNumber; 

    digitFour = fourDigitNumber % 10;
    digitThree = (fourDigitNumber/10) % 10;
    digitTwo = (fourDigitNumber/100) % 10;
    digitOne = (fourDigitNumber/1000) % 10;

    

    cout << "The sum of your digits is: " << (digitOne+digitTwo+digitThree+digitFour) << endl;
    cout << "Reversed digits (; : " << digitFour << digitThree << digitTwo << digitOne << endl;
    cout << "Last Digit in the first place " << digitFour << digitOne << digitTwo << digitThree << endl;
    cout << "Digit Three and two swap places " << digitOne << digitThree << digitTwo << digitFour << endl;

    return 0;
}
