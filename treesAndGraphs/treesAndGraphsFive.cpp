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

bool traverse(Node* node);

bool traverse(Node* node){
  if(!node->left&&!node->right)
    return true; 

  if (traverse(node->left)||traverse(node->right)) 
      std::cout<<node->data<<'\t';  

  if(node->left)
    traverse(node->left);

  if (node->right) 
    traverse(node->right);  
}

int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node (5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  traverse(root);
  return 0;
}
