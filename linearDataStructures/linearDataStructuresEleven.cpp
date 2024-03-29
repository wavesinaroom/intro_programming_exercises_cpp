/* Implement the data structure dynamic doubly linked list (DoublyLinkedList<T>) - list,
 * the elements of which have pointers both to the next and the previous elements. Implement 
 * the operations for adding, removing and searching for an element, as well as inserting
 * an element at a given index, retrieving an element by a given index and a method, which returns an array with the elements of the list
 * add : done
 * nodes array : done
 * remove : done 
 * insert at index : done
 * retrieve by index : function's ready, can't retrieve a *TNode though because the struct lives inside List
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
    void searchNode(TValue data);    
    void getNodesVector();
    void insertAtIndex(int index, TValue data);
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
  return it;
}

template<typename TValue>
void List<TValue>::searchNode(TValue data){
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
  it->previous->next = it->next;
  it->next->previous = it->previous;
}

template <typename TValue>
void List<TValue>::getNodesVector(){
  elements.clear();
  it = root;
  while(it){
    elements.push_back(*it);
    it = it->next;
  }
}

template<typename TValue>
void List<TValue>::insertAtIndex(int index, TValue data){
  getNodeByIndex(index);
  TNode * newNode = new TNode;
  newNode->data = data;
  if(it->previous){
    it->previous->next = newNode;
    newNode->previous = it->previous->next;
  }
  if(it->next){
    it->next->previous = newNode;
    newNode->next = it->next->previous;
  }
}

int main(){
  List<int> list; 
  list.addNode(4);
  list.addNode(5);
  list.addNode(6);
  list.addNode(7);
  list.getNodesVector();
  list.removeNode(5);
  list.insertAtIndex(2, 8);
  list.getNodesVector();
  return 0;
}


