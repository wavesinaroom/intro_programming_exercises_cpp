/*11. Write a program that deletes all words that begin with the word "test".
The words will contain only the following chars: 0...9, a...z, A...Z*/

#include <cctype>
#include <cstddef>
#include <iostream>
#include <string>
#include <fstream>

void delete_words(std::string & input, std::string & what){

  std::size_t index = 0; 
  std::size_t length;
  const char gap = ' ';
  bool erase_it = false;
  
  do{
    erase_it = true;
    index = input.find(what, index); 
    length = input.find(gap, index);
    if (length == input.npos) {
      length = input.length();
    }
    for (auto & ch : input.substr(index, length-index)) {
      if (std::isalnum(ch)==0) {
       erase_it = false; 
      }
    }
    if (erase_it) {
      input.erase(index, length-index+1);
      length = 0;
    }else {
      index = length;
    }
  }
  while(input.find(what,index)!=input.npos);
}

int main (int argc, char * argv[]){
  std::fstream reader, writer;
  reader.open("./input", std::ios::in);
  writer.open("./output", std::ios::out);
  std::string line; 
  std::string what = "test";
  if (reader.is_open()) {
    while (std::getline(reader,line)) {
      delete_words(line, what);
      writer<<line<<'\n';
    }
  }
  reader.close();
  writer.close();
  return 0;
}

