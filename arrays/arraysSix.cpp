#include <iostream>
#include <vector>

//PROBLEM NOT SOLVED COULDN'tEVEN UNDERSTAND THE SOLUTION FROM THE BOOK

/*Write a program, which finds the maximal sequence of increasing elements in an array arr[n]. 
It is not necessary the elements to be consecutively placed. 
E.g.: {9, 6, 2, 7, 4, 7, 6, 5, 8, 4} à {2, 4, 6, 8}. */

std::vector <int> numberSequence;
std::vector <int> longestSequence; 

int maxSum, vectorSize, longestSequenceIndex;


int main(int argc, char const *argv[])
{
    //Welcome message 
    std::cout<<"Pretty similar to previous exercise. Let's get started with your vector length"<<std::endl;
    
    //Vector init
    std::cin>>vectorSize;
    numberSequence.resize(vectorSize); 

    //Values input
    std::cout<<"Please enter your digits one by one "<<std::endl; 

    for(int input = 0; input<numberSequence.size(); input++)
    {
        std::cin>>numberSequence.at(input); 
    }

    //Max sum sequence scanner
    for (int vectorPos = 0; vectorPos < numberSequence.size(); vectorPos++)
    {
        //Adds up digits from a fixed position in the vector
        int sum = 0; 
        for (size_t scanner = vectorPos; scanner < numberSequence.size(); scanner++)
        {
            sum += numberSequence.at(scanner); 
        }

        //Compares sum with max sum and declares longest sequence index 
        if (sum>maxSum)
        {
            maxSum = sum; 
            longestSequenceIndex = vectorPos; 
        }
        
        std::cout<<"Sequence sum: "<<sum<<std::endl; 
    }
    
    



    return 0;
}
