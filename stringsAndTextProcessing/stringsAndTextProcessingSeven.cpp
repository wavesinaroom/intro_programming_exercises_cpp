/*Write a program that reads a string from the console (20 characters maximum)
and if shorter complements it right with "*" to 20 characters.*/

#include <iostream>

int main(int argc, char const *argv[])
{
    std::string input_string; 

    std::cout<<"Please enter a string shorter than 20 characters"<<'\n';
    std::cin>>input_string; 

    int number_missing_char=0;

    if(input_string.length()<20)
    {
          
        input_string.append((20-input_string.length()),'*'); 
        std::cout<<input_string<<'\n';         
    
    }else if(input_string.length()>20)
    {
        std::cerr<<"Input string is too long."<<'\n';
    }else if(input_string.length()==20)
    {
        std::cout<<input_string<<'\n'; 
    }


    return 0;
}

