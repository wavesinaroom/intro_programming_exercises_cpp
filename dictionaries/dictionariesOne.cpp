/* Write a program to that counts, in a given array of integers, the number of occurrences of each integer.
 * Example: array = {3, 4, 4, 2, 3, 3, 4, 3, 2}
 * 2 à 2 times 3 à 4 times 4 à 3 times */

#include <iostream>
#include <map>
#include <array>

int main(){

  std::map<int, int> map;
  std::map<int, int>::iterator mit;
  std::array<int, 9> array = {3, 4, 4, 2, 3, 3, 4, 3, 2};
  std::array<int, 9>::iterator ait = array.begin();

  while(ait!=array.end()){
    mit = map.find(*ait); 
    if(mit!=map.end()){
      mit->second += 1; 
    }else{
      map.insert(std::make_pair(*ait, 1));
    }
    ++ait;
  }

  mit = map.begin();

  while(mit!=map.end()){
    std::cout<<"Number: "<<mit->first<<" à "<<mit->second<<"\n";
    ++mit;
  }

  return 0;
}
