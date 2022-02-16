#include <iostream>
#include <vector>

/*Write a program to find a sequence of neighbor numbers in an array, 
which has a sum of certain number S.
 Example: {4, 3, 1, 4, 2, 5, 8}, S=11 à {4, 2, 5}.*/

//BOOK SOLUTION TWO IS MORE ELEGANT AND MADE TRY A NEW APPROACH :)
//DID IT WITH A FIXED VECTOR BUT CAN BE ADJUSTED TO RANDOM NUMBERS AND USER INPUT

int main(int argc, char const *argv[])
{
    std::vector <int> numberSequence = {4, 3, 1, 4, 2, 5, 8};
    int sumResult = 11;
    int sum = 0; 

    int vectorIndexPos, vectorSize;

    //Welcome message
    std::cout<<"Hey! I find sequences which have S a sum result"<<std::endl;

    //Finds sequence which result is sumResult
    vectorIndexPos=1; 
    while ((numberSequence.at(vectorIndexPos)+numberSequence.at(vectorIndexPos-1)+numberSequence.at(vectorIndexPos+1))!=sumResult&&vectorIndexPos<numberSequence.size()-2)
    {
        vectorIndexPos++; 
    }
    
    std::cout<<"Sequence starts at: "<<vectorIndexPos-1<<std::endl; 
    std::cout<<"Sequence ends at: "<<vectorIndexPos+1<<std::endl; 
    std::cout<<"Your sequence ;) : "<<std::endl; 

    //Prints sequence
    for (int printIndex=vectorIndexPos-1; printIndex<vectorIndexPos+2; printIndex++)
    {
        std::cout<<numberSequence.at(printIndex)<<" "; 
    }
    
    std::cout<<std::endl; 
    
    return 0;
}
