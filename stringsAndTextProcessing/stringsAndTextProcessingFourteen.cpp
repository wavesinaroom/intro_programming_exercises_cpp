/*Write a program that reverses the words in a given sentence without changing
punctuation and spaces. For example: "C# is not C++ and PHP is not Delphi" à
"Delphi not is PHP and C++ not is C#".*/

#include <iostream>
#include <vector>

void reverse_string(std::string input_string)
{
    std::vector<std::string> words;
    int word_start = 0;
    int word_end = 0;

    int i = 0;
    while (i != input_string.length())
    {

        if (i == input_string.length() - 1)
        {
            word_end = i;
            words.push_back(input_string.substr(word_start, word_end - word_start));
        }

        if (input_string[i] == ' ')
        {
            word_end = i;
            words.push_back(input_string.substr(word_start, word_end - word_start));
            word_start = word_end;
        }
        i++;
    }

    for (int j = words.size() - 1; j >= 0; j--)
    {
        std::cout << words[j] << " ";
    }

    std::cout << '\n';
}

int main(int argc, char const *argv[])
{
    reverse_string("C# is not C++ and PHP is not Delphi");
    return 0;
}
