/*Write a program which by given two sides finds the hypotenuse of a right triangle.
 Implement entering of the lengths of the sides from the standard input,
  and for the calculation of the hypotenuse use methods of the class Math.*/

#include <iostream>
#include <math.h>

int sideOne, sideTwo;

int main(int argc, char const *argv[])
{
    std::cout << "Let's calculate the hypotenuse of your right triangle" << '\n';
    std::cout<<"Please enter your side, one by one"<<'\n';
    std::cin>>sideOne>>sideTwo; 

    std::cout<<"Your triangle hypotenuse is: "<<sqrt((pow(sideOne,2)+pow(sideTwo,2)))<<'\n'; 

    return 0;
}
