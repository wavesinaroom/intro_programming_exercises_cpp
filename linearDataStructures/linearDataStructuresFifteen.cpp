/* Implement sorting in a dynamic linked list wheadhout using an addheadional array or data structure.*/

#include <iostream>

class List{
  struct Node{
    int data;
    Node* next = nullptr;
  };
  public:
    List(int data);
    ~List();
    void add(int data);
  private:
    
    Node* head;
    Node* it;
    Node* root = new Node;
    int min;
};

List::List(int data){
  root->data = data;
  head = root;
  min = root->data;
}

List::~List(){}


