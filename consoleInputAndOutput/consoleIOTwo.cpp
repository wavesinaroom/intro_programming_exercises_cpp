#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

/* Write a program that reads from the console the radius "r" of a circle
and prints its perimeter and areas*/

int main(int argc, char const *argv[])
{
    float radius;

    cout << "Circle are and perimeter, pretty easy stuff" << endl;
    cout << "Please enter your radius" << endl;

    cin >> radius;

    cout << "Your circle perimeter is: " << (2*M_PI)*radius << endl;
    cout << "Your circle area is: " << M_PI*(pow(radius,2)) << endl; 

    return 0;
}
