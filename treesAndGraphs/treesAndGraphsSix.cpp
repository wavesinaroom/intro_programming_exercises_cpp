/* Write program that checks whether a binary tree is perfectly balanced. */

#include <iostream>
#include <queue>

class Tree{
  class Node{
    private:
      int data;
      Node * left = nullptr;
      Node * right = nullptr;
    public:
      Node(int value){data = value;}

      bool hasTwoLeaves(){
        return(left && right);
      }
  };

  public:
    Node* root;
    Tree(int value){root = new Node(value);}
};


int main(){


  return 0;
}
