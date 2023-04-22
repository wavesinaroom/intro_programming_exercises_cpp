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

void List::add(int data){
  while (head->next) {
    head = head->next; 
  }
  head->next = new Node;
  head->next->data = data;
}

int main(){
  List list(8);
  list.add(3);
  list.add(5);
  list.add(7);
  list.add(2);
  list.add(4);
  return 0;
}
