/* The majorant of an array of size N is a value that occurs in it at least N/2 + times.
 * Write a program that finds the majorant of given array and prints it. If it does not exist, print "The majorant does not exist".
 * Example: array = {2, 2, 3, 3, 2, 3, 4, 3, 3} 3
 */

#include <iostream>
#include <iterator>
#include <list>

int main(){
  std::list<int> input = {2,2,3,3,2,3,4,3,3};
  const int majorant = input.size()/2 ; //I don't add 1 to it cause .begin() is already a unit
  input.sort();
  std::list<int>::iterator end = input.begin();
  std::list<int>::iterator start = input.begin();
  std::advance(end, majorant);

  while (end!=input.end()) {
    if (*start==*end) {
      std::cout<<"List has a majorant"<<'\n';
      break;
    }else {
      ++start;
      ++end;
    }
  }
  return 0;
}
