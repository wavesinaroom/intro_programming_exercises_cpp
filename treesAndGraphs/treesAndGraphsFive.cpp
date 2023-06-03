/* Write a program that finds and prints all vertices of a binary tree which have 
 * successor leaves only */

#include <iostream>

class Node{
  public:
    int data;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int value){data=value;}
};

bool isLeaf(Node* node){
  return !node->left&&!node->right;
}

bool isParent(Node* node){
  if(node)
    return (isLeaf(node->left)||isLeaf(node->right));
  else
    return false;
}

void printParent(Node* node){
  if(node == nullptr)
    return;

  if(!isLeaf(node)&&isParent(node))
    std::cout<<node->data<<'\n';

  if (node->left) 
    printParent(node->left);
  
  if (node->right) 
    printParent(node->right);  
}

int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->left->left = new Node(11);
  root->left->right = new Node (5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  printParent(root);
  return 0;
}
