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

      bool hasTwoLeaves(){
        return(left && right);
      }
  };

class Tree{
  public:
    std::queue<Node*> nodes;
    Node* root;
    Tree(int value){
      root = new Node(value);}

    void isBalanced(Node* node){
      if(!node||!node->hasTwoLeaves())
        return;

      nodes.push(node);
      if (node->hasTwoLeaves()) {
        nodes.push(node->right);
        nodes.push(node->left);
        nodes.pop();
      }
    }

};


int main(){
  Tree tree(1);
  tree.root->left = new Node(2);
  tree.root->right = new Node(3);
  tree.isBalanced(tree.root);

  return 0;
}
