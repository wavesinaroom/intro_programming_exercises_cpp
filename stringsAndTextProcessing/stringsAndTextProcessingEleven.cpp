/* A string is given, composed of several "forbidden" words separated by commas.
Also a text is given, containing those words. Write a program that replaces the 
forbidden words with asterisks. Sample text:

Microsoft announced its next generation C# compiler today. 
It uses advanced parser and special optimizer for the Microsoft CLR.

Sample string containing the forbidden words: "C#,CLR,Microsoft".

Sample result:

********* announced its next generation ** compiler today.
It uses advanced parser and special optimizer for the ********* ***.*/

#include <iostream>
#include <vector>

void change_to_forbidden(std::string input_text, std::string forbidden_words_input)
{
    
    std::vector<std::string> forbidden_words_set; 
    int forbidden_word_end;
    int forbidden_word_begin=0; 

    if (forbidden_words_input[forbidden_words_input.length()-1]!=',');
    {
        forbidden_words_input.append(",");
    }
    
    for (size_t i = 0; i < forbidden_words_input.length(); i++)
    {
        if (forbidden_words_input[i]==',')
        {
            forbidden_word_end = i; 
            forbidden_words_set.push_back(forbidden_words_input.substr(forbidden_word_begin, (forbidden_word_end-forbidden_word_begin))); 
            forbidden_word_begin=forbidden_word_end+1; 
        }
    } 
    


    for (int j=0; j<forbidden_words_set.size(); j++)
    {

        for (size_t k = 0; k < input_text.length(); k++)
        {
            if(input_text.substr(k,forbidden_words_set[j].length())==forbidden_words_set[j])
            {
                input_text.erase(k,forbidden_words_set[j].length());
                input_text.insert(k,forbidden_words_set[j].length(), '*');
            }
        }
    }
    std::cout<<input_text<<'\n'; 
}

int main(int argc, char const *argv[])
{
    change_to_forbidden("Microsoft announced its next generation C# compiler today","C#,CLR,Microsoft"); 
    return 0;
}
