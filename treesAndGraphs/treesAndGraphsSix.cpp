/* Write program that checks whether a binary tree is perfectly balanced. */

#include <iostream>

class Tree{
  public:
    int data;
    Tree * left = nullptr;
    Tree * right = nullptr;
    Tree(int value){data = value;}
};

bool isBalanced(Tree* root){
  return (root->left&&root->right);
}

int main(){

  Tree* root = new Tree(1);
  root->left = new Tree(2);
  root->right= new Tree(3);
  std::cout<<isBalanced(root)<<'\n';

  return 0;
}
