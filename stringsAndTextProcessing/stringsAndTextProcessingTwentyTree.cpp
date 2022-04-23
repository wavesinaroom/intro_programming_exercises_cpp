/*Write a program that reads a string from the console and prints in alphabetical
order all words from the input string and how many times each one of them occurs 
in the string.
*/

#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <iterator>


//TAKEN FROM: WWW.CPLUSPLUS.COM/FORUM/BEGINNER/99191/
void splitString(const std::string &inputString, std::vector<std::string> &words)
{
    std::string::size_type start = 0; 
    std::string::size_type last = inputString.find_first_of(" "); 
    while (last!=std::string::npos)
    {
        if (last>start)
        {
            words.push_back(inputString.substr(start, last-start));
        }
        start = ++last; 
        last = inputString.find_first_of(" ", last); 
    }
    words.push_back(inputString.substr(start));     
}

void checkWordsDict(const std::string &inputString, std::vector<std::string> &words, std::map <std::string, int> dictionary)
{
    
    const int DICT_ENTRY_START = 0; 
    std::map<std::string, int>::iterator mapIterator; 

    splitString(inputString, words);
    dictionary.insert(std::pair<std::string, int>(words[0], DICT_ENTRY_START)); 
    

    for (auto &&word : words)
    {
        for (mapIterator = dictionary.begin(); mapIterator != dictionary.end(); ++mapIterator)
        {
            if(word == mapIterator->first){
                ++mapIterator->second;
            }else{
                dictionary.insert(std::pair<std::string, int>(word, DICT_ENTRY_START)); 
            }
        }
    }

    for (mapIterator = dictionary.begin(); mapIterator != dictionary.end(); ++mapIterator)
    {
        std::cout<< mapIterator->first<<'\t'<<mapIterator->second<<'\n'; 
    }
}

int main(int argc, char const *argv[])
{
    std::string inputString = "Betty Botter bought some butter But she said the butter’s bitter If I put it in my batter, it will make my batter bitter";
    std::vector<std::string> words;
    std::map<std::string,int> dictionary; 

    checkWordsDict(inputString, words, dictionary); 
    
    
    return 0;
}
