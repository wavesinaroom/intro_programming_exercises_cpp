/* Write a program that gets from the user the full path to a file 
(for example C:\Windows\win.ini), reads the content of the file and prints it
to the console. Find in MSDN how to us the System.IO.File.
ReadAllText(…) method. Make sure all possible exceptions will be caught and a
user-friendly message will be printed on the console.*/

//File not found
//File could not be opened
//Line could not be read 

#include <iostream>
#include <fstream>

void read_file(std::string file_path)
{
    std::fstream file_stream (file_path, std::ios_base::in | std::ios_base::binary);
    std::string file_line;

    if (!file_stream.good())
    {
        throw "File not found"; 
    }

    if (file_stream.is_open()) 
    {
        while (std::getline(file_stream, file_line)) 
        {
            std::cout<<file_line<<'\n';
            
            if(file_stream.eof())
                std::cout<<"File read\n"; 
            else
                std::cout<<std::endl; 
                throw "File could not be read"; 
        }
    }else
    {
        throw "File could not be open";  
    }

    file_stream.close(); 
}

int main(int argc, char const *argv[])
{
    try
    {
        read_file("Whatever"); 
    }
    catch(const char* file_not_found)
    {
        std::cout<<"Your file was not found"<<'\n';
    }
    catch(const char* file_could_not_be_read)
    {
        std::cout<<"Your file could not be read"<<'\n';
    }
    catch(const char* file_could_not_be_open)
    {
        std::cout<<"Your file could not be open"<<'\n';     
    }

    return 0;
}
