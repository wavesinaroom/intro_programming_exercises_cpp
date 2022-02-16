#include <iostream>
#include <math.h>

using namespace std;

/*Write a program that converts a given number from hexadecimal to decimal notation.*/

int main(int argc, char const *argv[])
{
    char hexaDecimalNumber [16];

    int hexNumberDigits;
    int decimal=0;

    //Welcome message and input
    cout<<"Last conversion exercise"<<endl;
    cout<<"How many digits does your hexadecimal number have?"<<endl;
    cin>>hexNumberDigits;
    cout<<"Now, type each digit of your hexadecimal number"<<endl;
    
    int iterations = hexNumberDigits; 
    
    //Inputs hexadecimal number digits
    while(iterations>0)
    {
        cin>>hexaDecimalNumber[iterations-1];
        iterations--;    
    }

    //Converts hexDecimal number to decimal
    for (size_t i = 0; i < hexNumberDigits; i++)
    {
        switch (hexaDecimalNumber[i])
        {
        case '0':
            decimal += 0*pow(16,i);
            break;        
        case '1':
            decimal += 1*pow(16,i);
            break;
        case '2':
            decimal += 2*pow(16,i);
            break;
        case '3':
            decimal += 3*pow(16,i);
            break;
        case '4':
            decimal += 4*pow(16,i);
            break;
        case '5':
            decimal += 5*pow(16,i);
            break;
        case '6':
            decimal += 6*pow(16,i);
            break;
        case '7':
            decimal += 7*pow(16,i);
            break;
        case '8':
            decimal += 8*pow(16,i);
            break;
        case '9':
            decimal += 9*pow(16,i);
            break;
        case 'A':
            decimal += 10*pow(16,i);
            break;
        case 'B':
            decimal += 11*pow(16,i);
            break;
        case 'C':
            decimal += 12*pow(16,i);
            break;
        case 'D':
            decimal += 13*pow(16,i);
            break;
        case 'E':
            decimal += 14*pow(16,i);
            break;
        case 'F':
            decimal += 15*pow(16,i);
            break;
        }
    }
    cout<<decimal<<endl; 
    
    return 0;
}
