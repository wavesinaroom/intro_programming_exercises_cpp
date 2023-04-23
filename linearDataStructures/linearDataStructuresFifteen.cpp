/* Implement sorting in a dynamic linked list wheadhout using an addheadional array or data structure.*/

#include <algorithm>
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
    void sort();

  private:
    Node* head;
    Node* pre;
    Node* root = new Node;
    int min;
    void findMin(Node * start);
    void setPointers(Node * start);
};

List::List(int data){
  root->data = data;
  head = root;
  min = root->data;
}

List::~List(){}

void List::add(int data){
  while (head->next) {
    head = head->next; 
  }
  head->next = new Node;
  head->next->data = data;
}

void List::findMin(Node * start){
  head = start;
  min = start->data;
  while(head->next){
    head = head->next;
    if (head->data<min) 
      min = head->data; 
  }
  setPointers(start);
}

void List::setPointers(Node * start){
  head = start;
  while (head->data!=min) {
    pre = head;
    head = head->next;
  }
}

void List::sort(){
  findMin(root);
}

int main(){
  List list(8);
  list.add(3);
  list.add(5);
  list.add(7);
  list.add(2);
  list.add(4);
  list.sort();

  return 0;
}
