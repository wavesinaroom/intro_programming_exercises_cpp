/*Write a method ReadNumber(int start, int end) that reads an integer from the console 
in the range [start…end]. In case the input integer is not valid or it is not in the
required range throw appropriate exception.
Using this method, write a program that takes 10 integers a1, a2, …, a10 such that 
1 < a1 < … < a10 < 100.*/

#include <iostream>
#include <stdexcept>
#include <math.h>

void read_number(int min_range, int max_range, int number)
{
    //Throws exception if ranges are inverter
    if (min_range>max_range)
    {
        throw 0; 
    }
    
    //Use a std library exception 
    if (number<min_range||number>max_range)
    {
        throw std::out_of_range("Number out of range"); 
    }
}

int main(int argc, char const *argv[])
{
    try
    {
        for (size_t i = 0; i < 10; i++)
        {
            read_number(1,100,rand()%100);
        }
    }
        
    
    catch(int inverted_ranges)
    {
        std::cout<<"Max and Min range numbers are inverted"<<'\n'; 
    }

    return 0;
}
