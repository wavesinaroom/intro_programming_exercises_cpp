/* Implement the structure "Circular Queue" with array, which doubles its capacity when it's 
 * full. Implement the necessary methods for adding, removing the element in succesion
 * and retrieving without removing the element in succession. If an operation is invalid,
 * throw an appropriate exception.*/

#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>

template <typename TValue>
class CQueue {
  public:
    CQueue(int size);
    ~CQueue(); 
    void add(TValue data);
  private:
    int currentSize;
    //Definitely use a pointers array
    TValue* array;
    void resize(){
      TValue *resize;
      resize = new TValue[currentSize*2];

      for (int i = 0; i < currentSize; ++i) {
        resize[i] = array[i];
      }
      delete[] array;
      array = resize;
      currentSize *=2;
    }
};

template<typename TValue>
CQueue<TValue>::CQueue(int size){
  currentSize = size;
  array = new TValue [currentSize];}

template<typename TValue>
CQueue<TValue>::~CQueue(){}

template<typename TValue>
void CQueue<TValue>::add(TValue data){
  array = &data;
  ++array;
  if (!array) 
    resize(); 
}

int main(){
  CQueue<std::string>test(1) ; 
  test.add("data");
  return 0;
}
