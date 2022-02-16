#include <iostream>

using namespace std;

/* Write a program that finds the biggest of three integers
using if statements*/

int main(int argc, char const *argv[])
{
    int firstNumber;
    int secondNumber;
    int thirdNumber;

    cout<<"Let's compare three ints to see which one's the greatest"<<endl;
    cout<<"Type your first number"<<endl;
    cin>>firstNumber;
    cout<<"Type your second number"<<endl;
    cin>>secondNumber;
    cout<<"Type your third number"<<endl;
    cin>>thirdNumber;

    if (firstNumber>secondNumber)
    {
        if(firstNumber>thirdNumber)
            cout<<"First number is definitely the greatest one; "<<endl;
        else
            cout<<"Third number is definitely the greatest one; "<<endl; 
    }else if(secondNumber>firstNumber)
    {
        if (secondNumber>thirdNumber)
            cout<<"Second number is definitely the greatest one; "<<endl; 
        else
            cout<<"Third number is definitely the greatest one; "<<endl; 
    }else if(thirdNumber>secondNumber)
    {
        if (thirdNumber>firstNumber)
            cout<<"Third number is definitely the greatest one; "<<endl; 
        else
            cout<<"First number is definitely the greatest one; "<<endl; 
    }
    
    return 0;
}
