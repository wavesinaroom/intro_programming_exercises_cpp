   /*9. Write a program that deletes all the odd lines of a text file*/

#include <cstddef>
#include <iostream>
#include <string>
#include <fstream>

int main(){
  std::size_t count = 1;
  std::fstream reader;
  std::fstream writer;
  reader.open("./input", std::ios::in);
  writer.open("./output", std::ios::out);
  std::string temp;

  if (reader.is_open()) {
    while (std::getline(reader,temp)) {
      if ((count%2)!=0&&writer.is_open()) {
        writer<<temp<<'\n';
      }
      ++count;
    }
  }
}
