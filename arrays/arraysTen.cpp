#include <iostream>
#include <vector>
#include <math.h>
/*Write a program, which finds the most frequently occurring element in an array. 
Example: {4, 1, 1, 4, 2, 3, 4, 4, 1, 2, 4, 9, 3} à 4 (5 times).*/

std::vector <int> numberSeq; 

int digitRepetitionTimes = 0; 
int maxRepetitionTimes = 0;  
int digitPos, scanner, digit, sequenceSize; 

int main(int argc, char const *argv[])
{
    //Welcome message
    std::cout<<"I'll find the most annoying repetitive number of your vector"<<std::endl;
    std::cout<<"Also, I'm gonna try a different approach for this problem"<<std::endl; 
    std::cout<<"Please enter the vector size"<<std::endl; 

    //Vector init
    std::cin>>sequenceSize; 
    numberSeq.resize(sequenceSize); 

    //Sequence generator

    for ( digitPos = 0; digitPos < sequenceSize; digitPos++)
    {
        numberSeq.at(digitPos) = rand()%10;  
        std::cout<<numberSeq.at(digitPos)<<" "; 
    }

    std::cout<<std::endl; 

    //Loop goes position after position in the vector
    for ( digitPos = 0; digitPos < sequenceSize; digitPos++)
    {
        //digitRepetitionTimes initializes 1 as having the digit is one ocurrance
        digitRepetitionTimes = 1; 

        //Nested loop scans through all digits from the digit pos. 
        for (scanner=(digitPos+1); scanner<sequenceSize; scanner++)
        {
            if(numberSeq.at(digitPos)==numberSeq.at(scanner))
              digitRepetitionTimes++; 
        }

        //Checks max repetition digit plus its repetition number
        if(digitRepetitionTimes>maxRepetitionTimes)
        {
            maxRepetitionTimes = digitRepetitionTimes;
            digit = numberSeq.at(digitPos); 
        }
    }

    //Bye message
    std::cout<<"Number: "<<digit<<" is annoyingly "<<maxRepetitionTimes<<" times."<<std::endl; 

    return 0;
}
