/* Write a breadth first seach (BFS), based on a queue, to traverse a directed graph.*/

#include <iostream>
#include <vector>
#include <iterator>

template<typename T> class Node{
  private:
    T data;
    std::vector<Node<T>*> edges;
  public:
    Node(T value){data = value;}
    template<typename V> friend class Graph;
    void connectNode(Node<T>* to){
      edges.push_back(to);
    }
};

template<typename V> class Graph{
  private:
    std::vector<Node<V>*> nodes;
  public:
    Graph(){};
    void addNode(V value){
      nodes.push_back(Node<V>(value));
    }
};

int main(){

  return 0;
}
