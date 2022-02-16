/*Write a program which creates 10 objects of type Cat, gives them names CatN,
where N is a unique serial number of the object,
and in the end call the method SayMiau() for each of them. 
For the implementation use the namespace CreatingAndUsingObjects.*/

#include <iostream>
#include <math.h>

#include "usingObjectsSeven.cpp"

creating_objects::Cat cats [10]; 

int main(int argc, char const *argv[])
{
    for (size_t i = 0; i < 10; i++)
    {
        cats[i].name = std::to_string(rand()%100+1); 
    }
    
    for (auto &&cat : cats)
    {
        cat.say_miau(); 
    }
    
    return 0;
}

