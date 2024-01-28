/* Write a program to remove from a sequence all the integers, which appear odd number of times. For instance,for the sequence {4, 2, 2, 5, 2, 3, 2, 3, 1, 5, 2, 6, 6, 6} the output would be {5, 3, 3, 5}.*/

#include <iostream>
#include <unordered_map>
#include <vector>

int main(){

  std::unordered_map<int, int> map;
  std::unordered_map<int, int>::iterator mit = map.begin();
  std::vector<int> sequence = {4, 2, 2, 5, 2, 3, 2, 3, 1, 5, 2, 6, 6, 6};
  std::vector<int>::iterator sit = sequence.begin();

  for(; sit!=sequence.end(); ++sit){
    mit = map.find(*sit);
    if(mit!=map.end())
      ++mit->second;
    else
      map.insert(std::make_pair(*sit,1));
  }

  mit = map.begin();
  while(mit!=map.end()){
    if(mit->second%2==1)
      mit = map.erase(mit);
    else
      ++mit;
  }

  sit = sequence.begin();
  while(sit!=sequence.end()){
    mit = map.find(*sit);
    if(mit==map.end())
      sit = sequence.erase(sit);
    else
      ++sit;     
  }

  return 0;
}
