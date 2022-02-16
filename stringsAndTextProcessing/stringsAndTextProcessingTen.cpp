/* Write a program that extracts from a text all sentences that contain a particular
word. We accept that the sentences are separated from each other by the character "."
and the words are separated from one another by a character which is not a letter.
Sample text:

We are living in a yellow submarine. We don't have anything else.
Inside the submarine is very tight. So we are drinking all the day.
We will move out of it in 5 days.

Sample result:

We are living in a yellow submarine.
We will move out of it in 5 days.
*/

#include <iostream>
#include <vector>

void trim_string (std::string input_text, std::string word)
{
    std::vector<std::string> sentences;

    int start_sentence_pos = 0;
    int end_sentence_pos;

    for (size_t i = 0; i < input_text.length(); i++)
    {
        if (input_text[i]=='.')
        {
            end_sentence_pos = i; 
            sentences.push_back(input_text.substr(start_sentence_pos, (end_sentence_pos-start_sentence_pos)+1)); 
            start_sentence_pos=end_sentence_pos+2; 
        }
    }
    
    for (auto &&sentence : sentences)
    {
        if (sentence.find(word)!=sentence.npos)
        {
            std::cout<<sentence<<'\n'; 
        }
    }
    
}

int main(int argc, char const *argv[])
{
    std::string input_text = "We are living in a yellow submarine. We don't have anything else. Inside the submarine is very tight. So we are drinking all the day. We will move out of it in 5 days."; 
    
    trim_string(input_text, "are"); 
    return 0;
}

