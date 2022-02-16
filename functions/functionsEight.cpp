/*Write a method that calculates the sum of two very long positive integer numbers.
 The numbers are represented as array digits and the last digit (the ones) 
 is stored in the array at index 0. 
 Make the method work for all numbers with length up to 10,000 digits.*/

#include <iostream>
#include <vector>
#include <math.h>

unsigned long firstNumber, secondNumber, result;


std::vector<int> firstNumberVect, secondNumberVect;  

void printVector(std::vector<int> vector); 
long sumNumbers(std::vector<int>firstNumberVector,std::vector<int>secondNumberVector);
std::vector<int> deconstructNumber(long number);


int main(int argc, char const *argv[])
{
    firstNumber=32154;
    secondNumber=546841;

    printVector(deconstructNumber(firstNumber));
    printVector(deconstructNumber(secondNumber)); 

    std::cout<<sumNumbers(deconstructNumber(firstNumber),deconstructNumber(secondNumber))<<std::endl; 

    return 0;
}

std::vector<int> deconstructNumber(long number){

    std::vector<int> deconstructedNumber;
    int remainder = number; 

    //Deconstruct number into individual digits 
    while(number>0)
    {
        remainder=number%10; 
        deconstructedNumber.resize(deconstructedNumber.size()+1,remainder); 
        number/=10;
    }

    return deconstructedNumber; 
}


long sumNumbers(std::vector<int>firstNumberVector, std::vector<int>secondNumberVector)
{
    int result=0;
    int position=0;     

    while ((position<=firstNumberVector.size())&&(position<=secondNumberVector.size()))
    {
        result+=((firstNumberVector[position]+secondNumberVector[position])*pow(10,position)); 
        position++; 
        std::cout<<"*********** partial result: "<<result<<std::endl; 
    }
    

    return result; 
}
 
void printVector(std::vector<int> vector)
{
    for(int iPrinter=0; iPrinter<vector.size(); iPrinter++)
    {
        std::cout<<vector[iPrinter]<<" ";        
    }
    std::cout<<std::endl; 
} 