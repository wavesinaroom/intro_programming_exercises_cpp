#include <iostream>

using namespace std;

/* Write a program that shows the sign (+) or (-) of the product
of three real numbers, without calculating it. Use a sequence of
if operators*/

int main(int argc, char const *argv[])
{
    int firstNumber;
    int secondNumber;
    int thirdNumber;

    cout << "Do you have a negative product or a positive one? " <<endl;
    cout << "Just put your numbers, we'll see " << endl;
    cout << "First number: " << endl;
    cin >> firstNumber;
    cout << "Second number: " << endl;
    cin >> secondNumber;
    cout << "Third number: " << endl;
    cin >> thirdNumber; 

    if(firstNumber==0||secondNumber==0||thirdNumber==0)
        cout<<("Your product is definitely 0") << endl; 
    
    if(firstNumber<0)
    {
        if((secondNumber<0&&thirdNumber>0)^(secondNumber>0&&thirdNumber<0))
            cout<<"Your product is positive"<<endl;
        if((secondNumber<0&&thirdNumber<0)^(secondNumber>0&&thirdNumber>0))
            cout<<"Your product is negative"<<endl;
    }else
    {
        if((secondNumber<0&&thirdNumber>0)^(secondNumber>0&&thirdNumber<0))
            cout<<"Your product is negative"<<endl;
        if((secondNumber<0&&thirdNumber<0)^(secondNumber>0&&thirdNumber>0))
            cout<<"Your product is positive"<<endl;
    }
    
    return 0;
}
