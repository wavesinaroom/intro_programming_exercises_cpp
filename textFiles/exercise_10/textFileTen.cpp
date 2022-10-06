/* 10. Write a program that extracts from an XML file the text only ("without the tags). Sample
   input file:

<?xml version="1.0"><student><name>Peter</name>
   <age>21</age><interests count="3"><interest> Games</interest><interest>C#</interest><interest>
   Java</interest></interests></student>

   Sample output:

   Peter
   21

   Games

   C#

   Java
*/

#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void get_words(std::string & input, std::vector<std::string> & words){
  
  const char closing_tag = '>';
  const char open_tag = '<';
  size_t char_count = 0;
  size_t open_tag_pos = 0; 
  size_t closing_tag_pos = 0;

  do{
    open_tag_pos = input.find(open_tag,closing_tag_pos);
    char_count = open_tag_pos-closing_tag_pos; 
    if (char_count>1) {
      words.push_back(input.substr(closing_tag_pos+1,char_count-1));
      char_count = 0;
    }
    ++closing_tag_pos;
    open_tag_pos = 0;
    closing_tag_pos = input.find(closing_tag, closing_tag_pos);
  } 
 while (closing_tag_pos!=input.length()-1); 

}

int main(int argc, char* argv[]){
  std::fstream read;
  read.open("input");
  std::string line;
  std::vector<std::string> words;
  if (read.is_open()) {
    while (std::getline(read, line)) {
      get_words(line,words);
    }
  } 
  read.close();
  for (std::string word : words) {
    std::cout<<word<<'\n';
  }
  return 0; 
}
