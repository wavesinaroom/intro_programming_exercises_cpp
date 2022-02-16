#include <iostream>

using namespace std;

/* Write a program that calculates the sum (with precision of 0.001)
of the following sequence 1 + 1/2 +1/3 + 1/4...*/

int main(int argc, char const *argv[])
{
    float currentSum;
    float previousSum; 
    int divisor = 1; 
    cout << "This exercise looks terrible but it's actually easy " << endl; 
    
    while((currentSum-previousSum)>0.001)
    {
        previousSum = currentSum; 
        currentSum = (1/divisor) + (1/(divisor+1)); 
        divisor++; 
    }
    
    cout << "Sum of the sequence with a 0.001 pecision is: " << currentSum;
    return 0;
}
