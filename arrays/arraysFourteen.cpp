#include <iostream>

/*Write a program, which finds the longest sequence of equal string elements
in a matrix. A sequence in a matrix we define as a set of neighbor elements
 on the same row, column or diagonal.

 ha  fifi ho hi             s  qq s
 fo  ha   hi xx-------->ha  pp pp s----------> s
 xxx ho   ha xx             pp qq s
*/

int column,row,matrixSize,maxCount,maxCountRow,maxCountColumn;
int count=1;   

int main(int argc, char const *argv[])
{
    matrixSize = 3; 
    std::string matrix[matrixSize][matrixSize]; 

    std::cout<<"Hi! Please enter 9 syllables one after the other "<<std::endl;
    std::cout<<"I'll find that one that appears most in the matrix"<<std::endl; 

    //Generates characters in the matrix
    for (size_t row = 0; row < matrixSize; row++)
    {
        for (size_t column = 0; column < matrixSize; column++)
        {
            std::cin>>matrix[row][column];
        }
    }

    //Prints the matrix 
    for (size_t row = 0; row < matrixSize; row++)
    {
        for (size_t column = 0; column < matrixSize; column++)
        {
            std::cout<<matrix[row][column]<<" ";
        }
        std::cout<<std::endl; 
    }


    //Positions rows
    for (row=0; row<matrixSize; row++)
    {
        //Positions columns
        for (column=0; column<matrixSize; column++)
        {
            //Scans rows - column value stays row value increases GOES DOWN
            while ((matrix[row][column]==matrix[row+1][column])&&row<matrixSize)
            {
                count++; 
                row++;
            }

            //Checks if count is greater than maxCount 
            if(count>maxCount)
            {
                maxCount=count; 
                maxCountColumn=column;
                maxCountRow=row; 
            }
            
            //Scans column - row value stays column value increases GOES TO THE RIGHT
            while ((matrix[row][column]==matrix[row][column+1])&&row<matrixSize)
            {
                count++;
                column++;
            }

            //Checks if count is greater than maxCount
            if(count>maxCount)
            {
                maxCount=count; 
                maxCountColumn=column;
                maxCountRow=row; 
            }

            //Scans rows and columns - row value increases column value increases GOES DIAGONAL
            while ((matrix[row][column]==matrix[row+1][column+1])&&row<matrixSize)
            {
                count++;
                column++;
                row++; 
            }

            //Checks if count is greater than maxCount
            if(count>maxCount)
            {
                maxCount=count; 
                maxCountColumn=column;
                maxCountRow=row; 
            } 
        }
    }

    std::cout<<"Most repetitive word is: "<<matrix[maxCountRow][maxCountColumn]<<" and appears "<<maxCount<<" times"<<std::endl; 
    return 0;
}


 

