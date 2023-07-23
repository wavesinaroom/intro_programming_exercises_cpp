/* Implement a recursive traversal in depth in an undirected graph and a program to test it.*/

#include <iostream>
#include <vector>

template<typename T>
class Node{
  private:
    T data;
    std::vector<Node*> edges;
  public:
    template<typename V> friend class Graph;
    Node(T value){
      data = value;
    }
};

template <typename V>
class Graph{
  private:
    std::vector<Node<V>> nodes;
    Node<V>& getNode(V value){
      for (auto & node : nodes) {
        if(node== value) 
          return node;
      }
      return nullptr;
    }
  public:
    Graph();
    void addNode(V data){
      nodes.push_back(Node<V>(data));
    }
    
    void connectNodes(const  V &from, const V &to){
      getNode(from).edges.push_back(getNode(to));
      getNode(to).edges.push_back(getNode(from));
    }
};

int main(){
  Graph<int> graph;
  graph.addNode(0);
  graph.addNode(1);
  return 0;
}
