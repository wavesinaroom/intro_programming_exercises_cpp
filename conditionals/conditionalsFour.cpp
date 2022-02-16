#include <iostream>

using namespace std;

/*Sort 3 real numbers in descending order. Use nested if statements*/

int main(int argc, char const *argv[])
{
    int firstNumber;
    int secondNumber;
    int thirdNumber;
    
    cout<<"This is pretty simple number ordering algorythm"<<endl;
    cout<<"Type your first number"<<endl;
    cin>>firstNumber;
    cout<<"Type your second number"<<endl;
    cin>>secondNumber;
    cout<<"Type your third number"<<endl;
    cin>>thirdNumber;


    //Checks if first number is the smallest
    if(firstNumber<secondNumber)
    {
        //Double-checks if first number is less than third
        if(firstNumber<thirdNumber)
        {
            //Checks if second is less or greater the third when first is the smallest
            if (thirdNumber<secondNumber)
                cout<<secondNumber<<" "<<thirdNumber<<" "<<firstNumber<<endl;
            else
                cout<<thirdNumber<<" "<<secondNumber<<" "<<firstNumber<<endl; 
        }else if(thirdNumber<firstNumber){
            //Checks if first is less or greater the third when first is the smallest
            if(firstNumber<secondNumber)
                cout<<firstNumber<<" "<<secondNumber<<" "<<thirdNumber<<endl;
            else
                cout<<secondNumber<<" "<<firstNumber<<" "<<thirdNumber<<endl;
        }
    }else{
        //Double-checks if second number is less than third
        if (secondNumber<thirdNumber)
        {
            //Checks if third is less or greater than first when second is the smallest 
            if (thirdNumber<firstNumber)
                cout<<firstNumber<<" "<<thirdNumber<<" "<<secondNumber<<endl; 
            else
                cout<<thirdNumber<<" "<<firstNumber<<" "<<secondNumber<<endl; 
        }
        
    }

    //To be continued..
    
    return 0;
}
