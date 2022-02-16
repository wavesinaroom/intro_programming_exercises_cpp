#include <iostream>

using namespace std;

/*Write a program that reads and integer n from the console.
After that reads n numbers from the console and prints their sum*/

int main(int argc, char const *argv[])
{
    int n;
    int sum = 0; 
    int inputNumber;

    cout << "This one looks fun to do! " << endl;
    cout << "Enter a number, don't put a large number, you'll thank me ;) " << endl;
    cin >> n;
    cout << "No enter " << n << " digits, one after the other" << endl; 

    for (size_t i = 0; i < n; i++)
    {
        cin >> inputNumber;
        sum += inputNumber;
    }
    
    cout << "The sum off ALL your number is: " << sum << endl;
    cout << "Bye bye!" << endl; 

    return 0;
}
