/*Write a method that finds how many times certain number can be found in a given array.
Write a program to test that the method works correctly.*/

#include <iostream>
#include <vector>

std::vector<int> numbersSequence={3,2,5,1,8,4,5,8,4,1,8,2,9,5}; 
int number;  

int findNumberOccurrance(std::vector<int> numbersSequence, int number);

int main(int argc, char const *argv[])
{
    //Welcome message - input
    std::cout<<"Hey! Check out how many times your number appears in the array"<<std::endl;
    std::cout<<"Enter your number please"<<std::endl; 
    std::cin>>number; 
    
    //Output
    std::cout<<"Your number appears "<<findNumberOccurrance(numbersSequence, number)<<" times"<<std::endl; 
    
    return 0;
}

int findNumberOccurrance(std::vector<int> numbersSequence, int number)
{
    //Sets a counter
    int counter=0; 
    //Checks number through array - increases counter if occurance is found
    for(int vectorPos=0; vectorPos<numbersSequence.size(); vectorPos++)
    {
        if(numbersSequence[vectorPos]==number)
            counter++; 
    }
    return counter; 
}

