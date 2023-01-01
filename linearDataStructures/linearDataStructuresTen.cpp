/* We are given N and M and the following operations:
 *
 * N = N + 1
 * N = N + 2
 * N = N * 2
 *
 * Write a program, which finds the shortest subsequence from the operations, which starts with N and ends with M. Use queue.
 * Example: N = 5, M =16
 * Subsequence: 5 7 8 16
 * */

#include <iostream>
#include <queue>

int main(){
  int N,M;
  std::queue<int> queue;

  std::cout<<"N: "<<'\n';
  std::cin>>N;
  std::cout<<"M: "<<'\n';
  std::cin>>M;

  queue.push(M);
  int number = M;

  if (N>M) {
    std::cerr<<"N can't be greater than M"<<'\n';
    return -1;
  }
  while (number/2>N) {
    if(number%2==1) {
      number -= 1;
      queue.push(number);
    }
    number /= 2;
    queue.push(number);
  }

  while (number>N||(number-N)>=0) {
    number -=2;
    queue.push(number);
    if (number-N==1) {
      break;
    }
  }

  queue.push(N);
  while (!queue.empty()) {
    std::cout<<queue.front()<<'\t';
    queue.pop();
  }

  std::cout<<'\n';
  return 0;
}
