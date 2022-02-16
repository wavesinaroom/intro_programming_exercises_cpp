/*Search for information in Internet and define your own class for exception
FileParseException. The exception has to contain the name of the processed file and
the number of the row where the problem is occurred. Add appropriate constructors
in the exception. Write a program that reads integers from a text file.
If the during reading a row does not contain an integer throw FileParseException
and pass it to the calling method.*/

#include <iostream>
#include <error.h>
#include <fstream>
#include <sstream>

class FileParseException: public std::exception
{
    public:
        FileParseException(int errorCode, const std::string &message) noexcept;
        virtual ~FileParseException()=default;
        virtual const char* what() const noexcept override; 
    private:
        int errorCode;
        std::string m_message;
};

FileParseException::FileParseException(int errorCode, const std::string &message) noexcept:
                    errorCode(errorCode), m_message(message)
{
    
}

const char *FileParseException::what() const noexcept
{
    return this->m_message.c_str(); 
}

void extract_integers(std::string file_path)
{
    int row = 0;
    int number = 0; 

    std::ifstream read_file(file_path, std::ios_base::in);
    std::string buffer; 

    if (read_file.is_open())
    {
        while (!read_file.eof())
        {
            row++;
            std::getline(read_file, buffer);
            std::istringstream string_parser{buffer}; 
            string_parser>>number; 
            if (string_parser.fail())
            {
                std::stringstream message;
                message <<"File: " <<file_path<<" at line: "<<row<<" could not be parsed.";
                throw FileParseException(-EINVAL, message.str());  
            }  
        }
    }   
    read_file.close(); 
}

int main(int argc, char const *argv[])
{
   try
   {
        extract_integers("test_file.txt"); 
   }
   catch(const FileParseException &e)
   {
       std::cout <<"File parsing error: "<<'\n'<<e.what()<<'\n'; 
   }
   
    return 0;
}
