#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

/*Write a program, which uses a binary search in a sorted array of integer numbers 
to find a certain element.*/

std::vector <int> numberSequence;
int sequenceSize,number,halfPos,scanLength,min,max;

int main(int argc, char const *argv[])
{
    /*WAS CLOSE TO SOLVE IT BUT GOT STUCK WITH FIX WEIRD OUTPUT CASES.
    USE PSEUDOCODE FROM https://www.tutorialspoint.com/data_structures_algorithms/binary_search_algorithm.htm
    TO IMPROVE MY CODE*/

    //Welcome message
    std::cout<<"Hey! I'm gonna try to find a number in your random number sequence"<<std::endl;

    //Input
    std::cout<<"Please enter your sequence size"<<std::endl; 
    std::cin>>sequenceSize;

    numberSequence.resize(sequenceSize);

    //Random numbers generator
    for(int sequencePos=0; sequencePos<sequenceSize; sequencePos++)
    {
        numberSequence.at(sequencePos)=rand()%100+1; 
    }
    std::cout<<std::endl; 

    //Sorts number sequence
    std::sort(numberSequence.begin(),numberSequence.end()); 
    for(int sequencePos=0; sequencePos<sequenceSize; sequencePos++)
    {
        std::cout<<numberSequence.at(sequencePos)<<" "; 
    }
    std::cout<<std::endl;

    //Inputs number to be compared    
    std::cout<<"Please enter your number"<<std::endl;
    std::cin>>number; 
    
    //Compares number with number in the middle of the vector
    min = 1;
    max = numberSequence.size(); 
    while(number!=numberSequence.at(halfPos))
    {
        //Sets halfPos        
        halfPos=(min+((max-min)/2));

        //Set min and max depending on < o > halfPos comparison
        if(number>numberSequence.at(halfPos))
        {
            //Sets scanlength
            min=halfPos+1;
        }else if(number<numberSequence.at(halfPos))
        {
            //Sets scanlength
            max=halfPos-1;  
        }    

    }
    

    std::cout<<"Your number is at position: "<<halfPos<<std::endl; 
    return 0;
}


