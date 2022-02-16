#include <iostream>

using namespace std;

/* Write a program that checks if a given number n (1 < n < 100)
is a prime number (i.e. it is divisible without a remainder only 
to itself and to itself and 1)*/

int main(int argc, char const *argv[])
{
    int number;
    bool isPrime;

    cout << "Check your prime number ;) " << endl;
    cin >> number;
     

    for(int i = 0 ; i < number; i++ )
    {
        if(((6* i - 1) == number) ^ ((6*i + 1) == number))
            isPrime = true; 
    }   
    cout << "Is your number prime? : " << isPrime << endl;

    return 0;
}

