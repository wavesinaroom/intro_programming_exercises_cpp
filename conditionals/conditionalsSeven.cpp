#include <iostream>

using namespace std;

/*Write a program that finds the biggest of 5 numbers*/

int main(int argc, char const *argv[])
{
    //Used an array to prevent messy code
    int numbers[5]; 
    int greatest;

    cout<<"Let's sort some numbers " <<endl;
    cout<<"Please enter five digits " <<endl;

    //Iterates through array to input numbers
    for (int i = 0; i <sizeof(numbers)/sizeof(numbers[0]); i++)
    {
        cin>>numbers[i]; 
    }
    
    //Finds greatest digit
    for (int i = 0; i <(sizeof(numbers)/sizeof(numbers[0])-1); i++)
    {
        if(numbers[i]<numbers[i+1])
        {
            greatest = numbers[i+1];
            cout<<greatest<<endl;
        }
        else
        {
            greatest = numbers[i];
            cout<<greatest<<endl;
        }
    }
    
    cout<<"The greatest digit: " << greatest << endl; 
    

    return 0;
}
