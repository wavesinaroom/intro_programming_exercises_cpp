/* Write a program that extracts from a text all dates written in format DD.MM.YYYY and
   prints them on the console in the standard format for Canada. Sample text:

   I was born at 14.06.1980. My sister was born at 3.7.1984. In 5/1999 I graduated my high
   school. The law says (see section 7.3.12) that we are allowed to do this (section 7.4.2.9).

   Extracted dates from the sample text:

   14.06.1980

   3.7.1984
*/

#include <iostream>
#include <vector>
#include <regex>

std::regex regular_expres("([0-9]{1}|[0-9]{2}).([0-9]{1}|[0-9]{2}).[0-9]{4}"); 
std::smatch matches;

struct Date
{
    int day;
    int month;
    int year;
};

void parseStringToDate(std::string inputString, Date outputDate)
{
    std::vector<int> dotsPositions;  

    for (size_t i = 0; i < inputString.length(); i++)
    {
        if (inputString[i] == '.')
        {
            dotsPositions.push_back(i); 
        }
    }

    outputDate.day = std::stoi(inputString.substr(0,dotsPositions[0]));
    outputDate.month = std::stoi(inputString.substr(dotsPositions[0]+1,dotsPositions[1]-dotsPositions[0]-1));
    outputDate.year = std::stoi(inputString.substr(dotsPositions[1]+1,dotsPositions[1]-inputString.length()));

    std::cout<<"Your date in Canadian format: "<<outputDate.month<<'/'<<outputDate.day<<'/'<<outputDate.year<<'\n'; 
}

int main(int argc, char const *argv[])
{
    Date date;
    std::string inputString = "I was born at 14.06.1980. My sister was born at 3.7.1984. In 5/1999 I graduated my high school. The law says (see section 7.3.12) that we are allowed to do this (section 7.4.2.9).";
    std::regex_search(inputString, matches, regular_expres); 

    for (auto && match : matches)
    {
        parseStringToDate(match, date); 
    }
    
    return 0;
}
