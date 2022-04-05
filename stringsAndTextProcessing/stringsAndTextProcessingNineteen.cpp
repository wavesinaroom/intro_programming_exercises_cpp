/*Write a program that extracts all e-mail addresses from a text.
These are all substrings that are limited on both sides by text end or separator
between words and match the shape <sender>@<host>…<domain>. Sample text:

Please contact us by phone (+001 222 222 222) or by email at example@gmail.com
or at test.user@yahoo.co.uk. This is not email: test@test. This also: @gmail.com.
Neither this: a@a.b.

Extracted e-mail addresses from the sample text

example@gmail.com

test.user@yahoo.co.uk*/

// REGEX HAS BEEN USED IN DIFFERENT WEBSITES, DOESN'T WORK HERE THOUGH
// TRIED TO CREATE A RAGES BUT FAILES

#include <iostream>
#include <regex>
#include <string.h>

int main(int argc, char const *argv[])
{
    std::string input_string = "Please contact us by phone (+001 222 222 222) or by email at example@gmail.com or at test.user@yahoo.co.uk. This is not email: test@test. This also: @gmail.com. Neither this: a@a.b";
    std::regex regex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    std::smatch match;

    std::regex_search(input_string, match, regex);
    std::cout << "Extracted emails: " << '\n';

    for (auto &&email : match)
    {
        std::cout << email << '\n';
    }

    return 0;
}
