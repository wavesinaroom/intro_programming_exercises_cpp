/* Write a program that finds the number of occurences of a number in a tree of numbers*/

#include <iostream>
#include <vector>

class Node{
  public:
  int root;
  std::vector<Node*> children;
    Node(int value){
      root = value; 
    }

    void add(int child){
      children.push_back(new Node(child));
    }
};

class Tree{

  public:
    Node * root;
    Tree(int value){
     root = new Node(value);
    }
};

int main(){

  Node node(4);
  node.add(8);
  node.add(9);
  node.add(10);
  return 0;
}
