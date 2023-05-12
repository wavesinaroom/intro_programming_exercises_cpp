/* Write a program that finds the number of occurences of a number in a tree of numbers*/

#include <iostream>
#include <ostream>
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
    int occurence = 0;
    Tree(int value){
      root = new Node(value);
    }
  
    void countOccurence(Node* node, int input){
      if(!node)
        return;
      if(node->value == input)
        ++occurence;
      for(auto& child: node->children){
        countOccurence(child, input);
      }
    }
};

int main(){
  Tree tree(9); 
  tree.root->add(8);
  tree.root->add(7);
  tree.root->add(6);
  tree.root->add(7);
  tree.root->children[0]->add(9);
  tree.root->children[0]->add(7);
  tree.root->children[0]->add(8);
  tree.root->children[0]->add(7);
  tree.root->children[0]->children[0]->add(5);
  tree.root->children[0]->children[0]->add(7);
  tree.root->children[0]->children[0]->add(4);
  tree.root->children[0]->children[0]->add(4);
  tree.root->children[0]->children[0]->add(7);
  tree.countOccurence(tree.root, 4);

  return 0;
}
