#include <iostream>

using namespace std;

/*Write a program that calculates N!*K!/(N-K)! for given N and K (1<K<N)*/
    int kNumber;
    int nNumber; 
    int kFactorialArray[0];
    int nFactorialArray[0];

    void inputFactorialDigitsArray(int number, int factorialArray[]);
    long findFactorial(int number, int factorialArray[]); 
    void cancelsDigitsFactorialsDivision(int differenceBetweenNandK, int factorialArray[]); 
    void logArrayContents(int number, int factorialArray[]); 

int main(int argc, char const *argv[])
{

    //Welcome message
    cout<<"We're gonna divide factorials, please input a K number greater than one "<<endl;
    cin>>kNumber; 
    cout<<"and a N number greater than K"<<endl;
    cin>>nNumber;

    //Input
    if (kNumber<1||kNumber>nNumber)
        cerr<<"Wrong numbers, they can break the program"<<endl;      

    
    inputFactorialDigitsArray(nNumber,nFactorialArray);
    cancelsDigitsFactorialsDivision((nNumber-kNumber), nFactorialArray);
    
    //inputFactorialDigitsArray(kNumber,kFactorialArray); 
    
    logArrayContents(nNumber, nFactorialArray);     
    //logArrayContents(kNumber,kFactorialArray); 

    findFactorial(nNumber, nFactorialArray);
    findFactorial(kNumber,kFactorialArray); 

    cout<<findFactorial(nNumber,nFactorialArray)<<endl; 
    cout<<findFactorial(kNumber,kFactorialArray)<<endl; 
    
    return 0;
}

//Prints array contents to debug
void logArrayContents(int number,int factorialArray[])
{
    for (size_t i = 0; i < number ; i++)
    {
        cout<<"************LogFactorial*******"<<factorialArray[i]<<endl; 
    }
}

//Inputs factorials in a array
void inputFactorialDigitsArray(int number, int factorialArray[])
{
    for (size_t i = 0; i < number; i++)
    {
        factorialArray[i] = i+1; 
    }
}

//Makes digits equal 1 for largest factorial (same as cancelling numerator and divisor)
void cancelsDigitsFactorialsDivision(int differenceBetweenNandK, int factorialArray[])
{
    for (size_t i = (differenceBetweenNandK-1); i > 0; i--)
    {
        factorialArray[i] = 1; 
    }
}


//Finds factorial of a number
long findFactorial(int number, int factorialArray[])
{
    int result = factorialArray[number];
    for (size_t i = number; i > 1; i--)
    {
        result *= factorialArray[i-1];
    }
    return result; 
}        
    


