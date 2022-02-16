/* Write a program that detects how many times a substring is contained in the text.
For example, let’s look for the substring "in" in the text:

We are living in a yellow submarine. We don't have anything else. Inside the submarine is very tight. So we are drinking all the day. We will move out of it in 5 days.

The result is 9 occurrences.*/

//CODE TAKES DIFFERENCE BETWEEN CAPS

#include <iostream>
#include <algorithm>

int count_substrings(std::string text, std::string substring_text)
{
    int count = 0; 

    int substring_length = substring_text.length();  

    for (size_t i = 0; i < text.length(); i++)
    {
        if(text.substr(i, substring_length)==substring_text)
        {
            count++;
        }
    }
    return count; 
}

int main(int argc, char const *argv[])
{
    std::string text, substring_text;

    std::cout<<"Please enter your text"<<'\n';
    getline(std::cin, text); 

    std::cout<<"Please enter your substring"<<'\n';
    getline(std::cin, substring_text); 

    std::cout<<substring_text<<" appears "<<count_substrings(text, substring_text)<<" time(s)."<<'\n'; 

    return 0;
}

