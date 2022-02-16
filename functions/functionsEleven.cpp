/*Write a program that solves the following tasks:

-     Put the digits from an integer number into a reversed order.

-     Calculate the average of given sequence of numbers.

-     Solve the linear equation a * x + b = 0.

Create appropriate methods for each of the above tasks.

Make the program show a text menu to the user. By choosing an option of that menu, the user will be able to choose which task to be invoked.

Perform validation of the input data:

-     The integer number must be a positive in the range [1…50,000,000].

-     The sequence of numbers cannot be empty.

-     The coefficient a must be non-zero.
*/

#include <iostream>
#include<vector>

void reverseIntegerDigits(int number); 
void calculateAverage(std::vector<int>numberSequence);
void solveLinearEquation(int a, int b); 

void reverseIntegerDigits()
{
    //Variables
    int number; 
    std::vector<int> reversedNumber;
    int iterator=0; 

    //Console messages
    std::cout<<"Great, now please enter your number "<<'\n';
    std::cin>>number;
    if (number<1||number>50000000)
    {
        std::cout<<"Your number's too large of small to reverse"<<'\n'; 
        std::exit; 
    }
     
    std::cout<<"Here you go your reversed number "<<'\n'; 

    //Reverses integer
    while (number>0)
    {
        reversedNumber.push_back(number%10);
        number/=10;
        std::cout<<reversedNumber[iterator]<<" "; 
        iterator++; 
    }
    std::cout<<'\n'; 
}

void calculateAverage()
{
    //Variables
    int result=0;
    int numSeqSize=0;
    std::vector<int>numberSequence;

    //Console messages
    std::cout<<"How many digits does your sequence have? "<<'\n';
    std::cin>>numSeqSize; 
    if (numSeqSize==0)
    {
        std::cout<<"You don't have enough digits to calculate"<<'\n';
        std::exit; 
    }
    
    numberSequence.resize(numSeqSize); 

    std::cout<<"Awesome! Please enter your numbers one by one"<<'\n';

    for (auto& inputNumber:numberSequence)
    {
        std::cin>>inputNumber; 
    }
    
    //Calculates average
    for(auto& number : numberSequence)
    {
        result+=number; 
    }
    
    std::cout<<"Your average is: "<<result/numberSequence.size()<<'\n'; 
}

void solveLinearEquation()
{
    int a,b;

    std::cout<<"Great choice, please enter coefficient a, then intercept b"<<'\n';
    std::cin>>a>>b;
    
    if (a==0)
    {
        std::cout<<"Coefficient number a mustn't be 0 "<<'\n'; 
        std::exit; 
    }
    
    std::cout<<"Solution for your linear equation is: "<<-b/a<<'\n'; 
} 


int main(int argc, char const *argv[])
{
    //Welcome message
    std::cout<<"Hi! Long time no see, please enter a number to choose an option from the menu"<<'\n';
    std::cout<<"1. Reverse integer digits   2. Calculate the average    3. Solve Linear equation"<<'\n';

    //Input
    int choice=0;
    std::cin>>choice; 
    
    switch (choice)
    {
    case 1:
        reverseIntegerDigits(); 
        break;
    case 2:
        calculateAverage(); 
        break;
    case 3:
        solveLinearEquation(); 
        break; 
    default:
        std::cout<<"That's not a choice I'm afraid "<<'\n';
        return 0; 
        break;
    }        

    return 0;
}

