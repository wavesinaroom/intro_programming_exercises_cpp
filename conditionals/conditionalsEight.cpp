#include <iostream>

using namespace std;

/*Write a program that inputs int, double, or string variable
depending on the user's choice. If the variable is int or double,
the program increases it by 1. If the variable is a string, the program
appends "*" at the end. Print the result in the console, use switch statement*/

int main(int argc, char const *argv[])
{
    int userChoice;
    int integerNumber;
    double doubleNumber;
    string stringValue;
    char appendChar = '*'; 

    cout<< "Hi! You can change an integer by pressing 1, change a double by pressing 2"<<endl;
    cout<<"or add * character to a string by pressing 3"<<endl;
    cout<<"What's your choice?"<<endl;
    cin>>userChoice;

    switch (userChoice)
    {
    case 1:
        cout<<"Good choice, please enter an integer"<<endl;
        cin>>integerNumber;
        cout<<"Your integer: "<<integerNumber<<endl;
        cout<<"your increased integer: "<<integerNumber+1<<endl;
        break;
    case 2:
        cout<<"Good choice, please enter an double"<<endl;
        cin>>doubleNumber;
        cout<<"Your double: "<<doubleNumber<<endl;
        cout<<"your increased double: "<<doubleNumber+1<<endl;
        break;
    case 3:
        cout<<"Good choice, please enter an sring"<<endl;
        cin>>stringValue;
        cout<<"Your string: "<<stringValue<<endl; 
        stringValue += appendChar;
        cout<<"Your modified string: "<< stringValue<<endl;         
        break;
    default:
        cout<<"That's not an option buddy"<<endl; 
        break;
    }

     
    return 0;
}
