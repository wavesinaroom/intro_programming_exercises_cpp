/* A text file words.txt is given, containing a list of words, one per line. 
 * Write a program that deletes in the file text.txt all the words that occur in the other file.
 * Catch and handle all possible exceptions.
 */

#include <cctype>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> get_words(std::string & file){

  std::vector<std::string> words;
  std::fstream reader;
  reader.open(file, std::ios::in);
  std::string line;

  if (reader.is_open()) {
    while (std::getline(reader,line)) {
      words.push_back(line);
    } 
  }
  return words;
}

void delete_words (std::vector<std::string> & words_set, std::string input, std::string output){
  std::fstream reader, writer;
  reader.open(input, std::ios::in);
  writer.open(output,std::ios::out);
  std::string line;
  std::vector<std::string>::iterator it = words_set.begin();

}

int main(int argc, char * argv[]){

//"How much would wood a woodchuck chuck if a woodchuck could chuckwood?";
  std::string line= "How much would wood a woodchuck chuck if a woodchuck could chuckwood?";
  std::string word= "wood";
  std::string punctuation = " .,!?";
  size_t target = 0;
  target = line.find(word,target);
  char tail = line.at(target+word.length());
  int count = 0; 
  do{
    
    if (target == 0 && std::isalnum(tail)) {
      ++target;
      std::cout<<"can't delete"<<'\n';
      continue;
    }else if (target == line.length()-(word.length())&&isalnum(line.at(target-1))) {
      ++target;
      std::cout<<"can't delete"<<'\n';
      continue;
    }else if (std::isalnum(line.at(target-1))&&(bool)std::isalnum(tail)==1) {
      ++target;
      std::cout<<"can't delete"<<'\n';
      continue;
    }else {
      ++count; 
      ++target;
    }
    /*
    for (auto & character : punctuation) {
      if (character != tail) {
        ++target;
        continue;
      }
    }*/
    std::cout<<target<<'\n';
    std::cout<<line.at(target)<<'\n';
    std::cout<<tail<<'\n';
        
    //line.erase(--target, ++length);
    //++target;
    target = line.find(word,target);
    tail = line.at(target+word.length());
  }
  while (target!=line.npos);
 


  return 0;
  
}
