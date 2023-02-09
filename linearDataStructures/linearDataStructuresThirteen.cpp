/* Implement the data structure "Deque". This is a specific list-like structure, similar to stack and queue, allowing to add elements at the beginning and at the end of the structure. 
 * Implement the operations for adding and removing elements, as well as clearing the deque. If an operation is invalid, throw an appropriate exception.*/

#include <iostream>

template<typename TValue>
class Deque{
  struct TNode{
    TValue data;
    TValue * previous;
    TValue * next;
  };
  public:
    Deque(); 
    ~Deque();
  private:
    void getLast();
    void getFirst();
    TValue * it;
    TValue * root;
};

template<typename TValue>
Deque<TValue>::Deque(){}

template<typename TValue>
Deque<TValue>::~Deque(){}




