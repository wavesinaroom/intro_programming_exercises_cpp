/*Write a method that takes as a parameter the name of a text file, reads the file
and returns its content as string. What should the method do if and exception is
thrown?*/

//SOLUTION BASED ON: 
//https://www.udacity.com/blog/2021/05/how-to-read-from-a-file-in-cpp.html

#include <iostream>
#include <fstream>
#include <string>

void read_file(std::string file_name)
{
    std::ifstream myfile;
    myfile.open(file_name); 
    std::string myline;
    
    if(myfile.is_open())
    {
        while (myfile.good())
        {
            std::getline(myfile, myline);
            std::cout<<myline<<'\n'; 
        }
    }else
    {
        throw "File error"; 
    }
}

int main(int argc, char const *argv[])
{
    try
    {
        //Change the file name to see the exception in action
        read_file("test_file.txt"); 
    }

    catch(const char * file_error)
    {
        std::cout<<"File reading error. File does not exist or it's corrupt"; 
    }
    return 0;
}

