#include <iostream>
#include <vector>
#include <math.h>

/* Write a program, which finds a subsequence of numbers with maximal sum.
 E.g.: {2, 3, -6, -1, 2, -1, 6, 4, -8, 8} à 11*/


//USED BOOK SOLUTION TWO CAUSE I THOUGHT IT'D BE INSTERESTRING TRYING IT
 int main(int argc, char const *argv[])
 {
     std::vector <int> numberSequence; 
     int vectorSize, sequencePos;  
     int sequenceSum = 0;
     int maxSum = 0; 
     int sequenceStart = 0; 
     int sequenceEnd = 0; 

     //Welcome message
     std::cout<<"I'm going to find the max sum subsequence in your vector"<<std::endl;
     std::cout<<"Please enter your vector size"<<std::endl;
     std::cin>>vectorSize; 

    //Vector initialization 
     numberSequence.resize(vectorSize);    

        
     //Vector numbers generator
     for ( sequencePos = 0; sequencePos < numberSequence.size(); sequencePos++)
     {
         numberSequence.at(sequencePos) = (rand()%100)-50; 
         std::cout<<numberSequence.at(sequencePos)<<" ";  
     }
     std::cout<<std::endl; 
    
    
    //Sum loop
    for (sequencePos = 0; sequencePos < numberSequence.size(); sequencePos++)
    {
        //Sums values and checks if is greater than maxSum
        sequenceSum += numberSequence.at(sequencePos); 
        if(sequenceSum>maxSum)
        {
            maxSum = sequenceSum; 
            sequenceEnd = sequencePos; 
        }
        //A negative result resets the sequence
        if(sequenceSum<0)
        {
            sequenceSum = 0; 
            sequenceStart = sequencePos+1; 
        }
    }
        
    std::cout<<"Total sum: "<<maxSum<<std::endl;
    std::cout<<"Sequence starts at: "<< sequenceStart<<std::endl;  
    std::cout<<"Sequence ends at: "<< sequenceEnd<<std::endl;

    //Prints max sum sequence
    for (int printIndex = sequenceStart; printIndex < sequenceEnd+1; printIndex++)
    {
         std::cout<<numberSequence.at(printIndex)<<" ";  
    }
      
     std::cout<<std::endl; 
     
     return 0;
 }
 