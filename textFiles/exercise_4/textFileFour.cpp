/* 4. Write a program that compares two text files with
the same number of rows line by line and prints the number of equal
and the number of different lines.*/

#include <iostream>
#include <fstream>

int main(int argc, char const *argv[]) {

  std::fstream text_one_stream;
  text_one_stream.open("text_one.txt", std::ios::in);

  std::fstream text_two_stream;
  text_two_stream.open("text_two.txt", std::ios::in);

  std::string text_one_line, text_two_line;

  int line_count = 0;
  int same_line_count = 0;

  if (text_one_stream.is_open() && text_two_stream.is_open()) {
    while (std::getline(text_one_stream, text_one_line)&&std::getline(text_two_stream, text_two_line)) {
      ++line_count;
      if(text_one_line==text_two_line)
        ++same_line_count;
    }
  }

  std::cout << line_count << '\n';
  std::cout << "Number of same lines: "<< same_line_count << '\n';
  std::cout << "Number of different lines: " << line_count-same_line_count<< '\n';
  return 0;
}
