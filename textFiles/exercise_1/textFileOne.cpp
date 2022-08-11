/* Write a program that reads a text file and prints its odd lines
 on the console. */

#include <iostream>
#include<fstream>

int main(int argc, char const *argv[]) {
  std::fstream text_file;
  text_file.open("text.txt", std::ios::in);
  std::string text_line;
  int line_number=0;
  while (std::getline(text_file, text_line)) {
    ++line_number;
    if (line_number%2!=0) {
      std::cout <<line_number<<' '<< text_line<<'\n';
    }
  }
  text_file.close();
  return 0;
}
