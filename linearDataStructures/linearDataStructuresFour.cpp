/* 4. Write  a method that finds the longest subsequence of equal numbers in a given List<int>
 * and returns the result as new List<int>. Write a program to test whether the method works
 * correctly.
 */

#include <iostream>
#include <iterator>
#include <list>

int measureSublist(std::list<int> & inputList, std::list<int>::iterator head){

  std::list<int>::iterator same = head;
  int count = 0;

  while (*same==*head) {
    ++count;
    ++same;
  }

  return count;
}

int main(){
  std::list<int> input = {4,5,2,0,3,5,1,5,6,8};
  std::list<int>::iterator start = input.begin();
  int head=0, current=0, longest = 0;
 
  while (start!=input.end()) {
    current = measureSublist(input, start); 
    if (current>longest) {
      longest = current;
      head = std::distance(input.begin(), start);
    }
    ++start;
  }

  if (longest==1) {
    std::cout<<"There's no sublist with equal numbers"<<'\n';
  }else {
    std::cout<<"longest list: "<<longest<<" numbers starting at: "<<head<<'\n';
  }
  
  return 0;
}


