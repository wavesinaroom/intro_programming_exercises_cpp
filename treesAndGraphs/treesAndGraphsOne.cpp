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
        if(child)
          child->print();
      }
    }
};

class Tree{
  public:
    Node* root;
    Tree(int value){
      root = new Node(value);
    }
};

int main(){
  Tree tree(9); 
  return 0;
}
