/* We are given the following sequence:
 * S[1] = N
 * S[2] = S[1] + 1;
 * S[3] = 2*S[1] + 1;
 * S[4] = S[1] + 2;
 * S[5] = S[2] + 1;
 * S[6] = 2*S[2] + 1;
 * S[7] = S[2] + 2;
 * ...
 * Using the Queue<T> class, write a program which by given N prints on the console the first 50 elements of the sequence.
 *
 * Example: N=2 2,3,5,4,4,7,5,6,11,7,5,9,6, ...
 */

#include <iostream>
#include <queue>

void enqueue(int & number, std::queue<int> & queue){
  queue.push(number+1);
  queue.push(2*number+1);
  queue.push(number+2);
  number = queue.front();
}

int main(){

  std::queue<int> queue;
  int number = 2;

  std::cout<<number<<", ";
  for (int i = 0; i<49; ++i) {
    enqueue(number, queue);
    std::cout<<queue.front()<<", ";
    queue.pop();
  }
  std::cout<<'\n';
  return 0;
}
