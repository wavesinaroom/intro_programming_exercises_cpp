/* Implement a recursive traversal in depth in an undirected graph and a program to test it.*/

#include <iostream>
#include <vector>

template<typename T> class Edge{
  T *from, *to;
  public:
    Edge<T>(T &from, T &to){
      this->from = from; this->to = to;
    }
};

template <typename T>
class Graph{

  std::vector<T> nodes;
  std::vector<Edge<T>*> edges;

  public:
    void addNode(T data){nodes.push_back(data);}
    void addEdge(T &from, T &to){
      edges.push_back(Edge<T>(from, to));
      edges.push_back(Edge<T>(to,from));
    }
};

