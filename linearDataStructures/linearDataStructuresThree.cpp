/* Write a program that reads from the console a sequence of positive integer numbers.
 * The sequence ends when an empty line is entered. Print the sequence sorted in ascending order.
 */

#include <iostream>
#include <list>

int main(){
  std::list<int> sequence;
  std::cout<<"Hi! Please enter some numbers on by one. I'll print them in reversed order"<<'\n';
  std::string temp;

  while (true) {
    std::getline(std::cin,temp);
    if(temp.empty()){
      break;
    }
    sequence.push_front(std::stoi(temp));
  }
  
  sequence.sort();
  
  for(std::list<int>::iterator i = sequence.begin(); i!=sequence.end(); ++i ){
    std::cout<<*i<<'\n';
  }
}
