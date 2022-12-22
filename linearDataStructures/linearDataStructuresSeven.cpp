/* Write a program that finds in a given array of integers (in the range [0...1000]) how many times each of them occurs.  *
 * Example: array = {3,4,4,2,3,3,4,3,2}
 * 2 2 times
 * 3 4 times
 * 4 3 times 
 */

#include <iostream>
#include <iterator>
#include <list>
#include <vector>

bool checkVisitedNumbers(std::list<int>::const_iterator & end, std::vector<int>& numbers){
  for (auto & number : numbers) {
    if (*end==number) {
      return true;      
    }
  } 
  numbers.push_back(*end);
  return false;
}

int countNumberOcurrences(std::list<int>::const_iterator & start, std::list<int>::const_iterator & end, int value){
  int count = 1;

  while(start!=end){
    if (*start == value) {
      ++count;
    }
    ++start;
  }
  return count;
}

void findNumberOcurrences(std::list<int> & input){

  std::list<int>::const_iterator start = input.begin();
  std::list<int>::const_iterator end = std::prev(input.end());
  std::vector<int> numbers;
  int count;

  while (end!=start) {
    if (!checkVisitedNumbers(end, numbers)) {
      count = countNumberOcurrences(start, end, *end);
      std::cout<<"Number: "<<*end<<" appears "<<count<<" times"<<'\n';
    }
    count = 0;
    --end;
  }
}


int main(){
  std::list<int> input = {1,4,2,5,4,3,5,6,4};

  findNumberOcurrences(input);

  return 0;
}
