/* Implement the structure "Circular Queue" with array, which doubles its capacity when it's 
 * full. Implement the necessary methods for adding, removing the element in succesion
 * and retrieving without removing the element in succession. If an operation is invalid,
 * throw an appropriate exception.*/

#include <iostream>

template <typename TValue>
class CQueue {
  struct TNode{
    TValue data;
    TNode next = nullptr;
    TNode previous = nullptr;
  };
  public:
    CQueue();
    ~CQueue(); 
  private:
    TNode * it = nullptr;
    TNode * root = nullptr;

};
