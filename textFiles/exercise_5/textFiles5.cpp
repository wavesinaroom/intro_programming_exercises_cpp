/* 5. Write a program that reads a square matrix of integers from a
 file and finds the sub-matrix with size 2 × 2 that has the maximal
 sum and writes this sum to a separate text file.The first line
 of input file contains the size of the recorded matrix (N).
 The next N lines contain N integers separated by spaces.

 Sample input file:

 4
 2 3 3 4
 0 2 3 4
 3 7 1 2
 4 3 3 2
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(int argc, char const *argv[]) {

int row, col;

std::fstream file_stream;
file_stream.open("matrix.txt", std::ios::in);

std::string text_line;
std::getline(file_stream, text_line);

const int matrix_size = std::stoi(text_line);
int line_counter = 0;
std::vector<std::vector<int>> matrix (matrix_size, std::vector<int>(matrix_size));
std::vector<int> temporal;

while(std::getline(file_stream, text_line))
{
  for (size_t i = 0; i < text_line.length(); ++i) {
    if (text_line[i]!=' ') {
      temporal.push_back(text_line[i]-'0');
    }
  }

  for (size_t j = 0; j < temporal.size(); j++) {
    matrix[line_counter][j]=temporal[j];
  }
  temporal.clear();
  ++line_counter;
}
file_stream.close();

int max_sum = 0;

for(row = 0; row < matrix_size-1; ++row)
{
  for(col = 0; col < matrix_size-1; ++col)
  {
    if((matrix[row][col]+matrix[row][col+1]+matrix[row+1][col]+matrix[row+1][col+1])>max_sum)
    {
    max_sum = matrix[row][col]+matrix[row][col+1]+matrix[row+1][col]+matrix[row+1][col+1];
    }
  }
}

file_stream.open("result.txt", std::ios::out);
if (file_stream.is_open()) {
  file_stream<<max_sum;
  file_stream.close();
}
  return 0;
}
