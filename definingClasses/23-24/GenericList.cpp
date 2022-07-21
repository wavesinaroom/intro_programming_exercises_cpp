/* 23. Write a generic class GenericList<T>, which holds a list of elements of type T.
Store the list of elements into an array with a limited capacity that is passed as a
parameter of the constructor of the class. Add methods to add an item, to access
an item by index, to remove an item by index, to insert an item at given position, 
to clear the list, to search for an item by value and to override the method ToString().

24. Implement auto-resizing functionality of the array from the previous task, 
when by adding an element, it reaches the capacity of the array. 
*/

//CLASS AND CONSTRUCTOR TAKEN FROM GEEK FOR GEEK.ORG https://www.geeksforgeeks.org/generics-in-c/

#include <iostream>
#include <sstream>

template<typename T>
class Array{
    private:
        T* ptr;
        int size;
    public:
        Array(int s);
        void print();
        T getItem(int index);
        T removeItem(int index);
        T insertItem(T item, int position);
        void clearList();
        T searchItemValue(T value);
        std::string stringOverride(T arr[]);
};

template<typename T>
Array<T>::Array(int s)
{
    ptr = new T[s]; 
    size = s;
}

template<typename T>
void Array<T>::print()
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout<<" "<< *(ptr + i)<<'\n';
    }

}

template<typename T>
T Array<T>::getItem(int index)
{
    return *(ptr + index); 
}

template<typename T>
T Array<T>::removeItem(int index)
{
    for (size_t i = index; i < size-index; i++)
    {
        *(ptr+i) = *(ptr+(i+1));
    }

    T* temporal = new T[size-1]; 
    
    for (size_t j = 0; j < size-1; j++)
    {
        temporal[j] = ptr[j];
    }
    
    return temporal;
}

template<typename T>
T Array<T>::insertItem(T item, int position)
{
    T* temporal = new T[size+1];
    for (size_t i = 0; i < position-1; i++)
    {
        temporal[i] = ptr[i];
    }
    
    temporal[position] = item;

    for (size_t i = position+1; i < size+1; i++)
    {
        temporal[i] = ptr[i];
    }
    return temporal;    
}

template<typename T>
void Array<T>::clearList()
{
    delete [] ptr;
    ptr = NULL;
}

template<typename T>
T Array<T>::searchItemValue(T value)
{
    for (size_t i = 0; i < size; i++)
    {
        if (*(ptr + i)==value)
        {
            return *(ptr + i);
        }
    }
}

template<typename T>
std::string Array<T>::stringOverride(T arr[])
{
    std::ostringstream oss;
    for (size_t i = 0; i < size; i++)
    {
        oss<< arr[i];    
        oss<< " ";
    }
    return oss.str();
}

int main(int argc, char const *argv[])
{
    Array<int> array = Array<int>(5);
    return 0;
}
