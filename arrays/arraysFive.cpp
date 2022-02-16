#include <iostream>
#include <vector>
/* Write a program, which finds the maximal sequence of 
consecutively placed increasing integers. Example: {3, 2, 3, 4, 2, 2, 4} à {2, 3, 4}.*/

/*Can't find out why I get out of range exception 
when the sequence is right at the end of the vector*/

int endSequenceIndex;
int vectorSize;
int increasingSequenceLength = 1; //Number of digits in the sequence  
int longestSequenceLength; 
int longestSequenceStart; 

bool isConsecutiveNumber;

std::vector <int> numberSequence; 

int main(int argc, char const *argv[])
{
    //Welcome message
    std::cout<<"Task is similar to the previous one, albeit I wanna try another solution"<<std::endl;
    std::cout<<"Let's get started! Please enter the size of the vector"<<std::endl;

    //Vector initialization
    std::cin>>vectorSize; 
    numberSequence.resize(vectorSize);

    //Number sequence input
    std::cout<<"Now, enter your digits one by one"<<std::endl; 
    int i = 0;
    while (i<numberSequence.size())
    {
        std::cin>>numberSequence.at(i);
        i++; 
    }
    
    //Scans the vector to find the increasing sequence 
    for (size_t j = 0; j < numberSequence.size()-1; j++)
    {
        //while loop scans the vector and breaks iterations when the consecutive sequence stops
        int scannerIndex = j;
            std::cout<<"Scanner starts at : "<<scannerIndex<<" "; 

        while ((numberSequence.at(scannerIndex)+1)==numberSequence.at(scannerIndex+1)&&(scannerIndex<numberSequence.size()-2)&&((increasingSequenceLength)<(numberSequence.size()-j)))
        {
            increasingSequenceLength++; 
            scannerIndex++; 
            std::cout<<"Scanner index: "<<scannerIndex<<" "; 
        }
    
        std::cout<<"Increasing sequence length: "<<increasingSequenceLength<<std::endl; 
        //Checks if the current sequence is the longest. Sets longest sequence start point
        if(increasingSequenceLength>longestSequenceLength)
        {
            longestSequenceLength = increasingSequenceLength;
            longestSequenceStart = j; 
        }

        //Resets increasing sequence when scan and longest number check are done
        increasingSequenceLength = 1;  
    }
    
    std::cout<<"Longest sequence: "<<longestSequenceLength<<std::endl; 
    
    //Print longest consecutively numbers system
    for (size_t k = 0; k < longestSequenceLength; k++)
    {
        std::cout<<numberSequence.at(k+longestSequenceStart)<<std::endl; 
    }
    return 0;
}
