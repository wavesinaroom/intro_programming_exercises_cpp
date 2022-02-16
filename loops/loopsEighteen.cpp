#include <iostream>

using namespace std;

/*Write a program that for a given number n,
 outputs a matrix in the form of a spiral:

 1  2  3  4
 12 13 14 5
 11 16 15 6
 10 9  8  7
*/

int main(int argc, char const *argv[])
{
    //Welcome message and input
    int n, column, row, iterator;
    int positionShift=0;   
    int digit = 1;
    
    cout<<"Last exercise, gonna be pretty hard "<<endl;
    cout<<"Enter the size of the spiral matrix "<<endl;
    cin>>n;
    //Matrix size N declaration 
    int matrix[n][n]; 
    row = 0;
    column = (sizeof(matrix)/sizeof(matrix[0])-1);

    iterator = n; 

   
    for (size_t i = 0; i < n/2; i++)
    {
        //Matrix numbers input
        //Traverses row from left to right
        for (size_t i = 0; i < iterator; i++)
        {
            matrix[row][i+positionShift] = digit; //i must increase by one
            digit++;
        }
        //Traverses column top bottom
        for (size_t i = 0; i < iterator-1; i++)
        {
            matrix[i+1+positionShift][column] = digit; 
            digit++; 
        }
        //Traverses row right to left 
        for (size_t i = iterator-1; i > 0; i--)
        {
            matrix[column][i-1+positionShift] = digit;
            digit++; 
        }
            
        //Traverses column bottom top
        for (size_t i = iterator-2; i > 0; i--)
        {
            matrix[i+positionShift][row] = digit; 
            digit++; 
        }

        iterator-=2; 
        positionShift++;
        row++;
        column--;
    }


    //Matrix printer
    //Column printing loop
    
    for (size_t column = 0; column < n; column++)
    {
        //Row printing loop
        for (size_t row = 0; row < n; row++)
        {
            cout<<matrix[column][row]<<" ";
        }
        cout<<endl; 
    }

    return 0;
}

