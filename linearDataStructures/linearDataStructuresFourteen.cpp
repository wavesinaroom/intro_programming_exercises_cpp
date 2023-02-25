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
    CQueue();
    ~CQueue(); 
    void add(TValue data);
  private:
    int size = 1;
    //Definitely use a pointers array
    TValue* array;
    void resize(){
      TValue *resize = new TValue[size*2];

      for (int i = 0; i < size; ++i) {
        resize[i] = array[i];
      }
      delete[] array;
      array = resize;
      size *=2;
    }
};

template<typename TValue>
CQueue<TValue>::CQueue(){
  array = new TValue [size];}

template<typename TValue>
CQueue<TValue>::~CQueue(){}

template<typename TValue>
void CQueue<TValue>::add(TValue data){
  *array = data;
  if(!++array)
    resize();
  ++array;
}

int main(){
  CQueue<std::string>test; 
  test.add("data");
  return 0;
}
