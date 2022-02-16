#include <iostream>

using namespace std;

/*Write a program that reads from the console five integers and prints 
the greatest of them*/

int main(int argc, char const *argv[])
{
    int numbers[5]; 
    int greatest; 


    for (size_t i = 0; i < (sizeof(numbers)/sizeof(numbers[0])); i++)
    {
        cout << "Please enter your " << i << " number " <<endl;
        cin >> numbers[i];
    }
    
    greatest = numbers[0]; 

    for (size_t i = 0; i < (sizeof(numbers)/sizeof(numbers[0])); i++)
    {
        (greatest > numbers[i+1]) ? greatest = greatest : greatest = numbers[i+1];
    }


    cout << "Your greatest number is: " << greatest << endl; 
    

    return 0;
}

    

