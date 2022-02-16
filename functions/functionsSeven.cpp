/* Write a method that prints the digits of a given decimal number in a reversed order. 
For example 256, must be printed as 652.*/

#include <iostream>
#include <vector>
#include <tgmath.h>

int number;
int divider=10; 

std::vector<int> reversedNumber; 

std::vector<int> reverseNumber(int number); 


int main(int argc, char const *argv[])
{
    //Welcome message - input
    std::cout<<"Yo! Check it out! I can print any number in reversed order"<<std::endl;
    std::cout<<"Enter your number"<<std::endl;
    std::cin>>number; 
    

    //Stores reversed number in vector
    reversedNumber=reverseNumber(number); 
    
    //Ouput
    std::cout<<"Here you go: "; 
    //Vector printer
    for(int iPrinter=0; iPrinter<reversedNumber.size(); iPrinter++)
    {
        std::cout<<reversedNumber[iPrinter]; 
    }
    std::cout<<std::endl; 

    return 0;
}



std::vector<int> reverseNumber(int number){

    std::vector<int> reversedNumber;
    int remainder = number; 

    //Deconstruct number into individual digits 
    while(number>0)
    {
        remainder=number%10; 
        reversedNumber.push_back(remainder);
        number/=10; 
    }
    
    return reversedNumber; 
}


