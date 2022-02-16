#include <iostream>

using namespace std;

/* Write a program that reads an integer number n from the console and 
prints all numbers in that range */

int main(int argc, char const *argv[])
{
    int n;
    int sum = 0;

    cout << "This one's piece of cake " << endl;
    cout << "Enter a number, then you see the sum of its cycles " << endl;
    cin >> n;

    for (size_t i = 0; i <= n; i++)
    {
        sum += i;  
    }
    
    cout << "Sum result: " << sum << endl; 


    return 0;
}


