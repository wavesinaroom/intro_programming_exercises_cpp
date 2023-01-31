/* Implement the data structure dynamic doubly linked list (DoublyLinkedList<T>) - list,
 * the elements of which have pointers both to the next and the previous elements. Implement 
 * the operations for adding, removing and searching for an element, as well as inserting
 * an element at a given index, retrieving an element by a given index and a method, which returns an array with the elements of the list*/

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
    List();
    ~List();
    std::vector<TNode *> elements;
    auto getRoot();
    void getListNodes(TNode *node);
    void addNode(TValue data);
  private:
    auto getLastNode(TNode *node);
    TNode *root = nullptr;
};

template<typename TValue>
List<TValue>::List(){
}

template<typename TValue>
List<TValue>::~List<TValue>(){
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

template <typename TValue>
auto List<TValue>::getLastNode(TNode *node){
  if (node->next == nullptr) {
    return node;
  }else {
    return getLastNode(node->next);
  } 
}

template <typename TValue>
void List<TValue>::getListNodes(TNode *node){
  elements.push_back(node);
  if(node->next==nullptr)
    return;

  getListNodes(node->next);
}

template <typename TValue>
auto List<TValue>::getRoot(){
  return root;
}

int main(){
  List<int> list; 
  list.addNode(4);
  list.addNode(5);
  list.addNode(6);
  list.getListNodes(list.getRoot());
  return 0;
}


