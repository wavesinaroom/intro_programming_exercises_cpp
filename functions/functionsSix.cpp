/*Write a method that returns the position of the first occurrence of an element
 from an array, such that it is greater than its two neighbours simultaneously.
  Otherwise the result must be -1.*/

#include <iostream>
#include <vector>

int number; 

std::vector<int> numberSequence={1,2,5,8,4,3,8,3,5,4,1,0};  

int returnFirstOccurencePosition(std::vector<int> numberSequence, int number);

int main(int argc, char const *argv[])
{
    std::cout<<"Hey! Pick a number to see its first occurrence such it's greater than neighbouring numbers (-1 means no number)"<<std::endl; 
    std::cin>>number; 
    std::cout<<"Number that's greater than its neighbour appears at: "<<returnFirstOccurencePosition(numberSequence, number)<<std::endl; 
    return 0;
}

int returnFirstOccurencePosition(std::vector<int> numberSequence, int number)
{
    //Scans through the vector
    for(int numberSeqPos=1; numberSeqPos<(numberSequence.size()-1); numberSeqPos++)
    {
        //Checks first occurence element
        if((numberSequence[numberSeqPos]==number)&&(numberSequence[numberSeqPos]>numberSequence[numberSeqPos-1])&&(numberSequence[numberSeqPos]>numberSequence[numberSeqPos+1])) 
        {
            return numberSeqPos; 
        }
    }
    //Returns -1 if there's such number in the sequence
    return -1; 
}
