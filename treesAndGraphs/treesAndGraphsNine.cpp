/* Implement a recursive traversal in depth in an undirected graph and a program to test it.*/

#include <iostream>
#include <vector>

template<typename T> class Node{
  T* data;
  public:
    Node(T value){data=&value;}
};

template<typename T> class Edge{
  Node<T> *from, *to;
};

template <typename T>
class Graph{

  std::vector<Node<T>*> nodes;
  std::vector<Edge<T>*> edges;
};

