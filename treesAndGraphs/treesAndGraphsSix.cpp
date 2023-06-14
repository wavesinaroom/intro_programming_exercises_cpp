/* Write program that checks whether a binary tree is perfectly balanced. */

#include <iostream>
#include <queue>

  class Node{
    private:
      int data;
    public:
      Node * left = nullptr;
      Node * right = nullptr;
      Node(int value){data = value;}
      
      int getData(){
        return data;
      }
      bool hasTwoLeaves(){
        return(left && right);
      }
      bool isLeaf(){
        return(!left&&!right);
      }
  };

class Tree{
  public:
    std::queue<Node*> nodes;
    Node* root;
    Tree(int value){
      root = new Node(value);}

    void breadthTraverse(){
      nodes.push(root);
      while(!nodes.empty()&&nodes.front()->hasTwoLeaves()){
        nodes.push(nodes.front()->left);
        nodes.push(nodes.front()->right);
        nodes.pop();
      }
      if(nodes.front()->isLeaf()){
        std::cout<<"Tree's balanced"<<'\n';
        return;
      }else{
        std::cout<<"Tree's not balanced"<<'\n';
        return;
      }
  }    
};


int main(){
  Tree tree(1);
  tree.root->left = new Node(2);
  tree.root->left->left = new Node(4);
  tree.root->left->right = new Node(5);
  tree.root->right = new Node(3);
  tree.breadthTraverse();
  return 0;
}
