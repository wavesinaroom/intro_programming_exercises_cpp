#include <iostream>
#include <math.h>

using namespace std;

/*Write a program that calculates with how many zeroes the factorial of a given number ends. 
Examples:
N = 10 -> N! = 3628800 -> 2

      N = 20 -> N! = 2432902008176640000 -> 4 */

unsigned int n;
unsigned int zeroCount; 

int moduloSize=1; 
int nFactorial=1;
int modulo; 


bool isDigitZero=true; 

void findRecursiveFactorial(int n);

int main(int argc, char const *argv[])
{

    //pow() in C++ seems to work with int only. Program breaks when factorial
    //gets huge
    cout<<"Find number of zeros in a factorial"<<endl;
    cout<<"Enter your N number: "<<endl;
    cin>>n;

    findRecursiveFactorial(n);
    cout<<"**********Factorial: "<<nFactorial<<endl;

    while (isDigitZero)
    {
        modulo = pow(10,moduloSize);
        if (nFactorial%(modulo)==0)
        {
           zeroCount++;
           moduloSize++;  
        }else{
            isDigitZero = false; 
        }
        
    }
    
    cout<<"----------Number of zeros: "<<zeroCount<<endl;

    return 0;
}

void findRecursiveFactorial(int n){
    nFactorial*=n; 
    n--;
    if(n<=0)
        return; 
    findRecursiveFactorial(n); 
}


