#include <iostream>
#include <math.h>

using namespace std;

/*Write a program that converts a given number 
from decimal to binary notation (numeral system).*/

int decimalNumber;
int digit; 
int digitPosition; 
int iteration; 
int divRemainder; 

int binaryNumber[32]; 


int main(int argc, char const *argv[])
{
    //Welcome message and input
    cout<<"Decimal to binary convertor"<<endl;
    cout<<"Let's see how this turns out"<<endl;
    cout<<"What's your decimal number?"<<endl;
    cin>>decimalNumber; 
  
    //Decimal to binary loop converter
    while (decimalNumber>0)
    {
        //Digit position places each digit in the final number in powers of 10
        binaryNumber[iteration]=decimalNumber%2;  
        decimalNumber/=2; 
        cout<<"----"<<binaryNumber[iteration]<<endl;
        iteration++;
    }

    return 0; 
}
