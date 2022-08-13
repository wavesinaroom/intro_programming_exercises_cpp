/* 3. Write a program that reads the contents of a text file
and inserts the line numbers at the beginning of each line,
then rewrites the file contents.
*/

#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char const *argv[]) {

  std::fstream text_file;
  text_file.open("text.txt", std::ios::in);
  std::vector<std::string> text_lines;
  std::string text_line;
  int line_number = 0;

  if(text_file.is_open())
  {
    while(std::getline(text_file,text_line))
    {
      text_lines.push_back(text_line);
      ++line_number;
    }
    text_file.close();
  }

  line_number = 0;
  text_file.open("text.txt", std::ios::out);
  if(text_file.is_open())
  {
    while (line_number<text_lines.size()) {
        text_file<<line_number+1<<' '<<text_lines[line_number]<<'\n';
        ++line_number;
    }
    text_file.close();
  }

  return 0;

}
