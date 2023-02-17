/* Implement the structure "Circular Queue" with array, which doubles its capacity when it's 
 * full. Implement the necessary methods for adding, removing the element in succesion
 * and retrieving without removing the element in succession. If an operation is invalid,
 * throw an appropriate exception.*/

#include <iostream>

template <typename TValue>
class CQueue {
  public:
    CQueue();
    ~CQueue(); 
    void add();
  private:
    int size = 2;
    void resize(TValue* &arr){
      TValue *resize;
      resize = new TValue[size*2];

      for (int i = 0; i < size; ++i) {
        resize[i] = arr[i];
      }
      delete[] arr;
      arr = resize;
      size *=2;
    }

};
