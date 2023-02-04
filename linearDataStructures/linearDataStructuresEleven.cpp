/* Implement the data structure dynamic doubly linked list (DoublyLinkedList<T>) - list,
 * the elements of which have pointers both to the next and the previous elements. Implement 
 * the operations for adding, removing and searching for an element, as well as inserting
 * an element at a given index, retrieving an element by a given index and a method, which returns an array with the elements of the list
 * add : done
 * nodes array : done
 * remove : pending 
 * insert at index : pending
 * retrieve by index : ready
 * */

#include <cstddef>
#include <cstdio>
#include <iostream>
#include <vector>

template<typename TValue> class List{
struct TNode{
  TValue data;
  TNode *previous = nullptr;
  TNode *next = nullptr;
};
  public:
    TNode *it = nullptr;
    std::vector<TNode> elements;
    List();
    ~List();
    auto getNodeByIndex(int index);
    void addNode(TValue data);
    void removeNode(TValue data);
    auto searchNode(TValue data);    
    void getNodesVector();
  private:
    void getLastNode();
    TNode *root = nullptr;
};

template <typename TValue>
List<TValue>::List(){
}

template <typename TValue>
List<TValue>::~List(){
}

template <typename TValue>
void List<TValue>::getLastNode(){
  it = root;
  while (it->next) {
    it = it->next;
  }
}

template<typename TValue>
auto List<TValue>::getNodeByIndex(int index){
  it = root;
  for (std::size_t i = 0; i<index; ++i) {
    it = it->next; 
  }
  return *it;
}

template<typename TValue>
auto List<TValue>::searchNode(TValue data){
  it = root;
  while (it->data!=data) {
    if (!it->next) 
      std::cerr<<"Node not found"<<'\n';  
    it = it->next;
  }
}

template<typename TValue>
void List<TValue>::addNode(TValue data){
  TNode *newNode = new TNode; 
  newNode->data = data;

  if(!root)
    root = newNode;
  else{
    getLastNode();
    it->next = newNode;
    it->next->previous = it;
  }
}

template<typename TValue>
void List<TValue>::removeNode(TValue data){
  searchNode(data);
  while (it->next) {
    it->previous->next = it->next;
    it->next->previous = it->previous;
    it = it->next;
  }
}

template <typename TValue>
void List<TValue>::getNodesVector(){
  it = root;
  while(it){
    elements.push_back(*it);
    it = it->next;
  }
}

int main(){
  List<int> list; 
  list.addNode(4);
  list.addNode(5);
  list.addNode(6);
  list.addNode(7);
  list.getNodesVector();
  
  return 0;
}


