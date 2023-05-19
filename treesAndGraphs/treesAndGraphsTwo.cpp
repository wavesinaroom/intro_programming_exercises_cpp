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

    Node* getRoot(){
      return root;
    }

    void traverse(Node* node, int number){
      if(!node)
        return;

      if(node->hasNumberNodes(number))
        node->print();

      for(auto& child: node->getChildren())
        traverse(child, number);
    }
};

int main(){
  Tree tree(7);
  Node* root = tree.getRoot();
  root->add(8);
  root->add(9);
  root->add(6);
  root->add(5);

  std::vector<Node*> children= root->getChildren();

  children[0]->add(8);
  children[0]->add(9);
  children[0]->add(4);
  children[0]->add(7);

  children[1]->add(3);
  children[1]->add(4);
  children[1]->add(8);

  children[2]->add(2);
  children[2]->add(3);
  
  children[3]->add(8);
  children[3]->add(9);
  children[3]->add(4);
  children[3]->add(7);
  children[3]->add(5);

  tree.traverse(root, 6);
  return 0;
}
