#include <iostream>
#include <vector>

/*Write a program, which finds the maximal sequence of consecutive equal elements 
in an array. E.g.: {1, 1, 2, 3, 2, 2, 2, 1} à {2, 2, 2}. */

int vectorLength;
int digit; 
int sequenceLength = 1; 
int longestSequence; 
int sameDigitIndex; 

bool isSameDigit; 

std::vector <int> numbersSequence;

int main(int argc, char const *argv[])
{
    //Welcome message and input
    std::cout<<"Let's enter the length of the vector"<<std::endl;
    std::cin>>vectorLength;

    //Initializes vector size
    numbersSequence.resize(vectorLength); 

    //Input vector digits
    for (size_t i = 0; i < vectorLength; i++)
    {
        std::cout<<"Please enter your digits"<<std::endl; 
        std::cin>>digit; 
        numbersSequence.at(i) = digit; 
    }
    
    //Scans vector
    for (size_t i = 1; i < vectorLength; i++)
    {
        //Finds longest sequence
        if(numbersSequence.at(i)==numbersSequence.at(i-1))
            sequenceLength++;
        else
            sequenceLength = 1; 
        //Stores longest sequence        
        if(sequenceLength>longestSequence)
        {
            longestSequence = sequenceLength; 
            sameDigitIndex = i; 
        }
    }
    
    //End of process message
        std::cout<<"Your longest equal number sequence length is: "<<longestSequence<<std::endl; 
        std::cout<<"Longest sequence ends at: "<<sameDigitIndex<<std::endl;    
    
    //Prints longest sequence from sameDigitIndex backwards
    for (size_t i = 0; i < longestSequence; i++)
    {
        std::cout<<"---"<<numbersSequence.at(sameDigitIndex-i)<<std::endl; 
    }
    
    
    return 0;
}
