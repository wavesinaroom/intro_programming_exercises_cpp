/*Write a method that checks whether an element, from a certain position in an array 
is greater than its two neighbors. Test whether the method works correctly.*/

#include <iostream>
#include <vector>

int numberPos; 

std::vector<int> numberSequence={1,2,5,8,4,3,8,3,5,4,1,0};

bool checkNumberNeighbours(std::vector<int> numberSequence, int position);


int main(int argc, char const *argv[])
{
    //Welcome message and input
    std::cout<<"Hey! Check if your number's greater than its neighbours"<<std::endl;
    std::cout<<"Enter the position in the array"<<std::endl;
    std::cin>>numberPos; 

    //Output
    std::cout<<"(1=true, 0=false): "<<checkNumberNeighbours(numberSequence,numberPos)<<std::endl;    
    return 0;
}

bool checkNumberNeighbours(std::vector<int> numberSequence, int position)
{
    //Returns whether neighbours are greater than number at given position
    return ((numberSequence[position]>numberSequence[position+1])&&(numberSequence[position]>numberSequence[position-1]));
}
