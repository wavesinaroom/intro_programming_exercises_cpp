#include <iostream>
#include <iomanip>
using namespace std;

/* Write a program that prints three numbers in three virtual columns
on the console. Each column should have a width of 10 characters and
the numbers should be left asigned. The first number should be an 
integer in hexidecimal. The second should be fractional positive and the last
a negative fraction. The last two numbers have to be rounded to the second
decimal place.*/ 

int main(int argc, char const *argv[])
{
    unsigned int hexNumber;
    float posFraction;
    float negFraction;

    cout << "Weird numbers for this program:" << endl;
    cout << "Enter your hex number:" << endl;
    cin >> hexNumber;
    cin.ignore();
    cout << "Enter your positive fraction / float:" << endl;
    cin >> posFraction; 
    cout << "Enter your negative fraction / float:" << endl; 
    cin >> negFraction;    
    
     
    cout << "|" << hex << hexNumber << setprecision(8) << "|" << " ";  
    cout << "|" << posFraction << setprecision(8) << "|" << " ";
    cout << "|" << negFraction << setprecision(8) << "|" << " ";

    return 0;
}
