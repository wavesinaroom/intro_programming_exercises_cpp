/*Write a program which calculates the area of a triangle with the following given:
-     three sides;
-     side and the altitude to it;
-     two sides and the angle between them in degrees.*/

#include <iostream>
#include <math.h>

#define PI 3.1416

float calculate_triangle_area(float side_one, float side_two, float side_three)
{
    //Heron's Formula
    float s = (side_one+side_two+side_three)/2; 
    return sqrt(s*((s-side_one)*(s-side_two)*(s-side_three))); 
}

float calculate_triangle_area(float side_one, float altitude)
{
    //Normal area formula
    return (side_one*altitude)/2; 
}

float calculate_triangle_area_side_angle(float side_one, float side_two, float angle)
{
    //1/2(side*side)sin(angle)
    return ((side_one*side_two)/2)*sin(angle*PI/180);  
}

int main(int argc, char const *argv[])
{
    std::cout<<"V1. Triangle area is: "<<calculate_triangle_area(10,15,20)<<'\n';
    std::cout<<"V2. Triangle area is: "<<calculate_triangle_area(10,15)<<'\n';
    std::cout<<"V3. Triangle area is: "<<calculate_triangle_area_side_angle(10,15,60)<<'\n';
    return 0;
}

