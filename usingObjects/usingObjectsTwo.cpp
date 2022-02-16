/*Write a program, which generates and prints on the console 10 random 
numbers in the range [100, 200].*/

#include <iostream>
#include <random>

int main(int argc, char const *argv[])
{
    std::cout<<"I'm gonna generate 10 random numbers from 100 to 200"<<'\n';
    std::cout<<"Here we go!"<<'\n';

    std::default_random_engine numberGenerator; 
    std::uniform_int_distribution<int> range (100,200); 
    

    for (size_t i = 0; i < 10; i++)
    {
        std::cout<<range(numberGenerator)<<'\n'; 
    }
    

    return 0;
}
