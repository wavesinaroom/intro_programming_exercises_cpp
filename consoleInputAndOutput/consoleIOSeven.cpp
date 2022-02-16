#include <iostream>

using namespace std;

/*Write a program that reads five integer numbers and prints their sum.
If an invalid number is entered the program should prompt the user to enter
another number*/

int main ()
{
    int firstNumber;
    int secondNumber;
    int thirdNumber; 
    int fourthNumber;
    int fifthNumber;
    long result;
    
    cout << "Hello there! This is sort of a boring one" << endl;
    cout << "You're gonna need enter 5 numbers" << endl; 
    cout << "Enter your first number: " << endl; 
    cin >> firstNumber; 
    //Console outputs an error if the number is decimal
    cout << "Enter your second number: " << endl; 
    cin >> secondNumber;
    cout << "Enter your third number: " << endl; 
    cin >> thirdNumber;
    cout << "Enter your fourth number: " << endl; 
    cin >> fourthNumber;
    cout << "Enter your fifth number: " << endl; 
    cin >> fifthNumber;
    result = (firstNumber+secondNumber+thirdNumber+fourthNumber+fifthNumber); 
    cout << "The sum of your numbers is: " << result << endl; 


    return 0; 
}