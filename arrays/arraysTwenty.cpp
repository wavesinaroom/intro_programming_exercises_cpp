#include <iostream>
#include <array>

/*Write a program, which checks whether there is a subset of given array of N elements,
 which has a sum S. The numbers N, S and the array values are read from the console.
 Same number can be used many times.

Example: {2, 1, 2, 4, 3, 5, 2, 6}, S = 14 à yes (1 + 2 + 5 + 6 = 14)*/

//SOLUTION TAKEN FROM: https://www.techiedelight.com/subset-sum-problem

bool checkSubsetSum(int array[], int itemsCount, int sum)
{
    //Sums decreases each recursive call. It might get to 0 eventually
    if(sum==0)
        return true;
    
    //Neither the items count nor sum can be negative numbers
    if(itemsCount<0||sum<0)
        return false; 

    //Case 1. Include current item and recur for items n-1, with the remaining total
    bool include=checkSubsetSum(array, itemsCount-1, sum-array[itemsCount]); 

    //Case 2. Exclude the current item and recur for the remaining items n-1
    bool exclude=checkSubsetSum(array,itemsCount-1,sum);

    return include||exclude; 
}


int main(int argc, char const *argv[])
{
    //Input
    int array[]={2, 1, 2, 4, 3, 5, 6, 2};
    int sum=14;
    int itemsCount=sizeof(array);

    //Result printer
    if(checkSubsetSum(array, itemsCount, sum))
        std::cout<<"There's a subset of numbers that equals given sum"<<std::endl;
    else
        std::cout<<"There's no subset of numbers that equal given sum"<<std::endl;
        
    return 0;
}

