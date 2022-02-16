#include <iostream>

using namespace std;

/* Write a program that reads from the console a positive integer number N (N < 20) 
and prints a matrix of numbers as on the figures below:

N = 3       N = 4

1 2 3       1 2 3 4
2 3 4       2 3 4 5 
3 4 5       3 4 5 6
            4 5 6 7
*/

int size;
int row; 

int main(int argc, char const *argv[])
{
    //Input
    cout<<"Time to have some fun with loops"<<endl;
    cout<<"Type your square size"<<endl;
    cin>>size;

for (size_t row = 1; row <= size; row++)
{
    for (size_t i = row; i < (size + row); i++)
    {
        cout<<i<<" "; 
    }
    cout<<" "<<endl; 
}

    return 0;
}
