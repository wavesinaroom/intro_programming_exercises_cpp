/* Write a program that finds the number of occurences of a number in a tree of numbers*/

#include <iostream>
#include <vector>

class Node{
  public:
  int value;
  std::vector<Node*> children;
    Node(int input){
      value = input; 
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

  Tree tree(9);
  tree.root->add(8);
  tree.root->add(7);
  tree.root->add(6);
  tree.root->children[0]->add(8);
  tree.root->children[0]->add(5);
  tree.root->children[0]->add(9);
  tree.root->children[0]->add(4);
  
  return 0;
}
