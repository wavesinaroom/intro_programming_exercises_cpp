#include <iostream>

using namespace std;

/*Write a program, which creates an array of 20 elements of type integer 
and initializes each of the elements with a value equals to the index of 
the element multiplied by 5. Print the elements to the console.*/

int main(int argc, char const *argv[])
{
    int array[20];
    int arraySize = sizeof(array)/sizeof(array[0]); 

    for (size_t i = 0; i < arraySize; i++)
    {
        array[i] = i*5;
        cout<<array[i]<<" "; 
    }
    
    cout<<endl; 

    return 0;
}
