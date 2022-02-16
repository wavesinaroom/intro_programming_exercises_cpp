#include <iostream>

using namespace std;

/*Write a program that reads from the console number N 
and prints the sum of the first N members of the Fibonacci
sequence: 0,1,1,2,3,5,8,13,21,34,55,89,144,233,377*/

int main(int argc, char const *argv[])
{
    long result;
    long currentNumber = 1;
    long previousNumber = 0; 
    int sequenceLength;

    cout<<"This can through large numbers, get ready"<<endl;
    cout<<"Enter the number of digits for your Fibonacci sequence"<<endl;
    
    //Input
    cin>>sequenceLength;
    
    //Sequence calculation
    for (size_t i = 0; i < sequenceLength; i++)
    {
        result = previousNumber + currentNumber; 
        previousNumber = currentNumber;
        currentNumber = result; 
        cout<<result<<endl;
    }
    

    return 0;
}
