#include <iostream>

/*Write a program which by given N numbers, K and S, finds K elements
out of the N numbers, the sum of which is exactly S or says it is not possible.
Example: {3, 1, 2, 4, 9, 6}, S = 14, K = 3 à yes (1 + 2 + 4 = 14)*/


bool checkSubsetSum(int array[], int itemsCount, int sum)
{
    //Sums decreases each recursive call. It might get to 0 eventually
    if(sum==0)
        return true;
    
    //Neither the items count nor sum can be negative numbers
    if(itemsCount<0||sum<0)
        return false; 

    //Case 1. Include current item and recur for items n-1, with the remaining total
    bool include=checkSubsetSum(array,itemsCount-1,sum-array[itemsCount]); 
     
    std::cout<<counter<<" "; 

    //Case 2. Exclude the current item and recur for the remaining items n-1
    bool exclude=checkSubsetSum(array,itemsCount-1,sum);
     
    return include||exclude; 
}


int main(int argc, char const *argv[])
{   
    //Input
    int array[]={3,1,2,4,9,6};
    int sum=14;
    int itemsCount=sizeof(array);
    int sumCount=3;  

    //Result printer
    if(checkSubsetSum(array,itemsCount,sum))
        std::cout<<"There's a subset of numbers that equal given sum"<<std::endl;
    else
        std::cout<<"There's no subset of numbers that equal given sum"<<std::endl;

    std::cout<<itemsCount<<std::endl; 

    return 0;
}
