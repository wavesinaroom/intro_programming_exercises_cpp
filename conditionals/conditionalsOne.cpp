#include <iostream>

using namespace std;

/* Write an if statement that takes two integer variables 
and exchanges their values if the first one is greater than 
the second one*/

int main(int argc, char const *argv[])
{
    int firstNumber;
    int secondNumber;
    int storingNumber; 
    bool isSwapped; 

    cout << "Hey! Simple number swap if one is greater than the other " << endl;
    cout << "Enter your first number " << endl; 
    cin >> firstNumber;
    cout << "Enter your second number " << endl;
    cin >> secondNumber;
    
    if(firstNumber > secondNumber)
    {
        storingNumber = firstNumber;
        firstNumber = secondNumber;
        secondNumber = storingNumber; 
        isSwapped = true; 
    }

    cout << "Your first number: " << firstNumber << endl;
    cout << "Your second number: " << secondNumber << endl;
    cout << "Were they swapped? " << isSwapped << endl;    
    return 0;
}
