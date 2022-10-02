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
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]){

  //look for the > symbol that precedes a letter or a number. Store > position in a variable
  //track the word till reaching < character. That will be the string length
  //cut the string with string.sbtr as it takes position and length as parameters
  
  std::string input="<?xml version=\"1.0\"><student><name>Peter</name>";
  const char target_tag = '>';
  const char open_tag = '<';
  size_t char_count = 0;
  size_t tag_pos = 0; 
  std::vector<std::string> words; 
  

 while (tag_pos!=input.length()-1) {
  tag_pos = input.find(target_tag, tag_pos);
  if ((input.at(tag_pos)+1)!=open_tag) {
  char_count = 0;  
   while (input.at(tag_pos+char_count+1)!=open_tag) {
    ++char_count; 
   } 
  words.push_back(input.substr((tag_pos+1), char_count));
  }
  std::cout<<tag_pos<<'\n';
  ++tag_pos;
 } 

 for (std::string word : words) {
  std::cout<<word<<'\n';
 }
  return 0; 
}
