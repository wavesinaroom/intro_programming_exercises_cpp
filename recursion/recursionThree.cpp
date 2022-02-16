/*Write a program to generate and print all combinations with duplicates
of k elements from a set with n elements. Sample input:
n = 3
k = 2
(1 1), (1 2), (1 3), (2 2), (2 3), (3 3)*/

// BOOK SOLUTION

#include <iostream>
#include <vector>

std::vector<int> numbersSet; 

void print_vector(std::vector<int> vector)
{
    for (auto &&item : vector)
    {
        std::cout << item << " ";
    }
    std::cout << '\n';
}

void variations(int maxNumber, int maxPosition, int startNumber = 1, int currentPosition = 1)
{
 
    for (size_t i = startNumber; i <= maxNumber; i++)
    {
        numbersSet[currentPosition - 1] = i;
        if (currentPosition != maxPosition)
        {
            variations(maxNumber, maxPosition, startNumber, currentPosition + 1);
            startNumber++;
        }
        else
        {
            print_vector(numbersSet);
        }
    }
}

int main(int argc, char const *argv[])
{
    int k, n;

    std::cout << "Please enter k" << '\n';
    std::cin >> k;

    std::cout << "Please enter n" << '\n';
    std::cin >> n;

    std::vector<int> numbersSet(n);
    variations(k, n);

    return 0;
}