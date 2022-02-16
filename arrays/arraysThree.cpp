#include <iostream>
#include <stdlib.h>
#include <vector>

/* Write a program, which compares two arrays of type char lexicographically 
(character by character) and checks, 
which one is first in the lexicographical order.*/
    
std::vector<char> letters  = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','y','z'};
std::vector<char> charSetOne;
std::vector<char> charSetTwo; 

 int main(int argc, char const *argv[])
 {

    //Sets vectors to letter vector size
    charSetOne.resize(letters.size());
    charSetTwo.resize(letters.size());

    //Inputs random chars for array 1
    for (int i = 0; i < charSetOne.size(); i++)
    {
        charSetOne.at(i) = letters.at(rand()%25); 
    }
    
    //Inputs random chars for array 2
    for (int i = 0; i < charSetOne.size(); i++)
    {
        charSetTwo.at(i) = letters.at(rand()%25); 
    }

    //Prints, compares characters and outputs which comes first
    for (size_t i = 0; i < charSetOne.size(); i++)
    {
        std::cout<<"Char one: "<<charSetOne.at(i)<<" "<<"Char two: "<<charSetTwo.at(i)<<std::endl; 
        if(charSetOne.at(i)<charSetTwo.at(i))
            std::cout<<"*****"<<"Char two is greater"<<"*****"<<std::endl;
        else
            std::cout<<"*****"<<"Char one is greater"<<"*****"<<std::endl; 
    }

     return 0;
 }

 