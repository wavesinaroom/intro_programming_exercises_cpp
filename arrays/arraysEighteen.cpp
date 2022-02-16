#include <iostream>
#include <vector>

/*Write a program,which sorts an array of integer elements 
using a "quick sort" algorithm.*/

//SOLUTION TAKEN FROM https://www.youtube.com/watch?v=PupaczLYxmA

int partition(std::vector<int>&array, int start, int end)
{
    int pivot=array[start]; 
    int i =start+1;
    for (int j=i; j<=end; j++)
    {
        if(array[j]<pivot)
        {
            std::swap(array[i],array[j]); 
            i++; 
        }
    }
    std::swap(array[start],array[i-1]);
    return i-1; 
}


void quickSort(std::vector<int>&array, int start, int end)
{
     if (start<end)
     {
         int pivot=partition(array,start,end);
         quickSort(array,start,pivot-1);
         quickSort(array,pivot+1,end);   
     }
}

void printVector(std::vector<int>array)
{
    for (int iPrintArray=0; iPrintArray<array.size(); iPrintArray++)
    {
        std::cout<<array[iPrintArray]<<" ";
    }
    std::cout<<std::endl; 
}

int main(int argc, char const *argv[])
{
    std::vector<int>array={2,4,6,8,7,9,5,3,1,0,10};
    printVector(array);
    quickSort(array,0,array.size()-1);
    printVector(array); 
    return 0;
}

