/*Write a program that replaces all hyperlinks in a HTML document 
consisting of <a href="…">…</a> and hyperlinks in "forum" style,
which look like [URL=…]…[/URL].

<p>Please visit <a href="https://softuni.bg">our site</a> to choose a
training course. Also visit <a href="www.devbg.org">our forum</a> to discuss 
the courses.</p>

<p>Please visit [URL=https://softuni.bg]our site[/URL] to choose a training course.
Also visit [URL=www.devbg.org]our forum[/URL] to discuss the courses.</p>
*/

//NEED TO LEARN ABOUT POINTERS TO PROPERLY REPLACE SUBSTRINGS

#include <iostream>
#include <regex>
#include <string.h>

std::regex first_regex("<a.{7}");
std::regex second_regex("\">"); 
std::regex end_regex("\"</a>"); 

std::string change_address_format(std::string input_string)
{
    std::regex_replace(input_string, first_regex, "[URL="); 
    std::regex_replace(input_string, second_regex, "]");
    std::regex_replace(input_string, end_regex, "[/URL]");

    std::cout<<input_string<<'\n'; 
}

int main(int argc, char const *argv[])
{
    std::string input_string = "<p>Please visit <a href=\"https://softuni.bg\">our site</a> to choose a training course. Also visit <a href=\"www.devbg.org\">our forum</a> to discuss the courses.</p>";
    change_address_format(input_string);

    return 0;
}


