/*Write a method that returns the English name of the last digit of a given number. 
Example: for 512 prints "two"; for 1024 à "four".*/

#include <iostream>

std::string printLastDigit(int number); 

int main(int argc, char const *argv[])
{
    int number;

    //Welcome message - input
    std::cout<<"Hey! Do you know wanna now your last digit in letters?"<<std::endl;
    std::cout<<"Please enter your number: "<<std::endl; 
    std::cin>>number; 

    //Output
    std::cout<<"Your last digit is: "<<printLastDigit(number)<<std::endl; 
    return 0;
}

std::string printLastDigit(int number)
{
    switch (number%10)
    {
    case 0:
        return "Zero";
        break;
    case 1:
        return "One";
        break;
    case 2:
        return "Two";
        break;
    case 3:
        return "Three";
        break;
    case 4:
        return "Four";
        break;
    case 5:
        return "Five";
        break;
    case 6:
        return "Six";
        break;
    case 7:
        return "Seven";
        break;
    case 8:
        return "Eight";
        break;
    case 9:
        return "Nine";
        break;
    default:
        std::cout<<"Something went wrong"<<std::endl; 
        break;
    }
    
}