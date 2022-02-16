/*Write a program to generate all variations with duplicates of n elements class k. 
Sample input:
n=3 k=2
Sample output:
(1 1), (1 2), (1 3), (2 1), (2 2), (2 3), (3 1), (3 2), (3 3)
Think about and implement an iterative algorithm for the same task.*/

//SOLUTION BASED ON: https://stackoverflow.com/questions/25070766/nested-for-loops-recursion

#include <iostream>
#include <sstream>
#include <string>

void generate_number_sequence(int n, const std::string& prefix)
{
    //Reaches bottom 
    if(n!=0)
    {
        for (size_t i = 1; i <= 3 ; i++)
        {
            std::ostringstream os;
            os<<prefix<<i<< ' ';  
            generate_number_sequence(n-1, os.str()); 
        }
    }
    else std::cout<<prefix<<'\n'; 
}

int main(int argc, char const *argv[])
{
    generate_number_sequence(2, ""); 
    return 0;
}

