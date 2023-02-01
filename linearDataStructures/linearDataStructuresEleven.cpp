/* Implement the data structure dynamic doubly linked list (DoublyLinkedList<T>) - list,
 * the elements of which have pointers both to the next and the previous elements. Implement 
 * the operations for adding, removing and searching for an element, as well as inserting
 * an element at a given index, retrieving an element by a given index and a method, which returns an array with the elements of the list
 * add -> done
 * search -> done
 * nodes array -> done
 * remove ....
 * insert at index : pending
 * retrieve by index : pending
 * */

#include <cstddef>
#include <iostream>
#include <vector>

template<typename TValue> class List{
struct TNode{
  TValue data;
  TNode *previous = nullptr;
  TNode *next = nullptr;
};
  public:
    std::vector<TNode *> elements;
    List();
    ~List();
    auto getRoot();
    void addNode(TValue data);
    void removeNode(TValue data);
    auto searchNode(TValue data, TNode *node);    
    void getNodesVector(TNode *node);
  private:
    auto getLastNode(TNode *node);
    TNode *root = nullptr;
};

template <typename TValue>
auto List<TValue>::getLastNode(TNode *node){
  if (node->next == nullptr) {
    return node;
  }else {
    return getLastNode(node->next);
  } 
}

template<typename TValue>
List<TValue>::List(){
}

template<typename TValue>
List<TValue>::~List<TValue>(){
}

template <typename TValue>
auto List<TValue>::getRoot(){
  return root;
}

template<typename TValue>
void List<TValue>::addNode(TValue data){
  TNode *newNode = new TNode; 
  newNode->data = data;

  if(!root)
    root = newNode;
  else{
    TNode *last = getLastNode(root);
    last->next = newNode;
    last->next->previous = last;
  }
}

template<typename TValue>
void List<TValue>::removeNode(TValue data){
  auto node = searchNode(data, getRoot());
  node->previous->next = node->next;
  node->next->previous = node->previous;
  node = nullptr;
}

template<typename TValue>
auto List<TValue>::searchNode(TValue data, TNode *node ){
  if (node->data == data) 
    return node;
  return searchNode(data, node->next);
}

template <typename TValue>
void List<TValue>::getNodesVector(TNode *node){
  elements.push_back(node);
  if(node->next==nullptr)
    return;

  getNodesVector(node->next);
}



int main(){
  List<int> list; 
  list.addNode(4);
  list.addNode(5);
  list.addNode(6);
  list.addNode(7);
  list.removeNode(5);
  auto found = list.searchNode(5, list.getRoot());
  list.getNodesVector(list.getRoot());
  return 0;
}


