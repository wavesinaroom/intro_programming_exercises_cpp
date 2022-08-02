#include<iostream>
#include "Fraction.h"

int main(int argc, char const *argv[])
{
    Fraction fraction = Fraction();
    std::string input = "6545/35456";
    Fraction::parseString(fraction, input);
    return 0;
}
