/* 2. Write a program that displays the roots of those sub-trees of a tree, which have exactly k nodes, where k is an integer */

#include <iostream>
#include <vector>

class Node{
  int value;
  public:
    int nodeCount = 1;
    std::vector<Node*> children; 

    Node(int value){this->value = value;}
    void add(int value){
      children.push_back(new Node(value));
    }

    void countNodes(){
      nodeCount += children.size();       
  }
};

int main(){
    Node node(9);
    node.add(8);
    node.add(7);
    node.add(3);
    node.add(6);
    node.add(4);
    node.countNodes();

  return 0;
}
