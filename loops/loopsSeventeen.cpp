#include <iostream>

using namespace std;

/*Write a program that given two numbers finds their greatest common divisor (GCD)
 and their least common multiple (LCM). You may use the formula LCM(a, b) = |a*b|
  / GCD(a, b).*/
int a,b,divRemainder; 
int findGCDTwoIntegers(int a, int b);    

int main(int argc, char const *argv[])
{

     //Welcome message and input
    cout<<"Finding LCM and GCD of two number shouldn't be really tricky"<<endl;
    cout<<"what's your first number?"<<endl;
    cin>>a;
    cout<<"What's your second number?"<<endl;
    cin>>b;
     
    cout<<"Your GCD: "<<findGCDTwoIntegers(a,b)<<endl; 
    cout<<"Your LCM: "<<(a*b)/findGCDTwoIntegers(a,b)<<endl; 

      return 0;
  }

//GCD recursive method based on the Euclidian algorithm
int findGCDTwoIntegers(int a, int b)
{
    divRemainder=a%b;
    a=b; 
    b=divRemainder;
    if((a==0)^(b==0))
    {
        if (a==0)
            return b; 
        else if (b==0)
            return a;
        return 1;
    }
    findGCDTwoIntegers(a,b); 
}
  