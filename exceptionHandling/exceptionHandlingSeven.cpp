/* Write a program that takes a positive integer from the console 
and prints the square root of this integer.
If the input is negative or invalid print "Invalid Number" in the console. 
In all cases print "Good Bye".*/

#include <iostream>
#include <random>

void calculate_square_root(std::string numberStr)
{
    //If numberStr is not a number, stoi throws a std::invalid_argument
    if(std::stoi(numberStr)<0)
    {
        throw "Invalid number";
    }else{
        std::cout<<"Your result! "<<sqrt(std::stoi(numberStr))<<'\n'; 
    }

}

int main(int argc, char const *argv[])
{
    std::string numberStr;

    std::cout<<"Hey! I want to calculate your number square root! Please enter your number"<<'\n';
    std::cin>>numberStr;

    try
    {
        calculate_square_root(numberStr); 
    }
    catch(const char * invalid_num_message)
    {
        std::cerr << "You can't enter a negative number" << '\n';
    }
    //C++ DOESN'T HAVE A FINALLY CONSTRUCT.
    // https://www.stroustrup.com/bs_faq2.html#finally


    return 0;
}
