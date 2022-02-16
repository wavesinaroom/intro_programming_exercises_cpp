#include <iostream>
#include <vector>

/*Write a program, which creates an array containing all Latin letters.
 The user inputs a word from the console and as result the program prints 
 to the console the indices of the letters from the word.*/

    std::vector <char> alphabet {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    std::string word; 

int main(int argc, char const *argv[])
{

    //Welcome message and input

    std::cout<<"Finally we're doing some stuff with char only "<<std::endl; 
    std::cout<<"Just type a word and I'll find the char number in the alphabet"<<std::endl; 
    std::cin>>word;

    //Compares words letters with the alphabet array
    for (int wordPos=0; wordPos<word.length(); wordPos++)
    {
        for (int alphabetPos=0; alphabetPos<alphabet.size(); alphabetPos++)
        {
            if(word[wordPos]==alphabet.at(alphabetPos))
                std::cout<<alphabetPos+1<<" ";  
        }
    }
    
 

    return 0;
}
