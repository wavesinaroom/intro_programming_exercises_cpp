/*Write a program that reads a string, reverse it and prints it to the console.
For example: "introduction" à "noitcudortni".*/

#include <iostream>

std::string input;
std::string output;

int main(int argc, char const *argv[])
{
    std::cout << "What's up! anything to get something weird" << '\n';
    std::cin >> input;

    for (int i = input.length() - 1; i >= 0; i--)
    {
        output += input[i];
    }

    std::cout << "Here you go: " << output << '\n';

    return 0;
}
