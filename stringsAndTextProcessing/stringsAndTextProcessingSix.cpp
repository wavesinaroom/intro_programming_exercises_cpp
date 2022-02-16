/* A text is given. Write a program that modifies the casing of letters to uppercase
at all places in the text surrounded by <upcase> and </upcase> tags.
Tags cannot be nested.

Example:

We are living in a <upcase>yellow submarine</upcase>. 
We don't have <upcase>anything</upcase> else.

Result:

We are living in a YELLOW SUBMARINE. We don't have ANYTHING else.
*/

#include <iostream>
#include <algorithm>

void change_to_caps(std::string input_string)
{
    int open_tag_pos, close_tag_pos;
    std::string text_to_change; 

    //Find tags position
    open_tag_pos = input_string.find("<upcase>");
    close_tag_pos = input_string.find("</upcase>");
    text_to_change = input_string.substr(open_tag_pos+8, close_tag_pos-(open_tag_pos+8));
    std::transform(text_to_change.begin(), text_to_change.end(), text_to_change.begin(), ::toupper); 

    std::cout<<input_string.substr(0, open_tag_pos-1)<<" "<<text_to_change<<input_string.substr(close_tag_pos+9, input_string.length())<<'\n';    
    
}

int main(int argc, char const *argv[])
{
    std::string text, substring_text;

    std::cout<<"Please enter your text"<<'\n';
    getline(std::cin, text); 

    change_to_caps(text); 
    return 0;
}
