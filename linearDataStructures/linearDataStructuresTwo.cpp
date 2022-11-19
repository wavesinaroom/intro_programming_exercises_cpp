/* Write a program, which reads from the console N integers and prints them in reversed order.
 * Use the Stack<int> class.
 */

#include <iostream>
#include <stack>
#include <string>

int main(){

  std::string temp;
  std::stack<int> sequence;
  int number; 
  std::cout<<"Hi! Please enter some numbers on by one. I'll print them in reversed order"<<'\n';

  while (true) {
    std::getline(std::cin,temp);
    if(temp.empty()){
      break;
    }
    sequence.push(std::stoi(temp));
  }

  while(!sequence.empty()){
    number = sequence.top();  
    std::cout<<number<<'\n';
    sequence.pop();
  }
  return 0;
}
