/* A dictionary is given, which consists of several lines of text.
Each line consists of a word and its explanation, separated by a hyphen:

.NET – platform for applications from Microsoft
CLR – managed execution environment for .NET
namespace – hierarchical organization of classes

Write a program that parses the dictionary and then reads words from the console
in a loop, gives an explanation for it or writes a message on the console that
the word is not into the dictionary.*/

#include <iostream>
#include <vector>

struct DictionaryEntry
{
    std::string word;
    std::string definition; 
}; 

std::vector<DictionaryEntry> parse_dictionary(std::vector<std::string>inputEntries)
{
    std::vector<DictionaryEntry> parsedEntries; 

    for (size_t i = 0; i < inputEntries.size(); i++)
    {
        parsedEntries.push_back(DictionaryEntry());     
        parsedEntries[i].word = inputEntries[i].substr(0, (inputEntries[i].find("-")-1));
        parsedEntries[i].definition = inputEntries[i].substr((inputEntries[i].find("-")+2), (inputEntries[i].size()-1));
    
    }
    return parsedEntries; 
}

void find_definition(std::string input_word, std::vector<DictionaryEntry> dictionary)
{
    bool word_found=false; 
    
    for (size_t i = 0; i < dictionary.size(); i++)
    {
        if (input_word == dictionary[i].word)
        {
            std::cout<<dictionary[i].word<<": "<<dictionary[i].definition<<'\n'; 
            word_found=true;
        }
    }

    if(word_found==false)
    {
        std::cout<<"Word not found"<<'\n'; 
    }    
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> myDictionary;

    myDictionary.push_back(".NET - platform for applications from Microsoft");
    myDictionary.push_back("CLR - managed execution environment for .NET");
    myDictionary.push_back("namespace - hierarchical organization of classes");

    find_definition("CLR", parse_dictionary(myDictionary));  
    return 0;
}

