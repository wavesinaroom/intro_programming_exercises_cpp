#include <iostream>

using namespace std;

/* Write a program that calculates the sum S=1!/x+2!/x²+3!/x³...+n!/x^n
from given n and x positive integers*/

unsigned int n,x, sumIteration;


long exponent = 1; 

float factorial = 1;
float fraction;
float result;  

int main(int argc, char const *argv[])
{

    cout<<"Wanna practice some Do-while loops with factorials and stuff"<<endl;
    cout<<"Enter N number: "<<endl;
    cin>>n;
    cout<<"Enter X number: "<<endl;
    cin>>x;
    sumIteration = n; 

    for (size_t i = sumIteration; i > 0; i--)
    {
        n = i; 
        cout<<"**********"<<"Iteration: "<<i<<"***********"<<endl; 
        //Resets factorial and exponent
        factorial = 1;
        exponent = 1; 
        //Loop that finds factorial
        do
        {
            //Finds factorial
            factorial *= n; 
            //Finds exponent
            exponent *= x; 
            n--;
        } while (n>0);

        cout<<"Factorial: "<<factorial<<endl;
        cout<<"Exponent: "<<exponent<<endl;  
        
        fraction = factorial/exponent; 
        cout<<fraction<<endl; 

        result += fraction;  
        cout<<"Final sum: "<<result<<endl;
    }
    return 0;
}
