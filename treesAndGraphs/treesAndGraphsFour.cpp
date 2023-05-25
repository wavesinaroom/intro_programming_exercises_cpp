/* Write a program that finds in a binary tree of numbers the sum of the vertices of each
 * level of the tree.*/

#include <cstddef>
#include <iostream>
#include <queue>

class node{
  public:
    int data;
    node *left, *right;
};

void printCurrentLevel(node* root, int level);  
int height(node* node);
node* newNode(int data);
   
void printLevelOrder(node* root){
  int h = height(root);
  for (int i=1; i<=h; ++i) {
    printCurrentLevel(root, i); 
  }
}

void printCurrentLevel(node* root, int level){
  if (!root) 
    return;

  if(level == 1)
    std::cout<<root->data<<" ";
  else if(level>1){
    printCurrentLevel(root->left, level-1);
    printCurrentLevel(root->right, level-1);
  }
}

int height(node* node){
  if(!node)
    return 0;
  else{
    int lheight = height(node->left);
    int rheight = height(node->right);

    if(lheight>rheight)
      return (lheight+1);
    else
     return (rheight+1);
  }
}

node* newNode(int data){
  node* Node = new node();
  Node->data = data;
  Node->left = NULL;
  Node->right = NULL;
  
  return (Node);
}


int main(){
  node* root = newNode(1); 
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->right->right = newNode(5);

  printLevelOrder(root);
  return 0;
}
