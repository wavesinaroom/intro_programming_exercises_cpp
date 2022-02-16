#include <iostream>

using namespace std;

/*Write a program that prints in the console the numbers from 1 to N.
Number N should be read from the standard input*/

int main(int argc, char const *argv[])
{
    int number;
    cout<<"Hey! I can print your N numbers for you "<<endl;
    cout<<"How many numbers do you want in the console? "<<endl;
    cin>>number; 
    for (size_t i = 0; i <number; i++)
    {
        cout<<"*****"<<(i+1)<<"*****"<<endl; 
    }
    
    return 0;
}
