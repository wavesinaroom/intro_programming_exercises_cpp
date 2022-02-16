#include <iostream>
using namespace std;

/*write a program that reads two numbers from the console and prints 
the greatest. Solve the problem without conditional statements*/

int main(int argc, char const *argv[])
{
    int firstNumber;
    int secondNumber;

    cout << "This one goes pretty quickly, we're finding out greatest number between two ints " << endl;
    cout << "Type your first int: " << endl;
    cin >> firstNumber;
    cout << "Type your second int: " << endl;
    cin >> secondNumber; 

    cout << "Your greatest number is: " << max(firstNumber,secondNumber) << endl; 
    return 0;
}
