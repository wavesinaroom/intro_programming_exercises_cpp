/* Write a program which removes all negative numbers from a sequence
 *
 * Example: array = {19, -10, 12, -6, -3, 34, -2, 5} {19, 12, 34, 5}
 */

#include <iostream>
#include <list>

int main(){
  std::list<int> list = {19, -10, 12, -6, -3, 34, -2,5};
  std::list<int>::iterator it = list.begin();
  list.remove_if([](int i){return i<0;});

  for (auto & n : list) {
    std::cout<<n<<'\n';
  }
  return 0; 
}
