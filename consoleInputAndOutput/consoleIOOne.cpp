#include <iostream>

using namespace std;

/* Write a program that reads from the console three numbers of type int
and prints their sum*/

int main(int argc, char const *argv[])
{
    int numberOne;
    int numberTwo;
    int numberThree;

    cout << "Hey! Let's get a pretty simple sum done here, type your numbers " << endl;
    cout << "Number one: " << endl;
    cin >> numberOne;
    cout << "Number two: "<< endl;
    cin >> numberTwo;
    cout << "Number three: " << endl;
    cin >> numberThree;

    cout << "The sum of your three number is: " << (numberOne + numberTwo + numberThree) << endl;

    return 0;
}
