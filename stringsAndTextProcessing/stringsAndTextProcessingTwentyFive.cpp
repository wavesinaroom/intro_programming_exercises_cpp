/* Write a program that reads a list of words separated by commas from the console
and prints them in alphabetical order (after sorting)
*/

#include <iostream>
#include <vector>
#include <algorithm>

void orderWordsAlphabetical(std::string inputString, std::vector<std::string> words)
{
    std::string::size_type length = 0;
    std::string::size_type start = 0;  

    while (start<inputString.length())
    {
        while (inputString[start+length]!=','&&start+length<inputString.length())
        {
            ++length; 
        }
        words.push_back(inputString.substr(start,length));  
        start += length+2; 
        length = 0; 
    }
    
    std::sort(words.begin(), words.end()); 

    for (auto &&word : words)
    {
        std::cout<<word<<'\n'; 
    }
}

int main(int argc, char const *argv[])
{
    std::string inputString = "get, character, of, string";
    std::vector <std::string> words;

    orderWordsAlphabetical(inputString, words); 

    return 0;
}



