/*6. Write a program that reads a list of names from a text file,
arranges them in alphabetical order, and writes them to another file.
The lines are written one per row.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[]) {

  std::fstream file_stream;
  std::string name;
  std::vector<std::string> name_list;

  file_stream.open("input.txt", std::ios::in);
  if(file_stream.is_open()) {
    while (std::getline(file_stream, name)) {
      name_list.push_back(name);
    }
  }
  file_stream.close();

  std::sort(name_list.begin(), name_list.end());

  file_stream.open("output.txt", std::ios::app);
  {
    if (file_stream.is_open()) {
      for(std::string name : name_list)
      {
        file_stream<<name<<'\n';
      }
    }
  }

  return 0;
}
