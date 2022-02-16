#include <iostream>

using namespace std;

/* Write a program that reads from the console two integer numbers (int)
and prints how many numbers between them exist, such that the remainder
of their division by 5 is 0. Example: in the range (14, 25) there are
3 such number: 15, 20 and 25*/ 

int main(int argc, char const *argv[])
{
    int firstNumber;
    int secondNumber;
    int counter;

    cout << "Hey! Just type two int numbers " << endl;
    cout << "First number: " << endl;
    cin >> firstNumber;
    cout << "Second number: " << endl;
    cin >> secondNumber; 
    cout << " " << endl; 
    cout << "How many multiples of five are between:" << firstNumber;
    cout << " " << "and " << secondNumber << "?" << endl; 
    
    counter = (firstNumber - secondNumber) / 5; 
    

    cout << "You've got: " << (counter>0?(counter*1):(counter*-1)) << " multiple 5 number between " << firstNumber;
    cout << " and " << secondNumber; 
    return 0;
}
