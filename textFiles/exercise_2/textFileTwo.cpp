/* 2. Write a program that joins two text files and records the results
in a third file.*/

#include <iostream>
#include <fstream>

void writeTextInFile(std::string input_file, std::string output)
{
  std::fstream text_file_reader;
  std::fstream text_file_writer;
  std::string text_line;

  text_file_reader.open(input_file,std::ios::in);
  text_file_writer.open(output,std::ios::app);

  if (text_file_reader.is_open()) {
    while(std::getline(text_file_reader, text_line ))
    {
      text_file_writer<<text_line<<'\n';
    }
    text_file_reader.close();
    text_file_writer.close();
  } 
}

void printTextFromFileToConsole(std::string input_file)
{
  std::fstream text_file_reader;
  std::string text_line;

  text_file_reader.open(input_file, std::ios::in);
  if (text_file_reader.is_open()) {
    while(std::getline(text_file_reader, text_line ))
    {
      std::cout << text_line << '\n';
    }
    text_file_reader.close();
  }
}

int main(int argc, char const *argv[]) {
  writeTextInFile("text_one.txt", "text_three.txt");
  writeTextInFile("text_two.txt", "text_three.txt");
  printTextFromFileToConsole("text_three.txt");
  return 0;
}
