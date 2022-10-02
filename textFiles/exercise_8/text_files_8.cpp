/* 8. Write the previous program so that it changes only the whole words (not parts of the
   word).*/

#include <iostream>
#include <string>
#include <fstream>

void changeAWord (std::string & input, std::string & what, std::string & with){
  size_t  found=input.find(what);
  while (found!=input.npos) {
   if (found==0||found==input.length()-what.length()||(input.at(found-1)==' ')&&(input.at(found+what.length()+1==' '))){
      input.replace(found,what.length(),with);
    }  
    ++found;
    found=input.find(what,found);
  }
}

int main (){
  std::fstream reader;
  std::fstream writer;

  reader.open("./input", std::ios::in);
  writer.open("./output", std::ios::out);
  std::string temporal;
  std::string what="butter";
  std::string with="YEAH!";
  
  if (reader.is_open()) {
    while (std::getline(reader,temporal)) {
      if (writer.is_open()) {
        changeAWord(temporal, what, with);
        writer<<temporal<<'\n';
      }
    }
  }
  return 0;
}

