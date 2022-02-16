#include <iostream>

using namespace std;

/*Write a program that calculates N!/K!for given N and K (1<K<N)*/

int main(int argc, char const *argv[])
{
    float result;
    int nNumber;
    int kNumber;
    long nFactorial = 1;
    long kFactorial = 1; 

    //welcome message
    cout<<"We're gonna divide factorials, please input a K number greater than one "<<endl;
    cin>>kNumber; 
    cout<<"and a N number greater than K"<<endl;
    cin>>nNumber;

    //Input
    if (kNumber<1||kNumber>nNumber)
        cerr<<"Wrong numbers, they can break the program"<<endl;      

    //N factorial loop
    for (size_t i = 1; i <= nNumber; i++)
    {
        nFactorial*=i;
        cout<<"**********"<<nFactorial<<endl; 
    }
    
    //K factorial loop
    for (size_t i = 1; i <= kNumber; i++)
    {
        kFactorial*=i; 
        cout<<"----------"<<kFactorial<<endl; 
    }

    //Division
    result=(kFactorial/nFactorial);

    cout<<result<<endl; 
    return 0;
}
