/* Create a Dynamic<T> class to implement dynamically a stack (like a linked list, where each element knows its previous element and the stack knows its last element).
 * Add methods for all commonly used operations like Push(), Pop(), Peek(), Clear() and Count.
 * Push(T) - adds a new element on the top of the stack -> done
 * Pop() - returns the highest element and removes it from the stack -> done
 * Peek() - returns the highest elements without removing it -> done
 * Count - returns the count of elements in the stack-> done
 * Clear() - returns all elements of the stack
 */

#include <iostream>
#include <vector>


template<typename TValue> class Dynamic{
struct TNode{
  TValue data;
  TNode *previous;
};
  public:
    Dynamic();
    ~Dynamic();
    int Count;
    void Push(TValue data);
    void Pop();
    auto Peek();
    std::vector<TValue> Clear();
  private:
    TNode *it = nullptr;
    TNode *top = nullptr;
};

template<typename TValue>
Dynamic<TValue>::Dynamic(){}

template<typename TValue>
Dynamic<TValue>::~Dynamic(){}

template<typename TValue>
void Dynamic<TValue>::Push(TValue data){
  TNode *newNode = new TNode;
  newNode->data = data;
  if(top){
    newNode->previous = top;
    top = newNode;
  }
  else
    top = newNode;
  ++Count;
}

template<typename TValue>
void Dynamic<TValue>::Pop(){
  it = top;
  top = top->previous;
  it = nullptr;
  --Count;
}

template<typename TValue>
auto Dynamic<TValue>::Peek(){
  return top->data;
}

template<typename TValue>
std::vector<TValue> Dynamic<TValue>::Clear(){
  std::vector<TValue> elements;
  it = top;
  while (it) {
    elements.push_back(it->data);
    it = it->previous;
  }
  return elements;
}

int main(){
  Dynamic<int> stack;
  stack.Push(8);
  stack.Push(9);
  stack.Pop();
  stack.Push(10);
  stack.Push(11);
  int retrieved = stack.Peek();
  std::vector<int> elements = stack.Clear();

  return 0;
}

