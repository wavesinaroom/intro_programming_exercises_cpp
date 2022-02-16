#include <iostream>
#include <math.h>

/*Write a program, which creates a rectangular array with size of n by m elements. 
The dimensions and the elements should be read from the console. Find a platform 
with size of (3, 3) with a maximal sum.*/

int columnSize,rowSize,randNumber,startingPos,row,column,columnResult,rowResult;
const int PLATFORM_SIZE = 3; 
int sum = 0;
int maxSum = 0;

int main(int argc, char const *argv[])
{
   //Welcome message and input
    std::cout<<"Hey! Long time no see. Let's find max sum in 3 x 3 platform"<<std::endl;
    std::cout<<"Please enter a N number greater than 3"<<std::endl;
    std::cin>>rowSize;
    std::cout<<"Please enter a M number greater than 3"<<std::endl;
    std::cin>>columnSize;

    //Checks if numbers are valid
    if (rowSize<3||columnSize<3)
    {
        std::cout<<"Sorry, your digits aren't right"<<std::endl;
        return 0; 
    }
    
    //Initializes the matrix
    int matrix[rowSize][columnSize];

    //Inputs randomized values between 1 and 10
    for (size_t columnInit = 0; columnInit < columnSize ; columnInit++)
    {
        for (size_t rowInit = 0; rowInit < rowSize; rowInit++)
        {
            matrix[rowInit][columnInit] = rand() % 10 +1;
        }
    }

    std::cout<<std::endl; 

    //Matrix printer
    //Rows
    for (size_t j=0; j<rowSize; j++)
    {
        //Columns
        for (size_t k=0; k<columnSize; k++)
        {
            std::cout<<matrix[j][k]<<" "; 
        }
        std::cout<<std::endl; 
    }

    std::cout<<std::endl; 

    
    //3x3 Platform maxSum search
    //Iterates through rows
    for (size_t row=0; row<=(rowSize-PLATFORM_SIZE); row++)
    {
        //Resets sum
        sum = 0;
        //Iterates through columns
        for (size_t column=0; column<=(columnSize-PLATFORM_SIZE); column++)
        {
            sum = matrix[row][column]+matrix[row][column+1]+matrix[row][column+2]+
            matrix[row+1][column]+matrix[row+1][column+1]+matrix[row+1][column+2]+
            matrix[row+2][column]+matrix[row+2][column+1]+matrix[row+2][column+2];
            std::cout<<"Row: "<<row<<" "<<"Column: "<<column<<std::endl;  
            std::cout<<"Sum: "<<sum<<std::endl;  
            
            //Checks maxSum, resets sum and stores maxSum column and row
            if (sum>maxSum)
            {
                maxSum = sum;
                rowResult = row;
                columnResult = column; 
            }
        }

    }
    
    std::cout<<std::endl; 
    
    //Logs results
    std::cout<<"***************Max sum: "<<maxSum<<std::endl; 
    std::cout<<"***************Result row: "<<rowResult<<std::endl; 
    std::cout<<"***************Result column: "<<columnResult<<std::endl; 
    
    std::cout<<std::endl; 

    //Prints result platform
    //Rows
    for (size_t printRow=rowResult; printRow<(PLATFORM_SIZE+rowResult); printRow++)
    {
        //Columns
        for (size_t printColumn=columnResult; printColumn<(PLATFORM_SIZE+columnResult); printColumn++)
        {
            std::cout<<matrix[printRow][printColumn]<<" "; 
        }
        std::cout<<std::endl; 
    }
    
    

    return 0;
}
