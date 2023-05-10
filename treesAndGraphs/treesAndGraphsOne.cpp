/* Write a program that finds the number of occurences of a number in a tree of numbers*/

#include <iostream>
#include <ostream>
#include <vector>


class Node{
  int value;
  std::vector<Node*> children;
  public:
    Node(int input){
      value = input; 
    }

    void add(int child){
      children.push_back(new Node(child));
    }

    void print(){
      std::cout<<value<<'\n';
      for(auto&child:children){
        child->print();
      }
    }
};

int main(){

  Node node(9);
  node.add(7);
  node.add(8);
  node.add(6);
  node.add(5);
  node.print();
  
  return 0;
}
