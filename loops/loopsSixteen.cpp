#include <iostream>
#include <math.h>

using namespace std;

/* Write a program that by a given integer N 
prints the numbers from 1 to N in random order.*/

int main(int argc, char const *argv[])
{
    int n;
    int randomResult; 

    //Welcome message and input
    cout<<"First time randomizing stuff in C++"<<endl;
    cout<<"I'll print random numbers from 1 to N"<<endl;
    cout<<"What's your number N"<<endl;
    cin>>n;

    //Loop randomizes 
    for (size_t i = 0; i < n; i++)
    {
        randomResult = rand()%n; 
        cout<<randomResult<<endl;  
    }
    return 0;
}
