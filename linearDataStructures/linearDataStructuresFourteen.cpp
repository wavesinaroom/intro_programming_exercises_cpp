/* Implement the structure "Circular Queue" with array, which doubles its capacity when it's 
 * full. Implement the necessary methods for adding, removing the element in succesion
 * and retrieving without removing the element in succession. If an operation is invalid,
 * throw an appropriate exception.*/

#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <string>
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
    void expand();
    void add(TValue data);
  private:
    int size = 1;
    element* array; 
};
template<typename TValue>
CQueue<TValue>::CQueue(){
  array = (element*) malloc(sizeof(element));
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
    puts("Error reallocation memory");
  }
}

template<typename TValue>
void CQueue<TValue>::add(TValue data){
  array->data = data;
  if (array->index==size-1) 
    expand();
  ++array;
}


int main(){
  CQueue<int>test; 
  test.add(2);
  test.add(4);
  test.add(6);
  test.add(7);
  return 0;
}
