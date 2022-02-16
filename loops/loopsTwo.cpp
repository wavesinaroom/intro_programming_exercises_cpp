#include <iostream>

using namespace std;

/*Write a program that prints on the console the numbers from 1 to N,
which are not divisible by 3 and 7 simultaneously. Number N should be read
from the input*/

int main(int argc, char const *argv[])
{
    /*Book solution has a problem, but that's ok I figured it out anyway*/
    int nNumber;
    cout<<"I want to rise the bar a bit"<<endl;
    cout<<"I'll find all N numbers that are not divisible by 3 and 7 simultaneosly"<<endl;
    cout<<"How many number do you want me to scan?"<<endl;
    cin>>nNumber;

    for (size_t i = 1; i <= nNumber; i++)
    {
        if ((i%(3*7)!=0))
        {
            cout<<i<<" is not divisible by 3 or 7"<<endl; 
        }
    }
    return 0;
}
