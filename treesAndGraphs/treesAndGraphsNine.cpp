/* Implement a recursive traversal in depth in an undirected graph and a program to test it.*/

#include <iostream>
#include <vector>

template<typename T> class Edge{
  T *from, *to;
};

template <typename T>
class Graph{

  std::vector<T> nodes;
  std::vector<Edge<T>*> edges;
};

