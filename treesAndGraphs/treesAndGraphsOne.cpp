/* Write a program that finds the number of occurences of a number in a tree of numbers*/

#include <iostream>
#include <vector>

class Node{
  int* root;
  std::vector<Node*> children;

  public:
    Node(int value){
      *root = value; 
    }

    void add(int child){
      children.push_back(new Node(child));
    }
};

class Tree{

  private:
    Node * root;
  public:
    Tree(int value){
     root = new Node(value);
    }
};

int main(){

  return 0;
}
