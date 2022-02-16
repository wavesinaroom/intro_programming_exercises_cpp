#include <iostream>

using namespace std;

/*Write a program that reads from the console a series of integers 
and prints the smallest and the largest of them.*/

int main(int argc, char const *argv[])
{
    int minNumber=0;
    int maxNumber=0;
    int numberSetSize;
    //Array size input
    cout<<"Type the array size to find its greatest and least numbers"<<endl;
    cin>>numberSetSize;

    int numberSet[numberSetSize];
    //Array input
    cout<<"Now, type your numbers in the set"<<endl;

    for (size_t i = 0; i < numberSetSize; i++)
    {
        cin>>numberSet[i]; 
    }
    //Array comparison
    for (size_t i = 0; i < numberSetSize; i++)
    {
        if(numberSet[i]>maxNumber)
            maxNumber=numberSet[i];  
        if(numberSet[i]<minNumber)
            minNumber=numberSet[i]; 
    }
    cout<<"Max Number: "<<maxNumber<<endl;
    cout<<"Min Number: "<<minNumber<<endl;  
    return 0;
}
