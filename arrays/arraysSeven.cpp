#include <iostream>
#include <vector>

/*Write a program, which reads from the console two integer numbers N and K (K<N)
 and array of N integers. Find those K consecutive elements in the array,
  which have maximal sum.*/

  int nNumber, kNumber, maxSum, maxSumIndex; 
  int sum = 0;
  
  bool isSequenceOfConsecutives; 
  std::vector <int> nVector; 

  int main(int argc, char const *argv[])
  {
    //Welcome message and input
    std::cout<<"Hi! Please enter N number for array say and K number for sequence length"<<std::endl;
    std::cout<<"WARNING: K number must be less than N"<<std::endl;
    std::cout<<"N number"<<std::endl; 
    std::cin>>nNumber;
    std::cout<<"K number"<<std::endl; 
    std::cin>>kNumber; 

    //N is less than K excepcion 
    if(nNumber<kNumber){
        std::cerr<<"ERROR: K number is greater than N"<<std::endl;
        return 0; 
    }

    //Vector initialization
    nVector.resize(nNumber); 

    //Input vector contents
    std::cout<<"Please enter your values"<<std::endl; 
    
    for (size_t inputPos = 0; inputPos < nNumber; inputPos++)
    {
        std::cin>>nVector.at(inputPos);    
    }
    
    //Finds largest sum and sets max sum index 
    for (size_t nVectorPos = 0; nVectorPos <= (nVector.size()-kNumber); nVectorPos++)
    {
        sum = 0; 
        for (size_t scanner = 1 ; scanner < kNumber; scanner++)
        {
            if(nVector.at(scanner+nVectorPos)==(nVector.at(scanner+nVectorPos-1)+1))
                sum += nVector.at(scanner+nVectorPos);
            else
            {
                sum = 0; 
                break;  
            }
        }
            if(sum>maxSum)
            {
                maxSum = sum;
                maxSumIndex = nVectorPos; 
            }
    }

    //Prints result
    std::cout<<"Your max sum is: "<<maxSum<<std::endl; 
    std::cout<<"Your max sum sequence is: "; 
    for (size_t output = 0; output < kNumber; output++)
    {
        std::cout<<nVector.at(output+maxSumIndex)<<" "; 
    }
    std::cout<<std::endl;     
      return 0;
  }
  