/* 1. Write a program that reads from the console a sequence of positive integer numbers.
 * The sequence ends when empty line is entered. Calculate and print the sum and the
 * avarage of the sequence. Keep the sequence in List<int>.*/

#include <cctype>
#include <iostream>
#include <iterator>
#include <list>
#include <string>

int main(){

  std::list<int> sequence;
  std::list<int>::iterator it;
  int sum;
  std::string temp;
  std::cout<<"Hi, please enter some numbers one by one. You're done with your sequence when there's no input from you"<<'\n';


  while (true) {
    std::getline(std::cin,temp);
    if (temp.empty()) {
      break;      
    }
    sequence.push_front(std::stoi(temp)); 
    sum += sequence.front();
  }

  std::cout<<sum<<'\n';
  return 0;
}
