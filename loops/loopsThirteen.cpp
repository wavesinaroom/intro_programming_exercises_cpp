#include <iostream>
#include <math.h>

using namespace std;

/*Write a program that converts a given number from binary to decimal notation.*/
int main(int argc, char const *argv[])
{
    //Binary number holds up to 32 digits
    int binaryNumber[32];
    int numberOfDigits;
    int binaryDigit;  
    int decimalNumber=0;

    //Welcome message and input
    
    cout<<"Binary to decimal conversion...should be fun"<<endl;
    cout<<"Please enter number of digits for your binary number"<<endl;
    cin>>numberOfDigits; 
    cout<<"Please enter your binary number digit by digit"<<endl;
    
    int i = numberOfDigits; 

    //Binary number digits output
    do
    {   cin>>binaryDigit; 
        if (binaryDigit>1||binaryDigit<0)
            cerr<<"That's not a valid digit"<<endl; 
        i--;  
        binaryNumber[i]=binaryDigit;
    }while (i>0); 
    //Binary to decimal conversion
    for (size_t i = 0; i < numberOfDigits; i++)
    {   
        decimalNumber += binaryNumber[i] * pow(2,i);
    }
    
    cout<<"Your decimal number: "<<decimalNumber<<endl; 

    return 0;
}


