#include <iostream>

using namespace std;

//Write a program that prints the first 100 numbers of the Fibonacci series

int main(int argc, char const *argv[])
{
    ulong prevDigit = 0;
    ulong currentDigit = 1;  
    ulong result; 
    cout << "Printing the first 100 Fibonacci digits series " << endl;
    cout << prevDigit << endl; 

    for (size_t i = 0; i < 100 ; i++)
    {
        result = currentDigit + prevDigit; 
        cout << result << endl;  
        prevDigit = currentDigit;
        currentDigit = result;  
    }
    
    
    return 0;
}
