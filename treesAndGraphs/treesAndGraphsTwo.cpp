/* 2. Write a program that displays the roots of those sub-trees of a tree, which have exactly k nodes, where k is an integer */

#include <iostream>
#include <vector>

class Node{
  int data;
  std::vector<Node*> children; 
  public:
    Node(int value){data = value;}

    void add(int value){
      children.push_back(new Node(value));
    }

    bool hasNumberNodes(int number){
      return number == (children.size()+1);
    }
     
    int getData(){
      return data;
    }

    std::vector<Node*> getChildren(){
      return children;
    }
    
    void print(){
      std::cout<<data<<'\n';
      for(auto& child: children){
        std::cout<<child->data<<'\t';
      }
      std::cout<<'\n';
    }
};

class Tree{
  Node* root;
  public:
    Tree(int value){root = new Node(value);}

    void printNNodesSubtrees(Node* node, int value){
      if(!node)
        return;

      if(node->hasNumberNodes(value)){
        std::cout<<node->getData()<<'\n'; 
      }

      for(auto& child: node->getChildren()){
        printNNodesSubtrees(child, value);
      }
    }
};

int main(){
  Node node(7);
  node.add(8);
  node.add(9);
  node.add(6);
  node.add(5);

  node.print();
  return 0;
}
