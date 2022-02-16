#include <iostream>
#include <math.h>

using namespace std;

/*Write a program that converts a given number from decimal to hexadecimal notation.*/

int main(int argc, char const *argv[])
{
    int decimalNumber;
    int remainder; 
    int iterator=0;  
    int digit; 
    //Hex numbers include A to F chars in their system
    char hexDecimalNumber[16];

    //Message and input
    cout<<"This is a hard one :/...we've got to convert decimal to hex"<<endl;
    cout<<"Enter your decimal number: "<<endl;
    cin>>decimalNumber; 

    //Decimal to hex division loop
    while (decimalNumber>0)
    {   
        //Modulo and division to take out digits
        remainder = decimalNumber%16;  
        decimalNumber/=16; 
        //Compares digit to output remainder
        switch (remainder)
        {
        case 0:
            hexDecimalNumber[iterator] = '0'; 
            break;
        case 1:
            hexDecimalNumber[iterator] = '1'; 
            break;
        case 2:
            hexDecimalNumber[iterator] = '2'; 
            break;
        case 3:
            hexDecimalNumber[iterator] = '3'; 
            break;
        case 4:
            hexDecimalNumber[iterator] = '4'; 
            break;
        case 5:
            hexDecimalNumber[iterator] = '5'; 
            break;
        case 6:
            hexDecimalNumber[iterator] = '6'; 
            break;
        case 7:
            hexDecimalNumber[iterator] = '7'; 
            break;
        case 8:
            hexDecimalNumber[iterator] = '8'; 
            break;
        case 9:
            hexDecimalNumber[iterator] = '9'; 
            break;
        case 10:
            hexDecimalNumber[iterator] = 'A'; 
            break;
        case 11:
            hexDecimalNumber[iterator] = 'B'; 
            break;
        case 12:
            hexDecimalNumber[iterator] = 'C'; 
            break;
        case 13:
            hexDecimalNumber[iterator] = 'D'; 
            break;
        case 14:
            hexDecimalNumber[iterator] = 'E'; 
            break;
        case 15:
            hexDecimalNumber[iterator] = 'F'; 
            break;
        }
        iterator++; 
    }
    
    //Prints number back to forth cause of array input order
    for (size_t i = iterator; i >0;  i--)
    {
        cout<<hexDecimalNumber[i-1]; 
    }
    
    

    return 0;
}
