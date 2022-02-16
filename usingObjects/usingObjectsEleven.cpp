/* You are given a sequence of positive integer numbers given as string of
numbers separated by a space. Write a program, which calculates their sum. 
Example: "43 68 9 23 318" à 461.*/

#include <iostream>
#include <vector>

std::string numbersStr = "43 68 9 23 318"; 

void sum_num_in_string(std::string string)
{
    std::vector<int> numbers; 
    std::vector<int> gapsPos; 
    char gap = ' ';
    int result=0;

    string.insert(0,1,gap);  
    string.push_back(gap);

    for (size_t i = 0; i < string.size(); i++)
    {
        if(string[i]==gap){
            gapsPos.push_back(i);
        }
    }

    for (size_t j = 0; j < gapsPos.size()-1; j++)
    {
        numbers.push_back(std::stoi(numbersStr.substr(gapsPos[j],(gapsPos[j+1]-gapsPos[j]-1)))); 
    }

    for (size_t k = 0; k < numbers.size(); k++)
    {
        result+=numbers[k]; 
    }

    std::cout<<"There you go sum of ints in string: "<<result<<'\n';    
}




int main(int argc, char const *argv[])
{
    sum_num_in_string(numbersStr);
    return 0;
}


