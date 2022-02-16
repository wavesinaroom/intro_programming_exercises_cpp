/*Create a method GetMax() with two integer (int) parameters, that returns maximal 
of the two numbers. Write a program that reads three numbers from the console and 
prints the biggest of them. Use the GetMax() method you just created. 
Write a test program that validates that the methods works correctly.*/

#include <iostream>
    
int firstNumber, secondNumber, thirdNumber;

int getMax(int firstNumber, int secondNumber); 

int main(int argc, char const *argv[])
{
    //Welcome message and input
    std::cout<<"Hi! We're going to find your largest number "<<std::endl; 
    std::cout<<"Please enter three numbers one by one "<<std::endl;

    std::cin>>firstNumber;
    std::cin>>secondNumber;
    std::cin>>thirdNumber;
    
    //Output
    std::cout<<"Your largest number is: "<<getMax(firstNumber,getMax(secondNumber,thirdNumber))<<std::endl; 
    return 0;
}

//Finds the largest of two given numbers
int getMax(int firstNumber, int secondNumber)
{
    int largestNumber;
    
    firstNumber>secondNumber?largestNumber=firstNumber:largestNumber=secondNumber;
        
    return largestNumber;   
} 


