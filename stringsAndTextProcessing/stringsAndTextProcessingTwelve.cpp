/*Write a program that reads a number from console and prints it in 15-character field,
aligned right in several ways: as a decimal number, hexadecimal number, percentage,
currency and exponential (scientific) notation.*/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

void print_number_different_formats(int input_number)
{
    std::stringstream parsing_input;
    std::string output_string;

    parsing_input << input_number << " " << std::hex << input_number << std::dec << " " << std::put_money(input_number) << " " << input_number << "% " << std::scientific << static_cast<float>(input_number) << '\n';
    output_string = parsing_input.str();

    std::cout << output_string << '\n';
}

int main(int argc, char const *argv[])
{
    print_number_different_formats(12350);
    return 0;
}
