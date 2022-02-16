#include <iostream>

using namespace std;

/*We are given 5 integer numbers. Write a prigram that find those subsets 
which sum is 0. Examples:
    -If we are given the numbers {3,-2,1,1,8}, the sum of -2,1 and 1 is 0
    -if we are given the numbers {3,1,-7,35,22} there are not subsets with sum 0
*/


/////////////////COULDN'T CRACK IT DOWN, GOOD TRY THOUGH. BOOK SOLUTION IS NOT GOOD///
    int arraySize;  
    int numbersSet[5];
    int startingSum;
    int numberOfDigits=1; 
    void findStartingSum(int _numberOfDigits); 
    void comparePossibleSets(); 



int main(int argc, char const *argv[])
{

    cout<<"Is there any sum = 0 in the set?"<<endl;
    /*cout<<"Please enter the size of your array"<<endl;
    cin>>arraySize; 
    numbersSet[arraySize];*/ 
    cout<<"Please enter your digits"<<endl; 
    
    arraySize = sizeof(numbersSet)/sizeof(numbersSet[0]); 
    for (size_t i = 0; i < arraySize ; i++)
    {
        cin>>numbersSet[i];
    }
    comparePossibleSets(); 
    return 0;
}
    //Scans possible sums within the set
    void comparePossibleSets()
    {
        findStartingSum(numberOfDigits); 
        int iterationNumber = arraySize-numberOfDigits; 
        cout<<"/////Iteration Number in set////////:"<<iterationNumber<<endl; 
        for (int i = 0; i < iterationNumber; i++)
        {
            //Check this line
            if((startingSum + numbersSet[numberOfDigits+i])==0)
            cout<<"--is set?-- "<<"Set"<<endl; 
        }
        numberOfDigits++; 
        cout<<"-------Number of digits sum------: "<<numberOfDigits<<endl; 
        if(numberOfDigits==arraySize)
            return; 
        comparePossibleSets();
    }
    //Sum to compare method
    void findStartingSum(int _numberOfDigits)
    {
        startingSum = 0; 
        int i = 0; 
        do
        {
            startingSum+=numbersSet[i];
            i++; 
        } while (i<(_numberOfDigits+1));
        cout<<"******Starting sum*******: "<<startingSum<<endl; 
    }  