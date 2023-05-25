/* Write a program that finds and prints all vertices of a binary tree which have 
 * successor leaves only */

#include <iostream>

class Node{
  public:
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
    bool isLeave = false;

    Node(int value){data=value;}
};

int main(){
  Node root(1);
  root.left = new Node(2);
  root.right = new Node(3);
  root.left->left = new Node(4);
  root.left->right = new Node (5);
  root.right->left = new Node(6);
  root.right->right = new Node(7);

  return 0;
}
