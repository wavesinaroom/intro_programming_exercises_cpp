/* Write program that checks whether a binary tree is perfectly balanced. */

#include <iostream>

class Tree{
  public:
    int data;
    Tree * left = nullptr;
    Tree * right = nullptr;
    Tree(int value){data = value;}
};

int main(){

  Tree* root = new Tree(7);
  root->left = new Tree(8);
  root->right = new Tree(9);
  root->left->left = new Tree(11);
  root->left->right = new Tree(12);
  root->right->left = new Tree(13);
  root->right->left = new Tree(14);

  return 0;
}
