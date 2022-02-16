/* Write a method that takes as a parameter the name of a binary file,
reads the content of the file and returns it as an array of bytes.
Write a method that writes the file content to another file.
Compare both files.*/

#include <iostream>
#include <fstream>

//SOLUTION BASED ON: https://www.cplusplus.com/reference/ostream/ostream/write/

void copy_binary_file(std::string incoming_file_path, std::string output_file_path)
{
    std::ifstream read_file(incoming_file_path, std::ifstream::binary);
    std::ofstream write_file(output_file_path, std::ofstream::binary); 

        if(read_file)
            std::cout<<"all characters read successfully"<<'\n'; 
        else
            throw 0; 

        read_file.seekg(0, read_file.end);
        int length = read_file.tellg();
        read_file.seekg (0, read_file.beg);

        char * buffer = new char [length]; 

        read_file.read(buffer, length);  
        write_file.write(buffer, length); 

    write_file.close(); 
    read_file.close(); 
    delete[] buffer; 
}

int main(int argc, char const *argv[])
{
    try
    {
        copy_binary_file("test_file.dat", "copy_file.dat"); 
    }
    catch(int file_reading_error)
    {
        std::cerr << "File couldn't be read" << '\n';
    }
    
    return 0;
}




