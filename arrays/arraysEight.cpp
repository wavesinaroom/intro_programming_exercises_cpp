#include <iostream>
#include <vector>
#include <math.h>

/*Sorting an array means to arrange its elements in an increasing (or decreasing) order. 
Write a program, which sorts an array using the algorithm "selection sort".*/

std::vector <int> numbersVector; 

int vectorSize, vectorPos, swap, minPos;

int main(int argc, char const *argv[])
{
    //Welcome message
    std::cout<<"Hey! This is a selection sort program with random numbers from 1 to 100"<<std::endl;
    std::cout<<"Please enter the size of the vector"<<std::endl; 

    //Vector size and initialization
    std::cin>>vectorSize;
    numbersVector.resize(vectorSize); 

    //Random numbers in vector
    for (vectorPos = 0; vectorPos < vectorSize; vectorPos++)
    {
        numbersVector.at(vectorPos) = rand()%100; 
    }
    
    //Prints array
    for ( vectorPos = 0; vectorPos < vectorSize; vectorPos++)
    {
        std::cout<<numbersVector.at(vectorPos)<<" ";
    }
    std::cout<<std::endl; 
    
    //Selection sort algorithm
    for (vectorPos = 0; vectorPos < vectorSize; vectorPos++)
    {
        //Finds smallest value in the array    
        minPos = vectorPos; 
        for (int scanIndex=vectorPos+1;scanIndex<vectorSize;scanIndex++)
        {   
            if(numbersVector.at(scanIndex)<numbersVector.at(minPos))
                minPos = scanIndex;  
        }
        
        //Swaps min value and position 
        if(numbersVector.at(minPos)<numbersVector.at(vectorPos))
        {
            swap = numbersVector.at(vectorPos);
            numbersVector.at(vectorPos) = numbersVector.at(minPos);
            numbersVector.at(minPos) = swap; 
        }
    }
        
    //Prints sorted array
    for ( vectorPos = 0; vectorPos < vectorSize; vectorPos++)
    {
        std::cout<<numbersVector.at(vectorPos)<<" ";
    }
    
    std::cout<<std::endl; 



    return 0;
}
