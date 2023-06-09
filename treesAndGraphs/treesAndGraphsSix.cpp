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
  };

class Tree{
  public:
    std::queue<Node*> nodes;
    Node* root;
    Tree(int value){
      root = new Node(value);}

    bool queue(Node* node){
      if(node->hasTwoLeaves()){
        nodes.push(node);
        nodes.push(node->left);
        nodes.push(node->right);
        return true;
      }else{
        std::cout<<"Tree isn't perfectly balanced"<<'\n';
        return false;
      }
    }

    void breadthTraverse(){
      bool isBalanced = queue(root);
      while(!nodes.empty()&&isBalanced){
        nodes.pop();
        isBalanced = queue(nodes.front());
      }
    }

};


int main(){
  Tree tree(1);
  tree.root->left = new Node(2);
  tree.root->right = new Node(3);

  return 0;
}
