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
    void print();

  private:
    int min;
    Node* head;
    Node* it;
    Node* root = new Node;
    void findMin(Node* start);
    void swap(Node* a, Node* b);
    void setIterator(Node* start);
};

List::List(int data){
  root->data = data;
  head = root;
}

List::~List(){}

void List::findMin(Node* start){
  head = start;
  min = start->data;
  while(head){
    if (head->data<min) {
      min = head->data; 
    } 
    head = head->next; 
  }
}

void List::swap(Node* a, Node* b){
  int temp = a->data;
  a->data = b->data;
  b->data = temp;
}

void List::setIterator(Node* start){
  head = start;
  while (head->next) {
    if (head->data==min) {
      break; 
    } 
    head = head->next;
  }
}

void List::add(int data){
  while (head->next) {
    head = head->next; 
  }
  head->next = new Node;
  head->next->data = data;
}

void List::sort(){
  it = root;
  while (it->next) {
    findMin(it);  
    setIterator(it);
    swap(it, head);
    it = it->next;
  } 
}

void List::print(){
  it = root;
  while (it->next) {
    std::cout<<it->data<<'\n'; 
    it = it->next;
  }
}


int main(){
  List list(8);
  list.add(3);
  list.add(5);
  list.add(7);
  list.add(2);
  list.add(4);
  list.sort();
  list.print();
  return 0;
}
