/*Write a method that finds the biggest element of an array.
 Use that method to implement sorting in descending order*/
 
#include <iostream>
#include <vector>
    
int lengthDifference=0; 

std::vector<int> numbersVector={1,87,54,38,165,6,18,8}; 
std::vector<int> resultVector; 

std::vector<int> sortVectorWithBiggestNumber(std::vector<int> &numbersVector); 
void printVectorContents(std::vector<int>vector); 

int main(int argc, char const *argv[])
{
    //SORTING METHODS WORKS, CAN'T PRINT THE VECTOR THOUGH -> ASK COMMUNITY
    printVectorContents(sortVectorWithBiggestNumber(numbersVector)); 
    return 0;
}


//Sorts vector decreasing order
std::vector<int> sortVectorWithBiggestNumber(std::vector<int> &numbersVector)
{
    int greatest=lengthDifference; 
    int swap; 

    if(lengthDifference==numbersVector.size())
        return numbersVector;  

    //Finds position of the greatest number in the vector
    for(int vectorPos=lengthDifference; vectorPos<numbersVector.size(); vectorPos++)
    {
        if(numbersVector[vectorPos]>numbersVector[greatest])
            greatest=vectorPos; 
    }
    
    //Swaps greatest number with first vector position
    swap=numbersVector[lengthDifference];
    numbersVector[lengthDifference]= numbersVector[greatest]; 
    numbersVector[greatest]=swap;
    
    //Shortens vector length each iteration
    lengthDifference++;

    //Recursion 
    return sortVectorWithBiggestNumber(numbersVector);   
} 

void printVectorContents(std::vector<int>vector)
{
    for(int iPrinter=0; iPrinter<vector.size(); iPrinter++)
    {
        std::cout<<vector[iPrinter]<<" ";
    }
    std::cout<<std::endl; 
} 
