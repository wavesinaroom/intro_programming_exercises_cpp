#include <iostream>

using namespace std;

/* Write a program that asks for a digit (0-9), and depending on the input,
shows the digit as a word(in English). Use a switch statement. */

int main(int argc, char const *argv[])
{
    int digit;

    cout<<"Yeah, first time using a switch in these exercises"<<endl;
    cout<<"Just plug in a digit between 0 and 9"<<endl; 
    cin>>digit; 
    
    //If user inputs a letter, C++ takes it as 0. That can be solved with an exception 
    switch (digit)
    {
    case 0:
        cout<<"A"<<endl;
        break;
    case 1:
        cout<<"B"<<endl;
        break;
    case 2:
        cout<<"C"<<endl;
        break;
    case 3:
        cout<<"D"<<endl;
        break;
    case 4:
        cout<<"E"<<endl;
        break;
    case 5:
        cout<<"F"<<endl;
        break;
    case 6:
        cout<<"G"<<endl;
        break;
    case 7:
        cout<<"H"<<endl;
        break;
    case 8:
        cout<<"I"<<endl;
        break;
    case 9:
        cout<<"J"<<endl;
        break;
    default:
        cout<<"Not a digit mate " <<endl; 
        break;
    }

    return 0;
}
