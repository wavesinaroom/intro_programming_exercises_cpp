/*Write a program that reads a string from the console and prints in alphabetical 
order all letters from the input string and how many times each one of 
them occurs in the string. */

#include <iostream>
#include <vector>
#include <map>
#include <string>

std::vector<int> letterCounter(29);
std::map <char, int> alphabetCounter;

void populateAlphabetMap()
{
    char letter;

    for (letter = 65; letter <= 122; letter++)
    {
        if (letter>90 && letter<97)
        {
            continue;
        }
        alphabetCounter.insert(std::pair<char, int>(letter, 0)); 
    }
}

void countLetterAppearance(std::string input){
    for (auto && pair : alphabetCounter)
    {
        for (size_t i = 0; i < input.length(); i++)
        {
            if(input[i]==pair.first){
                pair.second++;
            }
        }

        for (size_t j = 1; j <=pair.second; j++)
        {
            std::cout<<pair.first;
        }
    }
    std::cout<<'\n'; 
}

int main(int argc, char const *argv[])
{
    populateAlphabetMap(); 

    std::string inputText = "Ornare porta lobortis consectetur, imperdiet magna justo, hac volutpat ut suspendisse accumsan leo tempor";
    countLetterAppearance(inputText); 
    return 0;
}




