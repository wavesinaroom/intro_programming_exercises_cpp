#include <iostream>
#include <array>
#include <math.h>

/*  Write a program, which finds all prime numbers in the range [1…10,000,000].*/

bool primeNumberSequence[1000]; 
int primeNumber=2; 



int main(int argc, char const *argv[])
{
    
    //Loop walks through each position of the array
    for(primeNumber=2; primeNumber<sizeof(primeNumberSequence); primeNumber++)
    {    
       //Runs the marking loop only from prime numbers 
        if(primeNumberSequence[primeNumber]==false)
        {
            //Marks multiple numbers of prime numbers
            for (int iMultiple=primeNumber; iMultiple<sizeof(primeNumberSequence)-primeNumber; iMultiple++)
            {
                if((iMultiple%primeNumber==0)&&(iMultiple>primeNumber))
                    primeNumberSequence[iMultiple]=true; 
            }
        }
    }

    //Prime numbers array printer
    for(int iPrintArray=0; iPrintArray<sizeof(primeNumberSequence); iPrintArray++)
    {
        if(primeNumberSequence[iPrintArray]==false)
            std::cout<<iPrintArray<<" "; 
    }
    
    return 0;
}




