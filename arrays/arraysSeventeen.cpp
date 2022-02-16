#include <iostream>
#include <vector>


/*Write a program, which sorts an array of integer elements 
using a "merge sort" algorithm.*/

/*ANSWER BASED ON:https://www.youtube.com/watch?v=1Xl-Zavaci8
TUTORIAL - Code has a bug I couldn't solve, feel free
to do a pull request if you sort it out*/

void merge(std::vector<int>&array,int start, int half,int end)
{
    int i,j,k;
    int leftContents=half-(start+1);
    int rightContents=end-half; 

    std::vector<int>leftSide(leftContents);
    std::vector<int>rightSide(rightContents);

    for (int i=0; i<leftContents; i++)
    {
        leftSide[i]=array[start+i];
    }
    for (int j=0; j<rightContents; j++)
    {
        rightSide[j]=array[half+1+j]; 
    }
    
    i=0;
    j=0;
    k=start;

    while (i<leftContents&&j<rightContents)
    {
        if(leftSide[i]<=rightSide[j])
        {
            array[k]=leftSide[i];
            i++;
        }else{
            array[k]=rightSide[j];
            j++;
        }
        k++;
    }

    while (j<rightContents)
    {
        array[k]=rightSide[j];
        j++;
        k++;
    }
    
    while (i<leftContents)
    {
        array[k]=leftSide[i];
        i++;
        k++; 
    }
    
}

void mergeSort(std::vector<int>&array,int start,int end)
{
    if(start<end)
    {
        int half = start+((end-start)/2); 
        mergeSort(array,start,half);
        mergeSort(array,half+1,end);
        merge(array,start,half,end); 
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
    std::vector<int>myVector={0,1,9,3,7,5,8,2,6,4,10}; 
    printVector(myVector);
    mergeSort(myVector,0,myVector.size()-1);
    printVector(myVector); 
    
    return 0;
}

