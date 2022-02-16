#include <iostream>

using namespace std;

/*In combinatronics, the Catalan numbers are calculated byt the following formula
(2n)!/(n+1)!n! for n>=0. Write a program that calculates the nth Catalan number*/
 
int n;
long findFactorial(int n, int iterations); 

int main(int argc, char const *argv[])
{
    cout<<"Gonna try a simple loop to calculate the Catalan numbers"<<endl;
    cout<<"Please enter n which must be greater than 1 "<<endl;
    cin>>n;

    cout<<findFactorial(2*n,n)/findFactorial(n+1,n+1)<<endl; 

    return 0;
}

//Finds a factorial n and enables iteration control for division digits cancelling
long findFactorial(int n, int iterations)
{
    long factorial = n; 
    for (size_t i = iterations; i>1; i--)
    {
        factorial *= (n-1); 
        n--;       
    }
    return factorial; 
}


