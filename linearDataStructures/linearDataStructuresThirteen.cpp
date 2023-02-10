/* Implement the data structure "Deque". This is a specific list-like structure, similar to stack and queue, allowing to add elements at the beginning and at the end of the structure. 
 * Implement the operations for adding and removing elements, as well as clearing the deque. If an operation is invalid, throw an appropriate exception.*/

#include <iostream>

template<typename TValue>
class Deque{
  struct TNode{
    TValue data;
    TNode * previous = nullptr;
    TNode * next = nullptr;
  };
  public:
    Deque(); 
    ~Deque();
    void addHead(TValue);
    void addTail(TValue);
  private:
    void getLast();
    void getFirst();
    TNode * it = nullptr;
    TNode * root = nullptr;
};

template<typename TValue>
Deque<TValue>::Deque(){}

template<typename TValue>
Deque<TValue>::~Deque(){}

template<typename TValue>
void Deque<TValue>::addHead(TValue data){
  TNode * addition = new TNode;
  addition->data = data;
  if(!root)
    root = addition;
  else{
    getFirst();
    it->next = addition;
  }
}

template<typename TValue>
void Deque<TValue>::addTail(TValue data){
  TNode * addition = new TNode;
  addition->data = data;
  if (!root) 
    root = addition; 
  else{
    getLast();
    it->previous = addition;  
  }
}

template<typename TValue>
void Deque<TValue>::getFirst(){
  it = root;
  while (it->next) {
    it = it->next;
  }
}

template<typename TValue>
void Deque<TValue>::getLast(){
  it = root;
  while (it->previous) {
    it = it->previous;
  }
}

int main(){
  Deque<int> deque;
  deque.addHead(8);
  deque.addHead(7);
  deque.addTail(3);
  return 0;
}
