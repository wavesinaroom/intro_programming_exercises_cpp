/* Write a program that extracts from a text all words which are palindromes,
   such as ABBA", "lamal", "exe".*/

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

std::vector<std::string>checkPalindromes(std::vector<std::string> tokens)
{
    std::string reversedToken;
    std::vector<std::string> palindromes;  
    for (auto &&token : tokens)
    {
        reversedToken = token; 
        std::reverse(reversedToken.begin(), reversedToken.end());  
        if (token==reversedToken)
        {
            palindromes.push_back(token); 
        }
    }
    return palindromes;
}

int main(int argc, char const *argv[])
{
    std::string input = "lamal Anita lava la ABBA";
    std::istringstream iss(input); 
    std::vector<std::string> tokens(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>()); 
    std::vector<std::string> palindromes = checkPalindromes(tokens);  
    for (auto &&palindrome : palindromes)
    {
        std::cout<<palindrome<<'\n'; 
    }
    
    
    return 0;
}
