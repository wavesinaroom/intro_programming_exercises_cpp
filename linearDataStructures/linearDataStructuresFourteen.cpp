/* Implement the structure "Circular Queue" with array, which doubles its capacity when it's 
 * full. Implement the necessary methods for adding, removing the element in succesion
 * and retrieving without removing the element in succession. If an operation is invalid,
 * throw an appropriate exception.*/

#include <cstdio>
#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <array>

template <typename TValue>
class CQueue {
  typedef struct Element{
    TValue data;
    int index=0;
  }element;
  public:
    CQueue();
    ~CQueue(); 
    void add(TValue data);
    auto retrieve();
  private:
    int size = 1;
    int index = 0;
    element* array = (element*) malloc(sizeof(element));
    element* it = array;
    void expand();
};
template<typename TValue>
CQueue<TValue>::CQueue(){
}

template<typename TValue>
CQueue<TValue>::~CQueue(){}

template<typename TValue>
void CQueue<TValue>::expand(){
  element* extend = NULL;
  size *= 2;
  extend = (element*)realloc(array, size*sizeof(element));
  if (extend!=NULL) {
    array = extend; 
  }else {
    free(array);
    puts("Error reallocating memory");
  }
}

template<typename TValue>
void CQueue<TValue>::add(TValue data){
  if (it->index==index) 
    ++it; 
  it->data = data;
  it->index = index;
  if (index == size-1)
    expand();
  ++it;
  ++index;
}

template<typename TValue>
auto CQueue<TValue>::retrieve(){
  if (it->index!=index) 
    --it;
  return *it;
}

int main(){
  CQueue<int>test; 
  test.add(2);
  test.add(4);
  test.add(6);
  test.add(8);
  auto retrieved = test.retrieve(); 

  return 0;
}
