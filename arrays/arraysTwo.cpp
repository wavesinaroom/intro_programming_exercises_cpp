#include <iostream>

using namespace std;

/*Write a program, which reads two arrays from the console and checks whether they are 
equal (two arrays are equal when they are of equal length and all of their elements,
 which have the same index, are equal).*/
int sizeArrayOne, sizeArrayTwo, inputIterator;
bool isSameDigit = true; 

 int main(int argc, char const *argv[])
 {
    //Welcome message arrays size input 
    cout<<"Pretty straight forward this time, we're gonna compare two arrays"<<endl;
    cout<<"Please enter number of digits for array one"<<endl;
    cin>>sizeArrayOne;
    cout<<"Please enter number of digits for array two"<<endl; 
    cin>>sizeArrayTwo;

    //Checks if array sizes are the same
    if (sizeArrayOne!=sizeArrayTwo)
    {
        cerr<<"Array one and two don't have the same size "<<endl; 
        return 0; 
    }
    
    //Array declaration
    int arrayOne[sizeArrayOne];
    int arrayTwo[sizeArrayTwo]; 

    //Array one digits input
    cout<<"Enter your digits for the first array"<<endl;

    for (size_t i = 0; i < sizeArrayOne; i++)
    {
        cin>>arrayOne[i];
        cout<<"What's your next digit "<<endl; 
    }
    
    //Array two digits input
    cout<<"Enter your digits for the second array"<<endl;

    for (size_t i = 0; i < sizeArrayTwo; i++)
    {
        cin>>arrayTwo[i];
        cout<<"What's your next digit "<<endl; 
    }

    //Comparison array
    for (size_t i = 0; i < sizeArrayTwo; i++)
    {
        if (arrayOne[i]!=arrayTwo[i])
        {
            isSameDigit = false; 
            break; 
        }
    }
    
    //Same array notification
    if(isSameDigit)
        cout<<"Your arrays contents are the same"<<endl; 
    else
        cout<<"Your arrays contents are not the same"<<endl; 
        
     return 0;
 }
