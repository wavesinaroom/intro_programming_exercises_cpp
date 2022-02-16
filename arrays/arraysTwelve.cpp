#include <iostream>


/*Write a program, which creates square matrices 
like those in the figures below and prints them formatted to the console. 
The size of the matrices will be read from the console. 
E.g. matrices with size of 4 x 4:

1 5 9  13   1 8 9  16   7 11 14 16   1 12 11 10
2 6 10 14   2 7 10 15   4 8  12 15   2 13 16 9
3 7 11 15   3 6 11 14   2 5  9  13   3 14 15 8
4 8 12 16   4 5 12 13   1 3  6  10   4 5  6  7 */

 
int column, row, sequenceLength, iterationCount;
int matrixSize = 6; 
int digit = 1;  

int main(int argc, char const *argv[])
{
    //2D array init
    int matrix[matrixSize][matrixSize]; 
    

    //Matrix 1
    //Columns
    for (column= 0; column< matrixSize; column++)
    {
        //Rows
        for (row = 0; row < matrixSize; row++)
        {
            matrix[row][column] = digit;
            digit++;  
        }
    }

    //Matrix printer
    //Rows
    for (size_t j = 0; j <matrixSize ; j++)
    {
        //Columns
        for (size_t k= 0; k<matrixSize; k++)
        {
            std::cout<<matrix[j][k]<<" "; 
        }
        std::cout<<std::endl; 
    }

    std::cout<<std::endl; 

    //Matrix 2
    digit = 1; 
    //Columns
    for (column=0; column<matrixSize; column++)
    {
        //Zero or odd columns
        if (column==0||(column%2)==0)
        {
            //Row
            for (row=0; row<matrixSize; row++)
            {
                matrix[row][column] = digit; 
                digit++; 
            }
        }
        //Even columns
        if ((column%2)>0)
        {
            //Row
            for (row=(matrixSize-1); row>=0; row--)
            {
                matrix[row][column] = digit;
                digit++; 
            }
        }
    }

    //Matrix printer
    //Rows
    for (size_t j = 0; j <matrixSize ; j++)
    {
        //Columns
        for (size_t k= 0; k<matrixSize; k++)
        {
            std::cout<<matrix[j][k]<<" "; 
        }
        std::cout<<std::endl; 
    }

    std::cout<<std::endl; 

    //Matrix 3
    digit = 1;
     
    //Left triangle 
    //Outer loop
    for (size_t leftTriangleIterator = 0; leftTriangleIterator < matrixSize; leftTriangleIterator++)
    {
        row = (matrixSize-1)-leftTriangleIterator;
        column = leftTriangleIterator-leftTriangleIterator;
        //Inner loop
        while ((column<matrixSize)&&(row<matrixSize))
        {
            matrix[row][column]=digit;
            digit++;
            row++;
            column++;    
        }
    }

    //Right triangle
    //Outer loop
    for (size_t rightTriangleIterator = 0; rightTriangleIterator < matrixSize-1; rightTriangleIterator++)
    {
        column = rightTriangleIterator+1;
        row = rightTriangleIterator-rightTriangleIterator;
        //Inner loop
        while ((column<matrixSize)&&(row<matrixSize))
        {
            matrix[row][column]=digit;
            digit++;
            row++;
            column++;    
        }
    }

    //Matrix printer
    //Rows
    for (size_t j = 0; j <matrixSize ; j++)
    {
        //Columns
        for (size_t k= 0; k<matrixSize; k++)
        {
            std::cout<<matrix[j][k]<<" "; 
        }
        std::cout<<std::endl; 
    }

    std::cout<<std::endl; 

    //Matrix 4
    digit = 1; 
    if(matrixSize%2==0)
        iterationCount = matrixSize/2;
    else
        iterationCount = (matrixSize/2)+1; 

    for (size_t iteration = 0; iteration < iterationCount; iteration++)
    {
        //Sets values 
        sequenceLength = matrixSize - iteration;
        column = iteration;
        row = iteration; 

        //Goes down
        while (row<sequenceLength)
        {
            matrix[row][column] = digit;
            row++; 
            digit++; 
        }
        
        //Adjusts position
        row--;
        column++;

        //Goes to the right
        while (column<sequenceLength)
        {
            matrix[row][column] = digit;
            column++;
            digit++; 
        }
        
        //Adjusts position
        row--;
        column--; 

        //Goes up
        while (row>(matrixSize-sequenceLength))
        {
            matrix[row][column] = digit;
            row--; 
            digit++; 
        }

        //Goes to the left
        while (column>(matrixSize-sequenceLength))
        {
            matrix[row][column] = digit;
            column--; 
            digit++; 
        }
         
    }
    
        
    
    //Matrix printer
    //Rows
    for (size_t j = 0; j <matrixSize ; j++)
    {
        //Columns
        for (size_t k= 0; k<matrixSize; k++)
        {
            std::cout<<matrix[j][k]<<" "; 
        }
        std::cout<<std::endl; 
    }
    
    return 0;
}



