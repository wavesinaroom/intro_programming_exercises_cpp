/* Write a program that counts how many times each word from a given text file words.txt appears in it. The result words should be ordered by their number of occurrences in the text.*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>


int main(){

  std::string word;
  std::ifstream fs("./mytext.txt");
  std::map<std::string, int> dictionary;
  std::map<std::string, int>::iterator mit;

  if(fs.is_open()){
    mit = dictionary.begin();
    while(std::getline(fs, word, ' ')){
      mit = dictionary.find(word);
      if(mit==dictionary.end())
        dictionary.insert(std::make_pair(word,1));
      else
        ++mit->second;
    }
    fs.close();
  }



  return 0;
}
