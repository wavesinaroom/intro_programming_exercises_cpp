/* Write a program that removes from a given sequence all numbers that appear an odd count
 * of times */

#include <iostream>
#include <iterator>
#include <list>
#include <vector>

void deleteANumberSequence(std::list<int> & input){
  std::list<int>::iterator end = input.end();
  std::list<int>::iterator start = input.begin();

  while (start!=input.end()) {
    do{--end;}
    while (*start!=*end);
    ++end;

    int length = input.size()-(std::distance(input.begin(),start)+std::distance(end, input.end()));
    if (length%2==1) {
      input.erase(start,end);
    }
    start = end;
    end = input.end();
  }

}

int main(){
  std::list<int> input = {1,6,4,6,7,3,2,6,3};
  input.sort();
  deleteANumberSequence(input);
  for (auto & item : input) {
    std::cout<<item<<'\n';
  }
  return 0;
}
