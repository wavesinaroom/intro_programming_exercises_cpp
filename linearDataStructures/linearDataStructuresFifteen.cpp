/* Implement sorting in a dynamic linked list without using an additional array or data structure.*/

#include <cstdio>
#include <iostream>
#include <functional>
#include <iterator>

class List{
  struct Node{
    int data;
    Node* next = nullptr;
  };
  public:
    List(int data);
    ~List();
    void add(int data);
    void print();
    void findMin();
  private:
    std::function<void(Node*)>callback;
    void iterate(Node * node, std::function<void(Node*)>callBack);
    void outputNodeData(Node *node);
    void compareToMin(Node* node);
    void getLast(Node* node);
    int min = 0;
    Node* root = new Node;
    Node* it;
};

List::List(int data){
  root->data = data;
  min = data;
  it = root;
}

List::~List(){}

void List::outputNodeData(Node *node){
  std::cout<<node->data<<'\n';
}

void List::compareToMin(Node* node){
  if (node->data<min) 
    min = node->data; 
}

void List::getLast(Node* node){
  it = node; 
}

void List::iterate(Node * node,std::function<void(Node*)>callBack){
  callBack(node);
  if(node->next == nullptr)
    return;
  iterate(node->next,callBack); 
}

void List::add(int data){
  callback = [this](Node* node){getLast(node);};
  iterate(root, callback);
  it->next = new Node;
  it->next->data = data;
}

void List::print(){
  callback = [this](Node* node)->void{outputNodeData(node);};
  iterate(root, callback);
}

void List::findMin(){
  callback = [this](Node* node){compareToMin(node);};
  iterate(root, callback);
}

int main(){
  List list(8); 
  list.add(9);
  list.add(7);
  list.add(2);
  list.add(3);
  list.print();
  list.findMin();
  return 0;
}


