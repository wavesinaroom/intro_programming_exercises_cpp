// Write a program to simulate n nested loops from 1 to n. 

#include<iostream>

void simulate_nested_loops(int n)
{
    if (n==1)
    {
        return; 
    }

    for (size_t i=n; i >0 ; i--)
    {
        std::cout<<"*"<<" ";
    }
    std::cout<<"-"<<'\n'; 

    simulate_nested_loops(n-1); 
}

int main(int argc, char const *argv[])
{
    simulate_nested_loops(20); 
    return 0;
}


